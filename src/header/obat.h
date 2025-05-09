#ifndef OBAT_H
#define OBAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int obat_id;
    char nama_obat[20];
} Obat;

typedef struct{
    Obat *items;
    int nEff;
    int capacity;
} ListObat;

// Menginisialisasi list obat dengan mengalokasikan memori secara dinamis
void createListObat(ListObat *list, int capacity);
// I.S. list terdefinisi dan sembarang, capacity terdefinisi
// F.S. Memori untuk list sudah teralokasikan, list.size bernilai 0, list.capacity bernilai capacity

// Mencetak list obat
void printListObat(ListObat list);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: print */


// Menambahkan data obat di indeks terakhir
void insertObat(ListObat *list, Obat item);
// I.S. list dan item terdefinisi.
// F.S. list[nEff] terisi dengan data pada item dan nEff diinkremen 1

#endif