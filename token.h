#ifndef TOKEN_H
#define TOKEN_H

enum token {
	TOKEN_IDENT = 1,
	TOKEN_WHILE,
	TOKEN_THEN,
	TOKEN_STRING,
	TOKEN_CHAR_LITERAL,
	TOKEN_STRING_LITERAL,
	SEMICOLON,
	ERROR
};
typedef enum token token_t;
const char* token_string(token_t t);

#endif
