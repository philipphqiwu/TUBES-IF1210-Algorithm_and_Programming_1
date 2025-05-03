#ifndef SET_H
#define SET_H
#include <stdio.h>

typedef char* ElType;

typedef struct {
    ElType data;
} Set;

void insertSet(Set *s, ElType data);
// I.S. data dan s terdefinisi, tidak ada data bernilai sama dalam set
// F.S. data terdapat dalam set

void deleteSet(Set *s, ElType data);
// I.S. data dan s terdefinisi, ada data dalam set
// F.S. data hilang dari set

int sizeSet(Set *s);
// mengembalikan banyak elemen dalam set

int containSet(Set *s, ElType data);
// mengecek apakah set memiliki elemen bernilai data. Mengembalikan 1 jika ada, 0 jika tidak. 

#endif