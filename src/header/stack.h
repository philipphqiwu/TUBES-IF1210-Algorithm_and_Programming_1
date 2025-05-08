#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_VAL_LENGTH 50

typedef struct {
    char items[MAX_STACK_SIZE][MAX_VAL_LENGTH]; //stack of strings
    int top;
} Stack;

void initStack(Stack *s);
bool isStackEmpty(const Stack *s);
bool isStackFull(const Stack *s);
void push(Stack *s, const char *value);
const char* pop(Stack *s);
const char* peek(const Stack *s);
void printStack(const Stack *s);

#endif