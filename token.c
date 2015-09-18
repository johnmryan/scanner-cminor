#include "token.h"

const char* token_string(token_t t) {
	switch(t) {
		case TOKEN_COMMA: return "COMMA";
		case TOKEN_CHAR_LITERAL: return "CHARACTER_LITERAL";
		case TOKEN_STRING_LITERAL: return "STRING_LITERAL";
		case TOKEN_L_BRACE: return "LEFT_BRACE";
		case TOKEN_R_BRACE: return "RIGHT_BRACE";
		case TOKEN_INT_LITERAL: return "INTEGER_LITERAL";
		case TOKEN_R_PAREN: return "R_PAREN";
		case TOKEN_L_PAREN: return "L_PAREN";
		case TOKEN_R_BRACKET: return "R_BRACKET";
		case TOKEN_L_BRACKET: return "L_BRACKET";
		case TOKEN_COLON: return "COLON";
		case TOKEN_IDENT: return "IDENTIFIER";
		case TOKEN_EXP: return "EXPONENT";
		case TOKEN_AND: return "AND";
		case TOKEN_OR: return "OR";
		case TOKEN_ADD: return "ADD";
		case TOKEN_MINUS: return "MINUS";
		case TOKEN_INCREMENT: return "INCREMENT";
		case TOKEN_DECREMENT: return "DECREMENT";
		case TOKEN_MODULUS: return "MODULUS";
		case TOKEN_DIVISION: return "DIVISION";
		case TOKEN_MULT: return "MULT";
		case TOKEN_ASSIGN: return "ASSIGN";
		case TOKEN_LT: return "LT";
		case TOKEN_GT: return "GT";
		case TOKEN_NE: return "NE";
		case TOKEN_EQUAL: return "EQUAL";
		case TOKEN_GE: return "GE";
		case TOKEN_LE: return "LE";
		case TOKEN_WHILE: return "WHILE";
		case TOKEN_ARRAY: return "ARRAY";
		case TOKEN_ELSE: return "ELSE";
		case TOKEN_FALSE: return "FALSE";
		case TOKEN_FOR: return "FOR";
		case TOKEN_FUNCTION: return "FUNCTION";
		case TOKEN_IF: return "IF";
		case TOKEN_INTEGER: return "INTEGER";
		case TOKEN_PRINT: return "PRINT";
		case TOKEN_RETURN: return "RETURN";
		case TOKEN_TRUE: return "TRUE";
		case TOKEN_VOID: return "VOID";
		case TOKEN_BOOLEAN: return "BOOLEAN";
		case TOKEN_CHAR: return "CHAR";
		case TOKEN_STRING: return "STRING";
		case TOKEN_SEMICOLON: return "SEMICOLON";
		case TOKEN_COMMENT: return "COMMENT";
		case ERROR: return "scan error: ";
	}
}
