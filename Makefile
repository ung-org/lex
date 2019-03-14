.POSIX:

CFLAGS=-D_XOPEN_SOURCE=700 -g

all: l

l: lex-ere.l lex-ere.y
	yacc -b lex-ere -d lex-ere.y
	lex -t lex-ere.l > lex-ere.yy.c
	cc -o $@ lex-ere.yy.c lex-ere.tab.c -ll -ly

lex: lex.c

libl.a: libl.a(libl.o)

clean:
	rm -f lex *.o *.a lex.yy.c
