%{
#include <stdio.h>
#include <stdlib.h> 
#include "./memory/symbolTable.h"
#include "parser.tab.h"
#include "./memory/stack.h"

int yylex(void);
int yyerror(const char *s);

// Labels for if statements
int label_ptr = 0;
int end_labels[1024];
int end_label = -1;
#define push_end_label end_labels[++end_label] = label_ptr++
#define pop_end_label end_labels[end_label--]
#define peek_end_label end_labels[end_label]

// Writing instruction output
struct Instruction {
    int opcode;
    int a, b, c;
};

Instruction code[4096];
int code_ptr = 0;
#define add_code(inst,res,op1,op2) code[code_ptr++] = (Instruction) {inst, res, op1, op2}

extern FILE *yyin;
%}

%union { int nb; char * var; int addr;}
%token tEQ tPLUS tMINUS tMULT tDIV
%token tOPAR tCPAR tOCURLY tCCURLY
%token tVOID tMAIN tINT 
%token tCONST tCOMMA tPRINTF tSEMIC
%token tINF tSUP tEQU
%token tERROR
%token tIF tELSE tELSIF

%type <addr> Expr Term
%type <nb> IfElseStatement IfStatement Cond ElsifStatement
%token <nb> tNUM
%token <var> tID


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
        | tPRINTF tOPAR Expr tCPAR tSEMIC {printf("PRI @%d\n", $3);}
        | tERROR {printf("ERROR\n");}
        | IfElseStatement {}
        ;

IfElseStatement : IfStatement {printf("L%d:\n", pop_end_label);$$ = $1;}
                | IfStatement ElsifStatements {printf("L%d:\n", pop_end_label);$$ = $1;}
                | IfStatement ElseStatement {printf("L%d:\n", pop_end_label);$$ = $1;}
                | IfStatement ElsifStatements ElseStatement {printf("L%d:\n", pop_end_label);$$ = $1;}
;

IfStatement     : tIF Cond tOCURLY Block tCCURLY {push_end_label; $$ = label_ptr; printf("JMP L%d\n", peek_end_label); printf("L%d:\n", $2); }
                ;

Cond          : Expr {$$ = label_ptr; printf("JMF @%d L%d\n", $1, label_ptr++);}
                ;


ElsifStatements : ElsifStatements ElsifStatement {}
                | ElsifStatement {}
                ;

ElsifStatement  : tELSIF Cond tOCURLY Block tCCURLY {$$ = $2; printf("JMP L%d\n", peek_end_label); printf("L%d:\n", $2);}
                ;

ElseStatement   : tELSE tOCURLY Block tCCURLY {}
                ;


Term    : tNUM {$$ = new_temp(); printf("AFC @%d %d\n", $$, $1);}
        | tID {$$ = lookup($1); if ($$ < 0) {printf("Error, symbol unknown. Exiting...\n"); exit(1);}}
        ;

Expr    : Term {$$ = $1;}
        | Expr tPLUS Expr {free_temps($1,$3); $$ = new_temp(); printf("ADD @%d @%d @%d\n", $$, $1, $3);}    
        | Expr tMINUS Expr {free_temps($1,$3); $$ = new_temp(); printf("SOU @%d @%d @%d\n", $$, $1, $3);}
        | Expr tMULT Expr {free_temps($1,$3); $$ = new_temp(); printf("MUL @%d @%d @%d\n", $$, $1, $3);}
        | Expr tDIV Expr {free_temps($1,$3); $$ = new_temp(); printf("DIV @%d @%d @%d\n", $$, $1, $3);}
        | tOPAR Expr tCPAR { $$ = $2;}
        | tMINUS Expr {free_temp($2); $$ = $2; int temp = new_temp(); printf("AFC @%d 0\n", temp); printf("SOU @%d @%d @%d\n", $2, temp, $2);}
        | Expr tINF Expr {free_temps($1,$3); $$ = new_temp(); printf("INF @%d @%d @%d\n", $$, $1, $3);}
        | Expr tSUP Expr {free_temps($1,$3); $$ = new_temp(); printf("SUP @%d @%d @%d\n", $$, $1, $3);}
        | Expr tEQU Expr {free_temps($1,$3); $$ = new_temp(); printf("EQU @%d @%d @%d\n", $$, $1, $3);}
        ;

Assignment      : tID tEQ Expr {free_temp($3); int addr = lookup($1); 
                                if (isConst(addr)) {printf("ERROR, editing const. Exiting...\n"); exit(1);}  
                                printf("COP @%d @%d\n", lookup($1), $3);
                                };

Declaration     : tINT DeclaratorList {}
                | tCONST tINT ConstDeclaratorList {}
                ;

DeclaratorList  : Declarator
                | Declarator tCOMMA DeclaratorList
                ;

Declarator      : tID {addSymbol($1, 0);}
                | tID tEQ Expr {free_temp($3); addSymbol($1, 0); printf("COP @%d @%d\n", lookup($1), $3);}
                ;

ConstDeclaratorList     : ConstDeclarator
                        | ConstDeclarator tCOMMA ConstDeclaratorList
                        ;

ConstDeclarator: tID tEQ Expr {free_temp($3); addSymbol($1, 1);printf("COP @%d @%d\n", lookup($1), $3);};

%%
int yyparse();

int yyerror(const char *s) { fprintf(stderr, "Syntax Error : %s\n", s); return 1; }

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

return 0;
}