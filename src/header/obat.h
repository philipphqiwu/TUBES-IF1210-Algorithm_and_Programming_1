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
    int indeksEmpty;
    int size;
    int capacity;
} ListObat;

// Menginisialisasi list obat dengan mengalokasikan memori secara dinamis
void createListObat(ListObat *list, int capacity);
// I.S. list terdefinisi dan sembarang, capacity terdefinisi
// F.S. Memori untuk list sudah teralokasikan, list.size bernilai 0, list.capacity bernilai capacity

// Mengupdate indeksEmpty pada indeks pertama ditemukan yang terisi NULL
void updateIndeksEmptyListObat(ListObat *list);
// I.S. list terdefinisi
// F.S. list.indeksEmpty terupdate menjadi nilai berupa indeks yang pertama memiliki nilai NULL

// Meningkatkan kapasitas list sebanyak 2 kalinya
void increaseCapacityListObat(ListObat *list);
// I.S. list terdefinisi
// F.S. memory tambahan teralokasi untuk list dan list.capacity = 2*list.capacity sebelumnya

// Menambahkan data obat pada indeks sesuai id
void insertObatByID(ListObat *list, int id, Obat item);
// I.S. list, id, dan item terdefinisi. list.items[id] bernilai NULL (kosong)
// F.S. list.items[id] terisi dengan data pada item

// Menghapus data obat pada indeks sesuai id
void deleteObat(ListObat *list, int id);
// I.S. list terdefinisi, list.items[id] tidak berniali NULL
// F.S. list.items[id] bernilai NULL

// Mengembalikan memori yang telah dialokasikan (digunakan saat list sudah tidak dipakai)
void freeListObat(ListObat *list);
// I.S. list terdefinisi
// F.S. Memori untuk list terdealokasikan, list.size dan list.capacity bernilai 0

#endif