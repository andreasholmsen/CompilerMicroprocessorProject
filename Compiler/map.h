#include <stdio.h>
#include <string.h>

#define MAPSIZE 1024

extern char *keys[MAPSIZE];
extern int values[MAPSIZE];

void addSymbol(char * key, int value);

int findSymbol(char * key);

void changeSymbol(char * key, int value);


void addConst(char * key, int value);

int inKeys(char * key);

int isConstant(char * key);