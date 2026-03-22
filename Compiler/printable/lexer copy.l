%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

extern FILE *yyin;
%}

%option noyywrap

whitespace [ \t\r\n]
newline [\n]
letter [a-zA-Z]
chiffer [0-9]
alphanum [a-zA-Z0-9]
alphanumunderscore [a-zA-Z0-9_]

%%

"=" {printf("TOKEN: tEQ\n");return tEQ;}
"+" {printf("TOKEN: tPLUS\n");return tPLUS;}
"-" {printf("TOKEN: tMINUS\n");return tMINUS;}
"*" {printf("TOKEN: tMULT\n");return tMULT;}
"/" {printf("TOKEN: tDIV\n");return tDIV;}

"(" {printf("TOKEN: tOPAR\n");return tOPAR;}
")" {printf("TOKEN: tCPAR\n");return tCPAR;}
"{" {printf("TOKEN: tOCURLY\n");return tOCURLY;}
"}" {printf("TOKEN: tCCURLY\n");return tCCURLY;}

void {printf("TOKEN: tVOID\n");return tVOID;}
main {printf("TOKEN: tMAIN\n");return tMAIN;}
int {printf("TOKEN: tINT\n");return tINT;}
const {printf("TOKEN: tCONST\n");return tCONST;}
printf {printf("TOKEN: tPRINTF\n");return tPRINTF;}
, {printf("TOKEN: tCOMMA)\n");return tCOMMA;}
; {printf("TOKEN: tSEMIC\n");return tSEMIC;}

[+-]?[0-9]+(e|E)[+-]?[0-9]+ { // Exponential integers
    printf("TOKEN: tNUM (exp)\n");
    yylval.nb = (int) strtod(yytext, NULL);
    return tNUM;
}
[+-]?[0-9]+ {printf("TOKEN: tNUM\n"); yylval.nb = atoi(yytext); return tNUM;} // Number
[a-zA-Z][a-zA-Z0-9_]* {printf("TOKEN: tID\n");yylval.var = strdup(yytext); return tID;} // Identifiers

{whitespace}+ {} /* Blank spaces are ignored */

. {printf("TOKEN: tERROR\n");return tERROR;}

%%

/*
int main(int argc, char**argv) {
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    if (argc == 2) {
        fclose(yyin);
    }
    printf("\n");
}
*/
/* Inspiration from https://courses.cs.umbc.edu/331/papers/lexyacc.pdf */