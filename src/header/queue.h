#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int counter;
} Queue;

Node* createNode(int data);
Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peek(Queue* q);
void printQueue(Queue* q);

#endif