%{
	#include "token.h"
%}

%option noyywrap
	
NUMBER [0-9]
LETTER [A-Za-z]
L_BRACKET \[
R_BRACKET \]
L_PAREN \(
R_PAREN \)
L_BRACE \{
R_BRACE \}

%%

[ \n\t\r]
(\/\*([^\*]|[\r\n]|(\*+([^\*\/]|[\r\n])))*\*+\/)|(\/\/.*)
, { return TOKEN_COMMA; }
\'{LETTER}\' { return TOKEN_CHAR_LITERAL; }
\"(\\.|[^\"])*\" { return TOKEN_STRING_LITERAL; }
{L_BRACE} { return TOKEN_L_BRACE; }
{R_BRACE} { return TOKEN_R_BRACE; }
{NUMBER}+ { return TOKEN_INT_LITERAL; }
{L_BRACKET} { return TOKEN_L_BRACKET; }
{R_BRACKET} { return TOKEN_R_BRACKET; }
{L_PAREN} { return TOKEN_L_PAREN; }
{R_PAREN} { return TOKEN_R_PAREN; }
\: { return TOKEN_COLON; }
\^ { return TOKEN_EXP; }
&& { return TOKEN_AND; }
\|\| { return TOKEN_OR; }
\+ { return TOKEN_ADD; }
- { return TOKEN_MINUS; }
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
(_|{LETTER})(_|{LETTER}|{NUMBER})* { return TOKEN_IDENT; }
. { return ERROR; }

%%
