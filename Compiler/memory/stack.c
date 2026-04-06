#include <stdio.h>
#include "stack.h"

#define STACKSIZE 1024

int stack_ptr = -1;
int tmp_ptr = (STACKSIZE/2)-1;

// Variables and constants

// Temporary values
int is_empty() {
    return stack_ptr < 0 ? 1 : 0;
}

int peek() {
    return stack_ptr;
}

int new_temp() {
    return ++tmp_ptr;
}

int new_addr() {
    return ++stack_ptr;
}

void free_temp(int a) {
    if (a >= (STACKSIZE/2) - 1) tmp_ptr--;
}

void free_temps(int a, int b) {
    if (a >= (STACKSIZE/2) - 1) tmp_ptr--;
    if (b >= (STACKSIZE/2) - 1) tmp_ptr--;
}