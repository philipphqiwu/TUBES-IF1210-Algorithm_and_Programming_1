#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/linked-list.h"
#include "../header/stack-linked.h"

void createStack(Stack* stack){ 
    stack->head = NULL;
    stack->length = 0;
}

int isStackEmpty(Stack stack){
    return (stack.head == NULL);
}

void push(Stack* stack, int data){
    Node* new_node = createLinked(data);
    if (!new_node){ // Ketika tidak berhasil teralokasi
        printf("\nStack Overflow");
        return;
    }
    new_node->next = stack->head;
    stack->head = new_node;
    stack->length++;
}

int pop(Stack* stack){
    if(isStackEmpty(*stack)){
        printf("Stack sudah kosong!");
        return 0;
    }
    int data = stack->head->data;

    Node* temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    stack->length--;
    return data;
}

int peekStack(Stack* stack){
    if (!isStackEmpty(*stack))
        return stack->head->data;
    else {
        printf("\nStack is empty");
        return 0;
    }
}

void printStack(Stack stack){
    Node* temp = stack.head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}