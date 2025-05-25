#include <stdlib.h>
#include "../header/linked-list.h"

Node* createLinked(int data) {
    Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void linkedInsertHead(Node** headPointer, int data){
    Node* newNode = createLinked(data);
    newNode->next = *headPointer;
    *headPointer = newNode;
}

void linkedDeleteHead(Node** head)
{
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void linkedInsertAt(Node** headPointer, int position, int data){
    Node* newNode = createLinked(data);
    if(position == 0){
        linkedInsertHead(headPointer, data);
    }
    else{
        Node* temp = *headPointer;
        for(int i = 0; temp != NULL && i < position; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Position out of range!\n");
            free(newNode);
        }
        else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void linkedDeleteAt(Node** headPointer, int position){
    if(*headPointer == NULL){
        printf("Data kosong.\n");
    }
    else{
        Node* temp = *headPointer;
        if(position == 0){
            *headPointer = temp->next;
            free(temp);
        }
        else{
            for(int i = 0; temp != NULL && i < position - 1; i++){
                temp = temp->next;
            }
            if(temp == NULL || temp->next == NULL){
                printf("Position out of range!\n");
            }
            else{
                Node* next = temp->next->next;
                free(temp->next);
                temp->next = next;
            }
        }
    }
}