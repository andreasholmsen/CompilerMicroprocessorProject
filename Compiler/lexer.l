%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
%}

%option noyywrap

whitespace [ \t\r\n]
newline [\n]
letter [a-zA-Z]
chiffer [0-9]
alphanum [a-zA-Z0-9]
alphanumunderscore [a-zA-Z0-9_]

%%

"=" {return tEQ;}
"+" {return tPLUS;}
"-" {return tMINUS;}
"*" {return tMULT;}
"/" {return tDIV;}

"(" {return tOPAR;}
")" {return tCPAR;}
"{" {return tOCURLY;}
"}" {return tCCURLY;}

void {return tVOID;}
main {return tMAIN;}
int {return tINT;}
const {return tCONST;}
printf {return tPRINTF;}
, {return tCOMMA;}
; {return tSEMIC;}


[0-9]+(e|E)[+-]?[0-9]+ { // Exponential integers https://stackoverflow.com/questions/68602795/in-c-code-how-to-convert-string-to-exponential-value
    yylval.nb = (int) atof(yytext);
    return tNUM;
}

[0-9]+ { // Number
    yylval.nb = atoi(yytext); 
    return tNUM;
} 

[a-zA-Z][a-zA-Z0-9_]* {  // Identifiers
    yylval.var = strdup(yytext);
    return tID;
}

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