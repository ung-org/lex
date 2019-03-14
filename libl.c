extern int yylex(void);

int yywrap(void)
{
	return 1;
}

int main(int argc, char *argv[])
{
	yylex();
	return 0;
}
