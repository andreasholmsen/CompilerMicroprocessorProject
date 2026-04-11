%{
#include <stdio.h>
#include <stdlib.h> 
#include "parser.tab.h"
#include "./memory/symbolTable.h"
#include "./memory/stack.h"

int yylex(void);
int yyerror(const char *s);

// Labels for if statements
int label_ptr = 0;
int end_labels[1024];
int end_ptr = -1;
#define push_end_label end_labels[++end_ptr] = label_ptr++
#define pop_end_label end_labels[end_ptr--]
#define peek_end_label end_labels[end_ptr]

// Writing instruction output
struct Instruction {
        char code;
        int a, b, c;
};
struct Instruction code[4096];
int code_ptr = 0;
#define add_code(inst,res,op1,op2) code[code_ptr++]=(struct Instruction){inst, res, op1, op2}

FILE *f_asm;
FILE *f_bin;


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
%token tWHILE

%type <addr> Expr Term
%type <nb> IfElseStatement IfStatement Cond ElsifStatement
%type <nb> tWhileCond
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
        | tPRINTF tOPAR Expr tCPAR tSEMIC {add_code('C', $3, 0, 0);}
        | tERROR {printf("Encountered Error\n");}
        | IfElseStatement {}
        | WhileStatement {}
        ;

IfElseStatement : IfStatement {add_code('L', pop_end_label, 0, 0);$$ = $1;}
                | IfStatement ElsifStatements {add_code('L', pop_end_label, 0, 0);$$ = $1;}
                | IfStatement ElseStatement {add_code('L', pop_end_label, 0, 0);$$ = $1;}
                | IfStatement ElsifStatements ElseStatement {add_code('L', pop_end_label, 0, 0);$$ = $1;}
;

IfStatement     : tIF Cond tOCURLY Block tCCURLY {push_end_label; $$ = label_ptr; add_code('7', peek_end_label, 0, 0); add_code('L', $2,0,0); }
                ;

Cond          : Expr {$$ = label_ptr; add_code('8', $1, label_ptr++, 0);}
                ;


ElsifStatements : ElsifStatements ElsifStatement {}
                | ElsifStatement {}
                ;

ElsifStatement  : tELSIF Cond tOCURLY Block tCCURLY {$$ = $2; add_code('7', peek_end_label, 0, 0); add_code('L', $2, 0, 0);}
                ;

ElseStatement   : tELSE tOCURLY Block tCCURLY {}
                ;


WhileStatement  : tWhileCond tOPAR Cond tCPAR tOCURLY Block tCCURLY {add_code('7', pop_end_label,0,0);  add_code('L', $3,0,0);}
                ;

tWhileCond : tWHILE {$$ = push_end_label; add_code('L', $$,0,0);}

Term    : tNUM {$$ = new_temp(); add_code('6', $$, $1, 0);}
        | tID {$$ = lookup($1); if ($$ < 0) {printf("Error, symbol unknown. Exiting...\n"); exit(1);}}
        ;

Expr    : Term {$$ = $1;}
        | tOPAR Expr tCPAR { $$ = $2;}
        | Expr tPLUS Expr {free_temps($1,$3); $$ = new_temp(); add_code('1', $$, $1, $3);}    
        | Expr tMINUS Expr {free_temps($1,$3); $$ = new_temp(); add_code('3', $$, $1, $3);}
        | Expr tMULT Expr {free_temps($1,$3); $$ = new_temp(); add_code('2', $$, $1, $3);}
        | Expr tDIV Expr {free_temps($1,$3); $$ = new_temp(); add_code('4', $$, $1, $3);}
        | tMINUS Expr {free_temp($2); $$ = $2; int temp = new_temp(); add_code('6', temp, 0, 0); add_code('3', $2, temp, $2);}
        | Expr tINF Expr {free_temps($1,$3); $$ = new_temp(); add_code('9', $$, $1, $3);}
        | Expr tSUP Expr {free_temps($1,$3); $$ = new_temp(); add_code('A', $$, $1, $3);}
        | Expr tEQU Expr {free_temps($1,$3); $$ = new_temp(); add_code('B', $$, $1, $3);}
        ;

Assignment      : tID tEQ Expr {free_temp($3); int addr = lookup($1); 
                                if (isConst(addr)) {printf("ERROR, editing const. Exiting...\n"); exit(1);}  
                                add_code('5', lookup($1), $3, 0);
                                };

Declaration     : tINT DeclaratorList {}
                | tCONST tINT ConstDeclaratorList {}
                ;

DeclaratorList  : Declarator
                | Declarator tCOMMA DeclaratorList
                ;

Declarator      : tID {addSymbol($1, 0);}
                | tID tEQ Expr {free_temp($3); addSymbol($1, 0); add_code('5', lookup($1), $3, 0);}
                ;

ConstDeclaratorList     : ConstDeclarator
                        | ConstDeclarator tCOMMA ConstDeclaratorList
                        ;

ConstDeclarator: tID tEQ Expr {free_temp($3); addSymbol($1, 1); add_code('5', lookup($1), $3, 0);};

%%
int yyparse();

int yyerror(const char *s) { fprintf(stderr, "Syntax Error : %s\n", s); return 1; }

void format_bin(); // Code below main function, for readability Exports file to binary code
void format_asm(); // Code below main function, for readability. Exports file to asm code

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

        int labelsSeen = 0; // How many temporary label lines we have seen so far
        int labelLine[1024]; // Associate labels with line
        // Convert lables to lines
        for (int i = 0; i < code_ptr; i++) {
                if (code[i].code == 'L') {
                        labelLine[code[i].a] = i - labelsSeen++ + 1;
                } 
        }

        for(int i = 0; i < code_ptr; i++) {
                if (code[i].code == '7') {
                        code[i].a = labelLine[code[i].a];
                }
                if (code[i].code == '8') {
                        code[i].b = labelLine[code[i].b];
                }
                
        }

        format_asm();
        format_bin();

        return 0;
}






























void format_asm() {
        f_asm = fopen("output_assembly.txt", "w");
        for(int i = 0; i < code_ptr; i++) {
                switch (code[i].code) {
                        case '1': fprintf(f_asm, "%s @%d @%d @%d\n", "ADD", code[i].a, code[i].b, code[i].c); break;
                        case '2': fprintf(f_asm, "%s @%d @%d @%d\n", "MUL", code[i].a, code[i].b, code[i].c); break;
                        case '3': fprintf(f_asm, "%s @%d @%d @%d\n", "SOU", code[i].a, code[i].b, code[i].c); break;
                        case '4': fprintf(f_asm, "%s @%d @%d @%d\n", "DIV", code[i].a, code[i].b, code[i].c); break;
                        case '5': fprintf(f_asm, "%s @%d @%d\n", "COP", code[i].a, code[i].b); break;
                        case '6': fprintf(f_asm, "%s @%d %d\n", "AFC", code[i].a, code[i].b); break;
                        case '7': fprintf(f_asm, "%s %d\n", "JMP", code[i].a); break;
                        case '8': fprintf(f_asm, "%s @%d %d\n", "JMF", code[i].a, code[i].b); break;
                        case '9': fprintf(f_asm, "%s @%d @%d @%d\n", "INF", code[i].a, code[i].b, code[i].c); break;
                        case 'A': fprintf(f_asm, "%s @%d @%d @%d\n", "SUP", code[i].a, code[i].b, code[i].c); break;
                        case 'B': fprintf(f_asm, "%s @%d @%d @%d\n", "EQU", code[i].a, code[i].b, code[i].c); break;
                        case 'C': fprintf(f_asm, "%s @%d\n", "PRI", code[i].a);
                        case 'L': break;
                }
        }
        fclose(f_asm);
}

void format_bin() {
        f_bin = fopen("output_binary.txt", "w");
        for(int i = 0; i < code_ptr; i++) {
                switch (code[i].code) {
                        case '1': fprintf(f_bin, "%d @%d @%d @%d\n", 1, code[i].a, code[i].b, code[i].c); break;
                        case '2': fprintf(f_bin, "%d @%d @%d @%d\n", 2, code[i].a, code[i].b, code[i].c); break;
                        case '3': fprintf(f_bin, "%d @%d @%d @%d\n", 3, code[i].a, code[i].b, code[i].c); break;
                        case '4': fprintf(f_bin, "%d @%d @%d @%d\n", 4, code[i].a, code[i].b, code[i].c); break;
                        case '5': fprintf(f_bin, "%d @%d @%d\n", 5, code[i].a, code[i].b); break;
                        case '6': fprintf(f_bin, "%d @%d %d\n", 6, code[i].a, code[i].b); break;
                        case '7': fprintf(f_bin, "%d %d\n", 7, code[i].a); break;
                        case '8': fprintf(f_bin, "%d @%d %d\n", 8, code[i].a, code[i].b); break;
                        case '9': fprintf(f_bin, "%d @%d @%d @%d\n", 9, code[i].a, code[i].b, code[i].c); break;
                        case 'A': fprintf(f_bin, "%c @%d @%d @%d\n", 'A', code[i].a, code[i].b, code[i].c); break;
                        case 'B': fprintf(f_bin, "%c @%d @%d @%d\n", 'B', code[i].a, code[i].b, code[i].c); break;
                        case 'C': fprintf(f_bin, "%c @%d\n", 'C', code[i].a);
                        case 'L': break;
                }
        }
        fclose(f_bin);
}