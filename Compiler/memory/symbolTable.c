#include <stdio.h>
#include <string.h>
#include "symbolTable.h"
#include "stack.h"
#include <stdlib.h>

struct symbol {
    int addr;
    int isConst;
    char * name;
};

int sym_ptr = -1; // Where to add next (key, address) pair
struct symbol map[MAPSIZE];

void addSymbol(char * key, int isConst) {
    map[++sym_ptr] = (struct symbol) {new_addr(), isConst, strdup(key)};
}

int isConst(int addr) {
    return map[addr].isConst;
}

int lookup(char * key) {
    for (int i = sym_ptr; i > -1; i--) if (strcmp(key, map[i].name) == 0) return map[i].addr;
    return -1;
}

