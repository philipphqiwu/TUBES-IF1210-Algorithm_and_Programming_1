#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef char* ElType;

typedef struct {
    ElType *data;
    int nEff;
    int capacity;
} Set;

void createSet(Set *s, int capacity);
// I.S. s dan capacity terdefinisi
// F.S. Set s terbentuk dengan kapasitas capacity dan dapat diisi

void freeSet(Set *s);
// I.S. s terdefinisi
// F.S. kapaistas Set s menjadi 0 (tidak dapat diisi)

int setContain(Set *s, ElType data);
// mengecek apakah set memiliki elemen bernilai data. Mengembalikan 1 jika ada, 0 jika tidak. 

void setInsert(Set *s, ElType data);
// I.S. data dan s terdefinisi
// F.S. data terdapat dalam set

void setDelete(Set *s, ElType data);
// I.S. data dan s terdefinisi, ada data dalam set
// F.S. data hilang dari set

int setSize(Set *s);
// mengembalikan banyak elemen dalam set

int setContain(Set *s, ElType data);
// mengecek apakah set memiliki elemen bernilai data. Mengembalikan 1 jika ada, 0 jika tidak. 

#endif