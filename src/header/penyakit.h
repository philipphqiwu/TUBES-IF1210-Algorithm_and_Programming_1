#ifndef PENYAKIT_H
#define PENYAKIT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nama_penyakit[50];
    float suhu_tubuh_min;
    float suhu_tubuh_max;
    int tekanan_darah_sistolik_min;
    int tekanan_darah_sistolik_max;
    int tekanan_darah_diastolik_min;
    int tekanan_darah_diastolik_max;
    int detak_jantung_min;
    int detak_jantung_max;
    float saturasi_oksigen_min;
    float saturasi_oksigen_max;
    int kadar_gula_darah_min;
    int kadar_gula_darah_max;
    float berat_badan_min;
    float berat_badan_max;
    int tinggi_badan_min;
    int tinggi_badan_max;
    int kadar_kolesterol_min;
    int kadar_kolesterol_max;
    int trombosit_min;
    int trombosit_max;
} Penyakit;

typedef struct{
    Penyakit *items;
    int nEff;
    int capacity;
} ListPenyakit;

// Menginisialisasi list penyakit dengan mengalokasikan memori secara dinamis
void createListPenyakit(ListPenyakit *list, int capacity);
// I.S. list terdefinisi dan sembarang, capacity terdefinisi
// F.S. Memori untuk list sudah teralokasikan, list.size bernilai 0, list.capacity bernilai capacity

// Mencetak list penyakit
void printListPenyakit(ListPenyakit list);
// I.S. l boleh kosong
// F.S. Jika l tidak kosong: print

// Menambahkan data penyakit di indeks terakhir, digunakan untuk penyakit tanpa id
void insertPenyakit(ListPenyakit *list, Penyakit item);
// I.S. list dan item terdefinisi. item.obat_id tidak bernilai (NULL)
// F.S. list[nEff] terisi dengan data pada item dan nEff diinkremen 1

// Menambahkan data obat berdasarkan id
void insertPenyakitByID(ListPenyakit *list, Penyakit item);
// I.S. list dan item terdefinisi. item.id bernilai dan dapat menjadi indeks yang valid
// F.S. list[item.id] terisi dengan data pada item
//      jika item.id >= l.nEff, maka l.nEff = item.id + 1

// Mencari ID penyakit berdasarkan nama, -1 jika tidak ditemukan.
int searchPenyakitIDByName(ListPenyakit list, char nama[]);
// Mengembalikan nilai -1 jika tidak menemukan penyakit dengan nama yang sesuai,
// Mengembalikan ID penyakit jika ditemukan penyakit dengan nama sesuai

// Mendealokasikan memori list penyakit
void freeListPenyakit(ListPenyakit *list);
// I.S. list terdefinisi dan sembarang
// F.S. Memori dalam list terdealokasi, list.nEff dan list.capacity bernilai 0

void writeListPenyakit(char * folderPath, ListPenyakit *list);
#endif