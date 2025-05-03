#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef int ElType;

typedef struct {
    ElType data;
    Node* next;
} Node;

void insertHead(Node** headPointer, ElType data);
// I.S. headPointer terdefinisi (sembarang), data terdefinisi
// F.S. headPointer menunjuk ke data pertama

void insertAt(Node** headPointer, int position, ElType data);
// I.S. headPointer terdefinisi dan terisi. position terdefinisi dan dalam range, data terdefinisi
// F.S. headPointer menunjuk ke elemen selanjutnya sampai elemen posisi, elemen posisi menunjuk ke elemen selanjutnya

void deleteAt(Node** headPointer, int position);
// I.S. headPointer terdefinisi dan terisi. position terdefinisi dan dalam range, data terdefinisi
// F.S. headPointer menunjuk ke elemen selanjutnya sampai elemen posisi sebelumnya, elemen posisi sebelumnya menunjuk ke elemen posisi setelahnya

#endif