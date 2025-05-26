#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

#define MAX_STACK_SIZE 100

typedef struct Stack {
    Node* head;
    int length;
} Stack;

// Menginisialisasi stack
void createStack(Stack* stack);
// I.S. stack terdefinisi, sembarang.
// F.S. komponen head pada stack terisi dengan nilai NULL.

// Mengembalikan 1 jika stack tidak terisi, 0 jika terisi
int isStackEmpty(Stack stack);

// Memasukan data pada bagian "atas" stack
void push(Stack* stack, int data);
// I.S. stack dan data terdefinisi
// F.S. jika stack tidak penuh, data masuk pada elemen terakhir.
//      jika stack penuh, mengeluarkan error message.

// Mengembalikan nilai elemen pada bagian "atas" stack dan menghilangkan elemen tersebut
int pop(Stack* stack);
// I.S. stack terdefinisi.
// F.S. elemen bagian "atas" hilang.

// Mengembalikan nilai elemen pada bagian "atas" stack tanpa menghilangkan elemen tersebut.
int peekStack(Stack* stack);
// Akan mengembalikan nilai -1 jika stack kosong

// Menampilkan isi stack
void printStack(Stack stack);
// I.S. stack terdefinisi.
// F.S. semua elemen dalam stack ditampilkan pada layar.

#endif