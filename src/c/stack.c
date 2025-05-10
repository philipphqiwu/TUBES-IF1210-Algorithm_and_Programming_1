#include "../header/stack.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void initStack(Stack *s){
    s->top = -1;
}

bool isStackEmpty(const Stack *s){
    return (s->top == -1);
}

bool isStackFull(const Stack *s){
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(Stack *s, const char *value){
    if(isStackFull(s)){
        printf("Error! Stack is full\n");
        return;
    }
    strcpy(s->items[++s->top], value);
}
const char* pop(Stack *s){
    if(isStackEmpty(s)){
        return NULL;
    }
    return s->items[s->top--];
}

const char* stackPeek(const Stack *s){
    if (isStackEmpty(s)) {
        return NULL;
    }
    return s->items[s->top];
}

void printStack(const Stack *s){
    if (isStackEmpty(s)) {
        printf("Stack kosong.\n");
        return;
    }
    printf("Contents (TOP -> BOTTOM):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("- %s\n", s->items[i]);
    }
}