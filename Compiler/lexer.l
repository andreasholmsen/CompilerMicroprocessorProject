%{
#include <stdio.h>
%}


[ \t]+ {}; /* Blank spaces and tablatures are ignored */

[a-zA-Z][a-zA-Z0-9_]* {return IDENTIFIER;} /* Identifiers (variables) */

(+|-)?[0-9]+ { yylval = atoi(yytext) ; return NUMBER;} /* Numbers */

