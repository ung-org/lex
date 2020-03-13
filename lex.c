#define _XOPEN_SOURCE 700

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAYBEADDLINE(buf, lineno, filename) do { if (needline) { \
	char ppline[LINE_MAX] = {0}; \
	sprintf(ppline, "#line %d \"%s\"\n", lineno, filename); \
	buf = append(buf, ppline); \
	needline = 0; \
	} } while (0)

#define RESETLINE(buf) do { \
	needline = 1; \
	buf = append(buf, "%%\n"); \
	} while (0)

#define OUTPUTFILENAME "lex.yy.c"

#define MIN_POSITIONS	2500
#define MIN_STATES	500
#define MIN_TRANSITIONS	2000
#define MIN_NODES	1000
#define MIN_CLASSES	1000
#define MIN_OUTPUTSIZE	3000

struct definition {
	char *name;
	char *substitute;
};

struct parser {
	enum { UNSPECIFIED, POINTER, ARRAY } yytexttype;
	int maxpositions;
	int maxstates;
	int maxtransitions;
	int maxnodes;
	int maxclasses;
	int maxoutput;

	int npositions;
	int nstates;
	int ntransitions;
	int nnodes;
	int nclasses;
	int outputsize;

	char *states;
	char *top;
	char *init;
	char *bottom;

	size_t ndefs;
	char *defs;
};

char *append(char *buf, const char *add)
{
	if (buf == NULL) {
		return strdup(add);
	}

	size_t oldlen = buf ? strlen(buf) : 0;
	size_t newlen = strlen(add);
	char *tmp = realloc(buf, oldlen + newlen);
	if (tmp == NULL) {
		perror("lex");
		exit(EXIT_FAILURE);
	}
	buf = tmp;
	memcpy(buf + oldlen, add, newlen);
	return buf;
}

static int add_directive(struct parser *p, const char *buf)
{
	if (!strcmp(buf, "%array\n")) {
		p->yytexttype = ARRAY;
		return 1;
	}

	if (!strcmp(buf, "%pointer\n")) {
		p->yytexttype = POINTER;
		return 1;
	}

	switch (buf[1]) {
	case 'p':
		p->npositions = atoi(buf + 2);
		break;

	case 'n':
		p->nstates = atoi(buf + 2);
		break;

	case 'a':
		p->ntransitions = atoi(buf + 2);
		break;

	case 'e':
		p->nnodes = atoi(buf + 2);
		break;

	case 'k':
		p->nclasses = atoi(buf + 2);
		break;

	case 'o':
		p->outputsize = atoi(buf + 2);
		break;

	case 'x':
	case 'X':
		/* exclusive start condition */
		break;

	case 's':
	case 'S':
		/* start condition */
		break;

	default:
		return 0;
	}

	return 1;
}

static int add_definition(struct parser *p, const char *buf)
{
	(void)p; (void)buf;
	return 1;
}

struct parser *parse(struct parser *parser, const char *file)
{
	struct parser p = {0};
	FILE *input = stdin;
	char *buf = NULL;
	int line = 0;
	size_t n = 0;
	ssize_t len = 0;
	int needline = 1;
	enum { DEFINITIONS, RULES, SUBROUTINES } section = DEFINITIONS;

	if (strcmp("-", file)) {
		if ((input = fopen(file, "r")) == NULL) {
			fprintf(stderr, "Couldn't open %s: %s\n", file,
				strerror(errno));
			return parser;
		}
	}

	while (!feof(input)) {
		len = getline(&buf, &n, input);
		if (len == -1) {
			if (errno == 0) {
				buf = NULL;
				n = 0;
				continue;
			}
			perror("lex");
			exit(EXIT_FAILURE);
		}
		line++;

		if (section == DEFINITIONS) {
			if (!strcmp("%%\n", buf)) {
				section = RULES;
			} else if (!strcmp("%{\n", buf)) {
				MAYBEADDLINE(p.top, line, file);
				while ((len = getline(&buf, &n, input)) != -1
					&& strcmp("%}\n", buf))
				{
					line++;
					p.top = append(p.top, buf);
				}
				line++;
				RESETLINE(p.top);
			} else if (isblank(buf[0])) {
				MAYBEADDLINE(p.top, line, file);
			} else if (buf[0] == '%') {
				if (!add_directive(&p, buf)) {
					fprintf(stderr, "lex: %s:%d: unknown directive %s", file, line, buf);
					return NULL;
				}
			} else {
				add_definition(&p, buf);
			}
		} else if (section == RULES) {
			if (!strcmp("%%\n", buf)) {
				section = SUBROUTINES;
			}
		} else if (section == SUBROUTINES) {
			if (!strcmp("%%\n", buf)) {
				fprintf(stderr, "%s:%d:Unexpected %%%% "
					"after processing user subroutines\n",
					file, line);
				free(buf);
				free(p.top);
				free(p.init);
				free(p.bottom);
				return parser;
			}
			MAYBEADDLINE(p.bottom, line, file);
			p.bottom = append(p.bottom, buf);
		}
	}

	if (input != stdin) {
		fclose(input);
	}

	if (section == DEFINITIONS) {
		fprintf(stderr, "%s:%d reach EOF without rules section\n", file, line);
		return parser;
	}

	/* merge successful stuff */
	if (parser == NULL) {
		parser = calloc(1, sizeof(*parser));
	}

	if (p.top) {
		parser->top = append(parser->top, p.top);
		free(p.top);
	}

	if (p.init) {
		parser->init = append(parser->init, p.init);
		free(p.init);
	}

	if (p.bottom) {
		parser->bottom = append(parser->bottom, p.bottom);
		free(p.bottom);
	}

	return parser;
}

int output(struct parser *p, FILE *f)
{
	/* write the data */
	if (p->top) {
		fprintf(f, "%s\n", p->top);
	}

	fprintf(f, "#include <stdio.h>\n");
	fprintf(f, "\n");

	fprintf(f, "static struct {\n");
	fprintf(f, "\tconst struct {\n");
	fprintf(f, "\t\tint INITIAL;\n");
	for (int i = 0; i < p->nstates; i++) {
		fprintf(f, "\t\tint %s;\n", p->states[i]);
	}
	fprintf(f, "\t} state;\n");
	fprintf(f, "\tint condition;\n");
	fprintf(f, "} YY = {\n");
	fprintf(f, "\t{ 0, ");
	for (int i = 0; i < p->nstates; i++) {
		fprintf(f, "%d, ", i + 1);
	}
	fprintf(f, "},\n");
	fprintf(f, "};\n");
	fprintf(f, "\n");

	fprintf(f, "#define ECHO fputs(yytext, yyout)\n");
	fprintf(f, "#define REJECT /* something complex */\n");
	fprintf(f, "#define BEGIN YY.condition = YY.state.\n");
	fprintf(f, "\n");

	if (p->yytexttype == ARRAY) {
		fprintf(f, "char yytext[YYARRAYSIZE];\n");
	} else {
		fprintf(f, "char *yytext = NULL;\n");
	}
	fprintf(f, "int yyleng = 0;\n");
	fprintf(f, "FILE *yyin = NULL;\n");
	fprintf(f, "FILE *yyout = NULL;\n");
	fprintf(f, "\n");

	/* int yymore(void) */
	/* int yyless(int n) */
	/* int input(void) */
	/* int unput(int c) */

	fprintf(f, "int yylex(void)\n{\n");
	if (p->init) {
		fputs(p->init, f);
	}
	/* generated code */
	fprintf(f, "}\n");

	if (p->bottom) {
		fputs(p->bottom, f);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	struct parser *parser = NULL;
	FILE *outfile = NULL;
	int verbose = 0;
	int c;

	while ((c = getopt(argc, argv, "tnv")) != -1) {
		switch (c) {
		case 't':
			/* Output to stdout */
			outfile = stdout;
			break;

		case 'n':	/* MUTEX: v */
			/* Suppress statistics summary */
			verbose = -1;
			break;

		case 'v':	/* MUTEX: n */
			/* Show statistics summary */
			verbose = 1;
			break;
			
		default:
			return 1;
		}
	}

	if (outfile == NULL) {
		if ((outfile = fopen(OUTPUTFILENAME, "w")) == NULL) {
			perror("lex: Couldn't open output file");
			return 1;
		}
	}

	if (optind >= argc) {
		parser = parse(parser, "-");
	} else {
		while (optind < argc) {
			parser = parse(parser, argv[optind++]);
		}
	}

	if (parser) {
		output(parser, outfile);
		/* if (verbose == 1 || (verbose == 0 && parser->tables_are_set) { */
		/* output_statistics(parser); */
		/* } */
	}

	if (outfile != stdout) {
		fclose(outfile);
	}

	return 0;
}
