#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef int ElType;

typedef struct Node{
    ElType data;
    struct Node* next;
} Node;

Node* createLinked(int data);
// menginisialisasi linked list.

void linkedInsertHead(Node** headPointer, ElType data);
// I.S. headPointer terdefinisi (sembarang), data terdefinisi.
// F.S. headPointer menunjuk ke data pertama.

// Menghapus elemen di head.
void linkedDeleteHead(Node** head);
// I.S. head terdefinisi.
// F.S. elemen head dihapus jika stack terisi.
//      mengeluarkan error message jika stack kosong.

void linkedInsertAt(Node** headPointer, int position, ElType data);
// I.S. headPointer terdefinisi dan terisi. position terdefinisi dan dalam range, data terdefinisi.
// F.S. headPointer menunjuk ke elemen selanjutnya sampai elemen posisi, elemen posisi menunjuk ke elemen selanjutnya.

void linkedDeleteAt(Node** headPointer, int position);
// I.S. headPointer terdefinisi dan terisi. position terdefinisi dan dalam range, data terdefinisi.
// F.S. headPointer menunjuk ke elemen selanjutnya sampai elemen posisi sebelumnya, elemen posisi sebelumnya menunjuk ke elemen posisi setelahnya.

#endif