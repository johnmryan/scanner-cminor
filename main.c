#include <stdio.h>
#include "token.h"

extern FILE* yyin;
extern char* yytext;
extern int yylex(void);

int main(int argc, char **argv) {
	//enough arguments
	if (argc > 1)
		yyin = fopen( argv[2], "r");
	else {
		printf("Please provide the correct number of arguments.\n");
		return 0;
	}
	//while 1 for main
	token_t t;
	while (1) {
		t = yylex();
		if (t == TOKEN_STRING_LITERAL) {
			printf("%s %s\n", token_string(t), yytext);
			continue;
		}
		if (!t) break;
		printf("%s\n",token_string(t));
		//printf("%s\n", yytext);
	}
}
	
