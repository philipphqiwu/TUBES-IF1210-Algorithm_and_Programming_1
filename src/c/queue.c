
#include "../header/queue.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
node* createNode(int data){
    // Allocate memory for a new node
    node* newNode = (node*)malloc(sizeof(node));
    // Check if memory allocation was successful
    if (newNode == NULL)
        return NULL;
    // Initialize the node's data and next pointer
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
queue* createQueue(){
    // Allocate memory for a new queue
    queue* newQueue = (queue*)malloc(sizeof(queue));
    // Initialize the front and rear pointers of the queue
    newQueue->front = newQueue->rear = NULL;
    queue* counter = 0;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(queue* q){
    // Check if the front pointer is NULL
    return q->front == NULL;
}

// Function to add an element to the queue
void enqueue(queue* q, int data){
    // Create a new node with the given data
    node* newNode = createNode(data);
    // Check if memory allocation for the new node was
    // successful
    if (!newNode) {
        printf("Queue Overflow!\n");
        return;
    }
    // If the queue is empty, set the front and rear
    // pointers to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    // Add the new node at the end of the queue and update
    // the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
    q->counter += 1;
}

// Function to remove an element from the queue
int dequeue(queue* q){
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    // Store the front node and update the front pointer
    node* temp = q->front;
    q->front = q->front->next;
    // If the queue becomes empty, update the rear pointer
    if (q->front == NULL)
        q->rear = NULL;
    // Store the data of the front node and free its memory
    int data = temp->data;
    q->counter -= 1;
    free(temp);
    return data;
}

// Function to return the front element of the queue
int peek(queue* q){
    // Check if the queue is empty
    if (isEmpty(q))
        return -1;
    // Return the data of the front node
    return q->front->data;
}

// Function to print the queue
void printQueue(queue* q){
    // Traverse the queue and print each element
    node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}