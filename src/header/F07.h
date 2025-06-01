#ifndef F07_H
#define F07_H
#include "user.h"
#include "colors.h"
#include "to-lower.h"
#include <string.h>
#include <stdio.h>

// Menanyakan user sort berdasarkan id atau nama dan urutan sort
void sortBased(int * base, int * order, int type);
// I.S. base dan order masih 0
// F.S. base dan order memiliki nilai berdasarkan jenis sort yang diinginkan

// Melakukan sort berdasarkan nama/alfabet
void alphabetSort(User *ptrs[], int length);
// I.S. Seluruh argumen terdefinisi
// F.S. Pointers-pointers ptrs disortir berdasarkan alfabet

// Melakukan sort berdasarkan aura
void auraSort(User *ptrs[], int length);
// I.S. Seluruh argumen terdefinisi
// F.S. Pointers-pointers ptrs disortir berdasarkan aura

// Menampilkan list berdasarkan jenis pengurutan
void tampilList(User *ptrs[], int type, int base, int order, int length);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan list berdasarkan jenis pengurutan yang diberikan user

// Melihat data seluruh pengguna
void lihatUser(ListDinUser UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan list pengguna berdasarkan jenis pengurutan yang diberikan user

// Melihat data seluruh pasien
void lihatPasien(ListDinUser UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan list pasien berdasarkan jenis pengurutan yang diberikan user

// Melihat data seluruh dokter
void lihatDokter(ListDinUser UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan list dokter berdasarkan jenis pengurutan yang diberikan user

#endif