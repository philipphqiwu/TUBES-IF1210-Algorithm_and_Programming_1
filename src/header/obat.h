#ifndef OBAT_H
#define OBAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMA_OBAT 21

typedef struct{
    int obat_id;
    char nama_obat[MAX_NAMA_OBAT];
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
// I.S. l boleh kosong
// F.S. Jika l tidak kosong: print

// Menambahkan data obat di indeks terakhir, digunakan untuk obat tanpa id
void insertObat(ListObat *list, Obat item);
// I.S. list dan item terdefinisi. item.obat_id tidak bernilai (NULL)
// F.S. list[nEff] terisi dengan data pada item dan nEff diinkremen 1

// Menambahkan data obat berdasarkan id
void insertObatByID(ListObat *list, Obat item);
// I.S. list dan item terdefinisi. item.obat_id bernilai dan dapat menjadi indeks yang valid
// F.S. list[item.obat_id] terisi dengan data pada item
//      jika item.obat_id >= l.nEff, maka l.nEff = item.obat_id + 1

// Mendealokasikan memori list obat
void freeListObat(ListObat *list);
// I.S. list terdefinisi dan sembarang
// F.S. Memori dalam list terdealokasi, list.nEff dan list.capacity bernilai 0

// Menyortir List obat berdasarkan id
void sortObat(ListObat *l);
// I.S. list terdefinisi
// F.S. list tersortir ascending menurut id

// Mengembalikan indeks obat dengan id tertentu
int cariIdxObat(ListObat * list, int id);

// Menuliskan List obat ke dalam file
void writeListObat(char * folderPath, ListObat *list);
// I.S. list terdefinisi dan terisi
// F.S. File obat.csv berada pada folder yang ditujukan

#endif