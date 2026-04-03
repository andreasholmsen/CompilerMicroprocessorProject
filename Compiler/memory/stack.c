#include <stdio.h>

#define STACKSIZE 1024
#define DEFAULT_VALUE 32765


int stack[STACKSIZE];
int stack_ptr = 0;
int stack_ptr_tmp = (STACKSIZE/2);


// Variables and constants

int is_empty() {
    return stack_ptr < 1 ? 1 : 0;
}

int pop() {
    return is_empty() ? DEFAULT_VALUE : stack[--stack_ptr];
}

int peek() {
    return is_empty() ? DEFAULT_VALUE : stack[stack_ptr];
}

int add(int value) {
    stack[stack_ptr] = value;
    return stack_ptr++;
}

void clear() {
    stack_ptr = 0;
}

void insert(int index, int value) {
    stack[index] = value;
}

int get(int index) {
    return stack[index];
}




// Temporary values
int is_empty_tmp() {
    return stack_ptr_tmp < (STACKSIZE/2) ? 1 : 0;
}

int pop_tmp() {
    return is_empty_tmp() ? DEFAULT_VALUE : stack[--stack_ptr_tmp];
}

int peek_tmp() {
    return is_empty_tmp() ? DEFAULT_VALUE : stack[stack_ptr_tmp];
}

int add_tmp(int value) {
    stack[stack_ptr_tmp] = value;
    return stack_ptr_tmp++;
}

void clear_tmp() {
    stack_ptr_tmp = STACKSIZE/2;
}