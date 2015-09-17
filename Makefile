CC=gcc
LEX=flex

all: cminor

cminor: main.o token.o lex.yy.c
	$(CC) main.o token.o lex.yy.c -o cminor

lex.yy.c: scanner.l
	$(LEX) scanner.l

main.o: main.c token.o
	$(CC) -c main.c

token.o: token.c token.h
	$(CC) -c token.c

clean:
	rm *.o lex.yy.c cminor
