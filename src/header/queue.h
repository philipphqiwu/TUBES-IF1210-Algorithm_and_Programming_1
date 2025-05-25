#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <string.h>
#include "linked-list.h"

typedef struct Queue {
    Node* front;
    Node* rear;
    int counter;
} Queue;

Node* createNode(int data);
Queue* createQueue();
int isQueueEmpty(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peekQueue(Queue* q);
void printQueue(Queue* q);

#endif