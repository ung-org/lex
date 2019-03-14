#include <stdlib.h>
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
#define YYPREFIX "yy"
#define ORD_CHAR 257
#define QUOTED_CHAR 258
#define DUP_COUNT 259
#define COLL_ELEM_SINGLE 260
#define COLL_ELEM_MULTI 261
#define META_CHAR 262
#define Open_equal 263
#define Equal_close 264
#define Open_dot 265
#define Dot_close 266
#define Open_colon 267
#define Colon_close 268
#define class_name 269
#define YYERRCODE 256
const short yylhs[] =
	{                                        -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    3,
    3,    3,    3,    4,    4,    4,    4,    4,    4,    5,
    5,    6,    7,    8,    8,    9,    9,   10,   10,   11,
   11,   11,   12,   12,   16,   13,   13,   17,   17,   17,
   15,   15,   14,
};
const short yylen[] =
	{                                         2,
    1,    3,    1,    2,    1,    1,    1,    3,    2,    1,
    1,    1,    1,    1,    1,    1,    3,    4,    5,    3,
    3,    1,    2,    1,    2,    1,    2,    1,    1,    1,
    1,    1,    2,    2,    2,    1,    1,    3,    3,    3,
    3,    3,    3,
};
const short yydefred[] =
	{                                      0,
   10,   11,    6,    7,    0,   12,    0,    0,    0,    0,
    5,   13,    0,   36,    0,    0,    0,    0,    0,    0,
   22,    0,   26,   28,   29,    0,   31,   32,    0,   37,
    0,    0,   14,   15,   16,    0,    9,    8,    0,    0,
    0,    0,    0,    0,   23,   20,   21,   25,   27,   35,
   34,   33,    0,    0,   41,   42,   38,   39,   40,   43,
   17,    0,    0,   18,   19,
};
const short yydgoto[] =
	{                                       8,
    9,   10,   11,   37,   12,   19,   20,   21,   22,   23,
   24,   25,   26,   27,   28,   29,   30,
};
const short yysindex[] =
	{                                    -36,
    0,    0,    0,    0,  -36,    0,  -85, -104,  -36,  -27,
    0,    0,  -33,    0, -235, -238, -242, -246,  -65,  -64,
    0,  -40,    0,    0,    0,  -15,    0,    0,  -34,    0,
  -36,  -27,    0,    0,    0, -228,    0,    0, -232, -231,
 -226, -221, -220, -234,    0,    0,    0,    0,    0,    0,
    0,    0,  -36,  -26,    0,    0,    0,    0,    0,    0,
    0, -119,  -90,    0,    0,};
const short yyrindex[] =
	{                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -55,    0,    0,    0,  -91,    0,    0,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   12,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,};
const short yygindex[] =
	{                                     45,
   20,    4,    0,    0,    0,    0,    0,   34,    0,   32,
    0,    0,   27,    0,    0,    0,    0,
};
#define YYTABLESIZE 261
const short yytable[] =
	{                                       4,
    3,   30,    4,    5,   48,   64,    1,   38,   18,    6,
   51,    2,   32,   14,   33,   34,   15,   62,   16,   31,
   17,   41,   42,   43,   39,   40,   44,   46,   47,   50,
   54,   55,   56,   60,   65,   35,    3,   24,    4,   57,
    3,    3,    4,    4,   58,   59,    3,    1,    4,   13,
   53,   45,    2,   49,    7,   52,   32,    3,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    3,    0,    4,    3,   36,    4,    0,   61,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    3,    0,    4,    0,    0,    0,
    1,    0,    0,    0,    0,    2,    0,    0,    0,   63,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   30,    0,
    0,   30,    0,   30,   14,   30,    0,   15,    0,   16,
    0,   17,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    1,    2,   15,    0,   16,   14,   17,    0,    0,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,    3,    4,
    4,
};
const short yycheck[] =
	{                                      36,
    0,   93,    0,   40,   45,  125,    0,   41,   94,   46,
   45,    0,    9,  260,   42,   43,  263,   44,  265,  124,
  267,  260,  261,  262,  260,  261,  269,   93,   93,   45,
  259,  264,  264,  268,  125,   63,   36,   93,   36,  266,
   40,   41,   40,   41,  266,  266,   46,   41,   46,    5,
   31,   18,   41,   22,   91,   29,   53,   94,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   91,   -1,   91,   94,  123,   94,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,  124,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,   -1,
   -1,  263,   -1,  265,  260,  267,   -1,  263,   -1,  265,
   -1,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,
  257,  258,  263,   -1,  265,  260,  267,   -1,   -1,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  257,
  258,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#if YYDEBUG
const char * const yyname[] =
	{
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'$'",0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,
"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'",
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ORD_CHAR","QUOTED_CHAR","DUP_COUNT",
"COLL_ELEM_SINGLE","COLL_ELEM_MULTI","META_CHAR","Open_equal","Equal_close",
"Open_dot","Dot_close","Open_colon","Colon_close","class_name",
};
const char * const yyrule[] =
	{"$accept : extended_reg_exp",
"extended_reg_exp : ERE_branch",
"extended_reg_exp : extended_reg_exp '|' ERE_branch",
"ERE_branch : ERE_expression",
"ERE_branch : ERE_branch ERE_expression",
"ERE_expression : one_char_or_coll_elem_ERE",
"ERE_expression : '^'",
"ERE_expression : '$'",
"ERE_expression : '(' extended_reg_exp ')'",
"ERE_expression : ERE_expression ERE_dupl_symbol",
"one_char_or_coll_elem_ERE : ORD_CHAR",
"one_char_or_coll_elem_ERE : QUOTED_CHAR",
"one_char_or_coll_elem_ERE : '.'",
"one_char_or_coll_elem_ERE : bracket_expression",
"ERE_dupl_symbol : '*'",
"ERE_dupl_symbol : '+'",
"ERE_dupl_symbol : '?'",
"ERE_dupl_symbol : '{' DUP_COUNT '}'",
"ERE_dupl_symbol : '{' DUP_COUNT ',' '}'",
"ERE_dupl_symbol : '{' DUP_COUNT ',' DUP_COUNT '}'",
"bracket_expression : '[' matching_list ']'",
"bracket_expression : '[' nonmatching_list ']'",
"matching_list : bracket_list",
"nonmatching_list : '^' bracket_list",
"bracket_list : follow_list",
"bracket_list : follow_list '-'",
"follow_list : expression_term",
"follow_list : follow_list expression_term",
"expression_term : single_expression",
"expression_term : range_expression",
"single_expression : end_range",
"single_expression : character_class",
"single_expression : equivalence_class",
"range_expression : start_range end_range",
"range_expression : start_range '-'",
"start_range : end_range '-'",
"end_range : COLL_ELEM_SINGLE",
"end_range : collating_symbol",
"collating_symbol : Open_dot COLL_ELEM_SINGLE Dot_close",
"collating_symbol : Open_dot COLL_ELEM_MULTI Dot_close",
"collating_symbol : Open_dot META_CHAR Dot_close",
"equivalence_class : Open_equal COLL_ELEM_SINGLE Equal_close",
"equivalence_class : Open_equal COLL_ELEM_MULTI Equal_close",
"character_class : Open_colon class_name Colon_close",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
/* LINTUSED */
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
unsigned int yystacksize;
int yyparse(void);
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    unsigned int newsize;
    long sslen;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    sslen = yyssp - yyss;
#ifdef SIZE_MAX
#define YY_SIZE_MAX SIZE_MAX
#else
#define YY_SIZE_MAX 0xffffffffU
#endif
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newss)
        goto bail;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss); /* overflow check above */
    if (newss == NULL)
        goto bail;
    yyss = newss;
    yyssp = newss + sslen;
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newvs)
        goto bail;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs); /* overflow check above */
    if (newvs == NULL)
        goto bail;
    yyvs = newvs;
    yyvsp = newvs + sslen;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
bail:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return -1;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif /* YYDEBUG */

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (1);
yyaccept:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (0);
}
