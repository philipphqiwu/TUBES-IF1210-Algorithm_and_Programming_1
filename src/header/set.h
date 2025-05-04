#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef char SetElType[20];

typedef struct {
    SetElType *data;
    int nEff;
    int capacity;
} Set;

// I.S. s dan capacity terdefinisi
// F.S. Set s terbentuk dengan kapasitas capacity dan dapat diisi
void createSet(Set *s, int capacity);

// I.S. s terdefinisi
// F.S. kapaistas Set s menjadi 0 (tidak dapat diisi)
void freeSet(Set *s);

// mengecek apakah set memiliki elemen bernilai data. Mengembalikan 1 jika ada, 0 jika tidak.
int setContain(Set *s, SetElType data);

// I.S. data dan s terdefinisi
// F.S. data terdapat dalam set
void setInsert(Set *s, SetElType data);

// I.S. data dan s terdefinisi, ada data dalam set
// F.S. data hilang dari set
void setDelete(Set *s, SetElType data);

// mengembalikan banyak elemen dalam set
int setGetSize(Set *s);

// mengecek apakah set memiliki elemen bernilai data. Mengembalikan 1 jika ada, 0 jika tidak.
int setContain(Set *s, SetElType data);

#endif