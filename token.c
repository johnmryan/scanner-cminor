#include "token.h"

const char* token_string(token_t t) {
	switch(t) {
		case ERROR: return "error";
		case TOKEN_WHILE: return "while";
		case TOKEN_IDENT: return "identifier";
		case TOKEN_STRING: return "string";
		default: return "default case";
	}
}
