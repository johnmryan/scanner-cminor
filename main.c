#include <stdio.h>
#include <string.h>
#include "token.h"

extern FILE* yyin;
extern char* yytext;
extern int yylex(void);

char* removeQuotes(char* s);
char temp[256];

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
		//if a string literal, print val and continue through loop
		if (t == TOKEN_STRING_LITERAL) {
			printf("%s %s\n", token_string(t), removeQuotes(yytext));
			continue;
		}
		if (!t) break;
		printf("%s\n",token_string(t));
		//printf("%s\n", yytext);
	}
}

char* removeQuotes(char* s) {
  int i = 1;
  for (i; i < strlen(s)-1; i++) {
  	temp[i-1] = s[i];
  }
  temp[strlen(temp)-1] = '\0';
 	return temp;
}
