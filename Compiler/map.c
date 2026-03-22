#include <stdio.h>
#include <string.h>
#include "map.h"


int ptr = 0;
char * keys[MAPSIZE];
int values[MAPSIZE];

void addSymbol(char * key, int value) {
    if (ptr >= MAPSIZE) return;
    keys[ptr] = strdup(key);
    values[ptr] = value;
    ptr++;
}

int findSymbol(char * key) {
    for (int i = ptr-1; i >= 0; i--) {
        if (strcmp(key, keys[i]) == 0) {
            return values[i];
        }
    }
    return 0;
}