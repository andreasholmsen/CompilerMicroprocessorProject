#include <stdio.h>
#include <string.h>

#define MAPSIZE 1024

void addSymbol(char * key, int isConst);

int lookup(char * key);

int isConst(int addr);