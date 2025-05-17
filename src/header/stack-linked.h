#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

#define MAX_STACK_SIZE 100
typedef int ElType;

// Mengembalikan 1 jika stack tidak terisi, 0 jika terisi
int isStackEmpty(Node** stack);

// Memasukan data pada bagian "atas" stack
void push(Node** stack, ElType data);
// I.S. stack dan data terdefinisi
// F.S. jika stack tidak penuh, data masuk pada elemen terakhir.
//      jika stack penuh, mengeluarkan error message.

// Mengembalikan nilai elemen pada bagian "atas" stack dan menghilangkan elemen tersebut
ElType pop(Node** stack);
// I.S. stack terdefinisi.
// F.S. elemen bagian "atas" hilang.

// Mengembalikan nilai elemen pada bagian "atas" stack tanpa menghilangkan elemen tersebut.
ElType peek(Node** stack);
// Akan mengembalikan nilai -1 jika stack kosong

// Menampilkan isi stack
void printStack(Node** stack);
// I.S. stack terdefinisi.
// F.S. semua elemen dalam stack ditampilkan pada layar.

#endif