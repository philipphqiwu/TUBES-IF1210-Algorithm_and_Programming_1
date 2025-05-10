#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define MAX_VAL_LENGTH 50

typedef struct {
    char items[MAX_QUEUE_SIZE][MAX_VAL_LENGTH]; //queue of strings
    int front, rear;
} Queue;

void initQueue(Queue *q);
bool isQueueEmpty(const Queue *q);
bool isQueueFull(const Queue *q);
void enqueue(Queue *q, const char *value);
const char* dequeue(Queue *q);
const char* peekQueue(const Queue *q);
void printQueue(const Queue *q);

#endif