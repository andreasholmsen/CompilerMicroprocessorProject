#include <stdio.h>
#include <string.h>
#include "symbolTable.h"
#include "stack.h"
#include <stdlib.h>



int ptr = 0; // Where to add next (key, address) pair
char * keys[MAPSIZE]; // Contains variable name
int addresses[MAPSIZE]; // addresses[i] constains address in stack.c to variablename at keys[i]

int const_ptr = 0; // Where to add next constant
char * const_keys[MAPSIZE];




void addSymbol(char * key, int value) {
    if (ptr >= MAPSIZE) return;

    keys[ptr] = strdup(key);
    addresses[ptr++] = add(value); // Adds to stack.c
}

void addConst(char * key, int value) {
    addSymbol(key, value);

    const_keys[const_ptr++] = strdup(key);
}




void changeSymbol(char * key, int value) {
    int index = inKeys(key);

    if (index == -1) {
        printf("ERROR, symbol not found\n");
        exit(1);
    }

    if (isConstant(key)) {
        printf("ERROR, trying to change a constant (%s <- %d) Exiting...\n", key, value);
        exit(1);
    }   

    insert(addresses[index] ,value); // Insert in stack.c
}



int findSymbol(char * key) {
    for (int i = ptr-1; i >= 0; i--) 
        if (strcmp(key, keys[i]) == 0) return addresses[i];
    

    return 0;
}



int inKeys(char * key) {
    for (int i = ptr-1; i >= 0; i--) 
        if (strcmp(key, keys[i]) == 0) return i;

    return 0;
}



int isConstant(char * key) {
    for (int i = const_ptr-1; i >= 0; i--)
        if (strcmp(key, const_keys[i]) == 0) return 1;
    
    return 0;
}