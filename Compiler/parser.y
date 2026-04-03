%{
#include <stdio.h>
#include <stdlib.h> 
#include "./memory/symbolTable.h"
#include "parser.tab.h"
#include "./memory/stack.h"

// For using structures in symbolTable
extern char * keys[MAPSIZE];
extern int values[MAPSIZE];
extern char * const_keys[MAPSIZE];

int yylex(void);
int yyerror(const char *s);

// For defining multiple variables in one line
int var_ptr = 0;
char * varNames[256];

extern FILE *yyin;
%}

%union { int nb; char * var; }
%token tEQ tPLUS tMINUS tMULT tDIV
%token tOPAR tCPAR tOCURLY tCCURLY
%token tVOID tMAIN tINT 
%token tCONST tCOMMA tPRINTF tSEMIC
%token tINF tSUP tEQU
%token tERROR

%token <nb> tNUM
%token <var> tID

%type <nb> Program Line Expr Term Declaration

%left tEQU tINF tSUP
%left tPLUS tMINUS
%left tMULT tDIV

%%

Program : tMAIN tOPAR tVOID tCPAR tOCURLY DeclarationPart tCCURLY {;}
        | tMAIN tOPAR tCPAR tOCURLY DeclarationPart tCCURLY {;}
        ;

DeclarationPart : Declaration tSEMIC DeclarationPart {;}
                | Block {;}
                ;

Block : Line
        | Block Line
        ;

Line    : Assignment tSEMIC {;}
        | tPRINTF tOPAR Expr tCPAR tSEMIC {printf("PRI @%d (%d)\n", $3, get($3));}
        | tERROR {printf("ERROR\n");}
        ;

Term    : tNUM {$$ = add_tmp($1);}
        | tID {$$ = findSymbol($1);}
        ;

Expr    : Term {$$ = $1;}
        | Expr tPLUS Expr {printf("ADD @%d @%d @%d\n", $$, $1, $3); $$ = $$= add_tmp(pop_tmp() + pop_tmp()); }    
        | Expr tMINUS Expr {printf("SOU @%d @%d @%d\n", $$, $1, $3); int val1 = pop_tmp(); $$= add_tmp( pop_tmp() - val1); }
        | Expr tMULT Expr {printf("MUL @%d @%d @%d\n", $$, $1, $3); $$= add_tmp(pop_tmp() * pop_tmp()); }
        | Expr tDIV Expr {printf("DIV @%d @%d @%d\n", $$, $1, $3); int val1 = pop_tmp(); $$= add_tmp(pop_tmp() / val1); }
        | tOPAR Expr tCPAR { $$ = $2;}
        | tMINUS Expr {$$ = add_tmp(-pop_tmp());}
        | Expr tINF Expr {$$ = add_tmp(pop_tmp() > pop_tmp() ? 1 : 0);}
        | Expr tSUP Expr {$$ = add_tmp(pop_tmp() < pop_tmp() ? 1 : 0);}
        | Expr tEQU Expr {$$ = add_tmp(pop_tmp() == pop_tmp() ? 1 : 0);}
        ;

Assignment      : tID tEQ Expr {int val = pop_tmp(); printf("AFC @%d %d\n", findSymbol($1), val); changeSymbol( $1, val);}
                ;

Declaration     : tINT tID {addSymbol($2, 32765);}
                | tINT tID tEQ Expr {int val = pop_tmp(); addSymbol($2, val); printf("AFC @%d %d\n", findSymbol($2), val);}
                | tCONST tINT tID tEQ Expr {addConst($3, $5);}
                | tINT VariableList {for (int i = var_ptr-1; i > -1; i--) {addSymbol(varNames[i], 32765);} var_ptr = 0;}
                | tINT VariableList tEQ Expr {int val = pop_tmp(); for (int i = var_ptr-1; i > -1; i--) {addSymbol(varNames[i], val); printf("AFC @%d %d\n", findSymbol(varNames[i]), val);} var_ptr = 0;}
                | tCONST tINT VariableList {for (int i = var_ptr-1; i > -1; i--) {addConst(varNames[i], 32765);} var_ptr = 0;}
                | tCONST tINT VariableList tEQ Expr {int val = pop_tmp(); for (int i = var_ptr-1; i > -1; i--) {addConst(varNames[i], val); printf("AFC @%d %d\n", findSymbol(varNames[i]), val);} var_ptr = 0;}
                ;

VariableList    : tID tCOMMA VariableList { varNames[var_ptr++] = $1; }
                | tID tCOMMA tID { varNames[var_ptr++] = $1; varNames[var_ptr++] = $3; }
                ;


%%
int yyparse();

int yyerror(const char *s) { fprintf(stderr, "Syntax Error : %s\n", s); return 1; }

void print_stack() {
        if (!is_empty()) {
                int val = pop();
                print_stack();
                printf("%d\n", val);
        }
        return;
}

void print_stack_tmp() {
        if (!is_empty_tmp()) {
                int val = pop_tmp();
                print_stack_tmp();
                printf("%d\n", val);
        }
        return;
}

// https://github.com/black13/flex-and-bison/blob/master/ch04-input_management/03-input_from_strings/main.c
int main(int argc, char * argv[]) {
        if (argc == 2) {
        yyin = fopen(argv[1], "r");
        } else {
                yyin = stdin;
        }
        yyparse();
        if (argc == 2) {
                fclose(yyin);
        }


        // FOR TESTING
        printf("\n\n=====GDB DEBUGGING MODE v0.1 =====\n");

        printf("---------------STACK--------------\n");
        print_stack();
        printf("---------------TEMP --------------\n");
        print_stack_tmp();

        printf("=====GDB DEBUGGING DONE =====\n");

return 0;
}