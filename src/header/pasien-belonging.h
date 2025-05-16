#ifndef PASIEN_BELONGING_H
#define PASIEN_BELONGING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVENTORY_CAP 20
#define PERUT_CAP 20

typedef struct{
    int pasienID;
    int inventory[INVENTORY_CAP];
    int perut[PERUT_CAP];
} PasienBelonging;

typedef struct{
    PasienBelonging *items;
    int nEff;
    int capacity;
} ListPasienBelonging;

// Menginisialisasi list PasienBelonging dengan mengalokasikan memori secara dinamis
void createListPasienBelonging(ListPasienBelonging *list, int capacity);
// I.S. list terdefinisi dan sembarang, capacity terdefinisi
// F.S. Memori untuk list sudah teralokasikan, list.size bernilai 0, list.capacity bernilai capacity

// Mencetak list PasienBelonging
void printListPasienBelonging(ListPasienBelonging list);
// I.S. l boleh kosong
// F.S. Jika l tidak kosong: print

// Menambahkan data PasienBelonging di indeks terakhir, digunakan untuk PasienBelonging tanpa id
void insertPasienBelonging(ListPasienBelonging *list, PasienBelonging item);
// I.S. list dan item terdefinisi. item.PasienBelonging_id tidak bernilai (NULL)
// F.S. list[nEff] terisi dengan data pada item dan nEff diinkremen 1

// Menambahkan data PasienBelonging berdasarkan id
void insertPasienBelongingByID(ListPasienBelonging *list, PasienBelonging item);
// I.S. list dan item terdefinisi. item.PasienBelonging_id bernilai dan dapat menjadi indeks yang valid
// F.S. list[item.PasienBelonging_id] terisi dengan data pada item
//      jika item.PasienBelonging_id >= l.nEff, maka l.nEff = item.PasienBelonging_id + 1

// Mendealokasikan memori list PasienBelonging
void freeListPasienBelonging(ListPasienBelonging *list);
// I.S. list terdefinisi dan sembarang
// F.S. Memori dalam list terdealokasi, list.nEff dan list.capacity bernilai 0

#endif