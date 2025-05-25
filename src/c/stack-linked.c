#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/linked-list.h"
#include "../header/stack-linked.h"

int isStackEmpty(Node** stack){
    return (*stack == NULL);
}

void push(Node** stack, ElType data){
    linkedInsertHead(stack, data);
}

ElType pop(Node** stack){
    if(isEmpty(stack)){
        printf("Stack sudah kosong!");
        return -1;
    }
    ElType data = (*stack)->data;
    linkedDeleteHead(stack);
    return data;
}

ElType peek(Node** stack){
    if(isEmpty(stack)){
        return -1;
    }
    return (*stack)->data;
}

void printStack(Node** stack){
    Node* temp = *stack;
    while(temp != NULL){
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}