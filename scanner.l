%{
	#include "token.h"
%}

%option noyywrap
	
NUMBER=[0-9]
LETTER=[A-Za-z]

%%

[ \n\t\r]
\^ { return TOKEN_EXP; }
&& { return TOKEN_AND; }
\|\| { return TOKEN_OR; }
\+ { return TOKEN_ADD; }
- { return TOKEN_SUBTRACT; }
\+\+ { return TOKEN_INCREMENT; }
-- { return TOKEN_DECREMENT; }
% { return TOKEN_MODULUS; }
\/ { return TOKEN_DIVISION; }
\* { return TOKEN_MULT; }
= { return TOKEN_ASSIGN; }
\< { return TOKEN_LT; }
\> { return TOKEN_GT; }
\!= { return TOKEN_NE; }
== { return TOKEN_EQUAL; }
\>= { return TOKEN_GE; }
\<= { return TOKEN_LE; }
array { return TOKEN_ARRAY; }
else { return TOKEN_ELSE; }
false { return TOKEN_FALSE; }
for { return TOKEN_FOR; }
function { return TOKEN_FUNCTION; }
if { return TOKEN_IF; }
integer { return TOKEN_INTEGER; }
print { return TOKEN_PRINT; }
return { return TOKEN_RETURN; }
true { return TOKEN_TRUE; }
void { return TOKEN_VOID; }
boolean { return TOKEN_BOOLEAN; }
while { return TOKEN_WHILE; }
char { return TOKEN_CHAR; }
string { return TOKEN_STRING; }
; { return TOKEN_SEMICOLON; }
(\/\*([^\*]|[\r\n]|(\*+([^\*\/]|[\r\n])))*\*+\/)|(\/\/.*) { return TOKEN_COMMENT; }
. { return ERROR; }

%%
