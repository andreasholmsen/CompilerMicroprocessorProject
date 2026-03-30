#include <stdio.h>
#include <string.h>

#define MAPSIZE 1024

// Adds the symbol to the symbolTable and adds to the stack
void addSymbol(char * key, int value);

// Adds a constant to the symbolTable and adds to the stack
void addConst(char * key, int value);

// Changes the symbol in stack.c if eligible
void changeSymbol(char * key, int value);

// Returns address in Stack.c of the symbol
int findSymbol(char * key);

// Returns 1 if the symbol is recognized
int inKeys(char * key);

// Returns 1 if symbol defined as a constant
int isConstant(char * key);