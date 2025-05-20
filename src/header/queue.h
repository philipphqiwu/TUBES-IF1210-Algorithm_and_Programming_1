#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

typedef struct Queue {
    node* front;
    node* rear;
    int counter;
} queue;

node* createNode(int data);
queue* createQueue();
int isEmpty(queue* q);
void enqueue(queue* q, int data);
int dequeue(queue* q);
int peek(queue* q);
void printQueue(queue* q);

#endif