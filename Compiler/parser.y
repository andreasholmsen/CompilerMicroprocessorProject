%{
#include <stdio.h>
#include "map.h"
#include "parser.tab.h"

extern char * keys[MAPSIZE];
extern int values[MAPSIZE];

int yylex(void);
int yyerror(const char *s);

%}

%union { int nb; char * var; }
%token tEQ tPLUS tMINUS tMULT tDIV
%token tOPAR tCPAR tOCURLY tCCURLY
%token tVOID tMAIN tINT 
%token tCONST tCOMMA tPRINTF tSEMIC
%token tERROR

%token <nb> tNUM
%token <var> tID

%type <nb> Program Line Expr Term Declaration

%%

Program : Line
        | Program Line
        ;

Line    : Assignment tSEMIC {;}
        | tPRINTF tSEMIC {printf("testing\n");}
        | Declaration tSEMIC {;}
        | tPRINTF Expr tSEMIC {printf("%d\n", $2);}
        | tERROR {printf("ERROR\n");}
        ;

Term    : tNUM {$$ = $1;}
        | tID {$$ = findSymbol($1);}
        ;

Expr    : Term {$$ = $1;}
        | Expr tPLUS Term { $$ = $1 + $3; }    
        | Expr tMINUS Term { $$ = $1 - $3; }
        | Expr tMULT Term {$$ = $1 * $3;}
        | Expr tDIV Term {$$= $1 / $3;}
        | tOPAR Expr tCPAR { $$ = $2;}
        ;

Assignment     
        : tID tEQ Expr {addSymbol($1, $3);}
        ;

Declaration
        : tINT tID tEQ Expr { addSymbol($2, $4); }
        ;


%%
int yyparse();

int yyerror(const char *s) { fprintf(stderr, "Syntax Error : %s\n", s); return 0; }

int main(void) {
        for (int i = 0; i < MAPSIZE; i++) {
                keys[i] = 0;
                values[i] = 0;
        }

yyparse();
return 0;
}