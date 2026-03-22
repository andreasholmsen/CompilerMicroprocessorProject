compile:
	flex lexer.l && bison -d parser.y && gcc lex.yy.c parser.tab.c map.c -o compiler

lcompile:
	flex lexer.l && gcc lex.yy.c -o lex

ltest:
	./lex test.txt


ycompile:
	bison -d -y parser.y