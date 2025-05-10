#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "../header/queue.h"

void initQueue(Queue *q){
    q->front = q->rear = -1;
}

bool isQueueEmpty(const Queue *q){
    return (q->front == -1);
}

bool isQueueFull(const Queue *q){
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, const char *value){
    if(isQueueFull(q)){
        printf("Error! Queue is full\n");
        return;
    }
    if(isQueueEmpty(q)){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    strcpy(q->items[q->rear], value);
}

const char* dequeue(Queue *q){
    if(isQueueEmpty(q)){
        return NULL;
    }
    const char* val = q->items[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1; //reset lagi ke kondisi awal
    }else{
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return val;
}

const char* peekQueue(const Queue *q){
    if (isQueueEmpty(q)) {
        return NULL;
    }
    return q->items[q->front];
}

void printQueue(const Queue *q){
    if (isQueueEmpty(q)) {
        printf("Queue saat ini sedang kosong.\n");
        return;
    }
    printf("Current queue :\n");
    int i = q->front;
    do {
        int sequence = i + 1;
        printf("%d) %s\n", sequence, q->items[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i != (q->rear + 1) % MAX_QUEUE_SIZE);
}