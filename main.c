#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

extern FILE* yyin;
extern char* yytext;
extern int yylex(void);

char* removeQuotes(char* s);
char temp[512];

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
		if (t == TOKEN_STRING_LITERAL || t == TOKEN_CHAR_LITERAL) {
			printf("%s %s\n", token_string(t), removeQuotes(yytext));
			continue;
		}
		if (t == ERROR) {
			fprintf(stderr,"%s%s is not valid.\n", token_string(t), yytext);
			exit(1);
		}	
		if (!t) break;
		printf("%s\n",token_string(t));
		//printf("%s\n", yytext);
	}
}

char* removeQuotes(char* s) {
  int i = 1;
	int num_combinations = 0;
  for (i; i < strlen(s)-1; i++) {
		if (s[i] == '\\') {
			if (s[i+1] == 'n') {
				temp[i-1-num_combinations] = '\n';
				num_combinations++;
				i++;
				continue;
			}
			else if (s[i+1] == '0') {
				temp[i-1-num_combinations] = '\0';
				num_combinations++;
				i++;
				continue;
			}
			//backwhack and any other character
			else {
				temp[i-1-num_combinations] = s[i+1];
				num_combinations++;
				i++;
				continue;
			}
		}
  	temp[i-1-num_combinations] = s[i];
		if (i > 255) {
			fprintf(stderr,"scan error: string too large\n");
			exit(1);
		}
  }
  temp[i-1-num_combinations] = '\0';
 	return temp;
}
