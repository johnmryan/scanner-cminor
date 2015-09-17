%{
	#include "token.h"
%}

%option noyywrap
	
NUMBER=[0-9]
LETTER=[A-Za-z]

%%

[ \n\t]
while { return TOKEN_WHILE; }
then { return TOKEN_THEN; }
. { return ERROR; }

%%
