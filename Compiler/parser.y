%{
#include <stdio.h>
#include "map.h"
#include "parser.tab.h"

// For using structures in map.c
extern char * keys[MAPSIZE];
extern int values[MAPSIZE];
extern char * const_keys[MAPSIZE];

int yylex(void);
int yyerror(const char *s);

// For defining multiple variables
int var_ptr = 0;
char * varNames[256];

extern FILE *yyin;

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

%left tPLUS tMINUS
%left tMULT tDIV


%%

Program : DataType tMAIN tOPAR tVOID tCPAR tOCURLY DeclarationPart tCCURLY {;}
        | DataType tMAIN tOPAR tCPAR tOCURLY DeclarationPart tCCURLY {;}
        ;

DeclarationPart : Declaration tSEMIC DeclarationPart {;}
                | Block {;}
                ;

Block : Line
        | Block Line
        ;

Line    : Assignment tSEMIC {;}
        | tPRINTF tOPAR Expr tCPAR tSEMIC {printf("%d\n", $3);}
        | tERROR {printf("ERROR\n");}
        ;

Term    : tNUM {$$ = $1;}
        | tID {$$ = findSymbol($1);}
        ;

DataType : tVOID {;} | tINT {;};

Expr    : Term {$$ = $1;}
        | Expr tPLUS Expr { $$ = $1 + $3; }    
        | Expr tMINUS Expr { $$ = $1 - $3; }
        | Expr tMULT Expr {$$ = $1 * $3;}
        | Expr tDIV Expr {$$= $1 / $3;}
        | tOPAR Expr tCPAR { $$ = $2;}
        | tMINUS Expr {$$ = -$2;}
        ;

Assignment      : tID tEQ Expr {changeSymbol($1, $3);}
                ;

Declaration     : tINT tID {addSymbol($2, 32765);}
                | tINT tID tEQ Expr { addSymbol($2, $4);}
                | tCONST tINT tID tEQ Expr {addConst($3, $5);}
                | tINT VariableList {for (int i = var_ptr-1; i > -1; i--) {addSymbol(varNames[i], 32765);} var_ptr = 0;}
                | tINT VariableList tEQ Expr {for (int i = var_ptr-1; i > -1; i--) {addSymbol(varNames[i], $4);} var_ptr = 0;}
                | tCONST tINT VariableList {for (int i = var_ptr-1; i > -1; i--) {addConst(varNames[i], 32765);} var_ptr = 0;}
                | tCONST tINT VariableList tEQ Expr {for (int i = var_ptr-1; i > -1; i--) {addConst(varNames[i], $5);} var_ptr = 0;}
                ;

VariableList    : tID tCOMMA VariableList { varNames[var_ptr++] = $1; }
                | tID tCOMMA tID { varNames[var_ptr++] = $1; varNames[var_ptr++] = $3; }
                ;


%%
int yyparse();

int yyerror(const char *s) { fprintf(stderr, "Syntax Error : %s\n", s); return 0; }

// https://github.com/black13/flex-and-bison/blob/master/ch04-input_management/03-input_from_strings/main.c
int main(int argc, char * argv[]) {
        for (int i = 0; i < MAPSIZE; i++) {
                keys[i] = 0;
                values[i] = 0;
                const_keys[i] = 0;
        }

        if (argc == 2) {
        yyin = fopen(argv[1], "r");
        } else {
                yyin = stdin;
        }
        yyparse();
        if (argc == 2) {
                fclose(yyin);
        }

return 0;
}