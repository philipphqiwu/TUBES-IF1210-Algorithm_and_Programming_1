
#include "../header/Queue.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new Node
Node* createNode(int data){
    // Allocate memory for a new Node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Check if memory allocation was successful
    if (newNode == NULL)
        return NULL;
    // Initialize the Node's data and next pointer
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
Queue* createQueue(){
    // Allocate memory for a new Queue
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    // Initialize the front and rear pointers of the Queue
    newQueue->front = newQueue->rear = NULL;
    newQueue->counter = 0;
    return newQueue;
}

// Function to check if the Queue is empty
int isQueueEmpty(Queue* q){
    // Check if the front pointer is NULL
    return q->front == NULL;
}

// Function to add an element to the Queue
void enqueue(Queue* q, int data){
    // Create a new Node with the given data
    Node* newNode = createNode(data);
    // Check if memory allocation for the new Node was
    // successful
    if (!newNode) {
        printf("Queue Overflow!\n");
        return;
    }
    // If the Queue is empty, set the front and rear
    // pointers to the new Node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    // Add the new Node at the end of the Queue and update
    // the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
    q->counter += 1;
}

// Function to remove an element from the Queue
int dequeue(Queue* q){
    // Check if the Queue is empty
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    // Store the front Node and update the front pointer
    Node* temp = q->front;
    q->front = q->front->next;
    // If the Queue becomes empty, update the rear pointer
    if (q->front == NULL)
        q->rear = NULL;
    // Store the data of the front Node and free its memory
    int data = temp->data;
    q->counter -= 1;
    free(temp);
    return data;
}

// Function to return the front element of the Queue
int peekQueue(Queue* q){
    // Check if the Queue is empty
    if (isQueueEmpty(q))
        return -1;
    // Return the data of the front Node
    return q->front->data;
}

// Function to print the Queue
void printQueue(Queue* q){
    // Traverse the Queue and print each element
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}