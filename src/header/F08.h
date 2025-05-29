#ifndef F08_H
#define F08_H
#include "user.h"
#include "colors.h"
#include "to-lower.h"
#include <stdio.h>

#include "F07.h"

// Menanyakan user pencarian berdasarkan id atau nama atau penyakit (bagi pasien)
void findBased(int * base, int type);
// I.S. base adalah 0 dan type terdefinisi
// F.S. base memiliki nilai berdasarkan jenis pencarian yang diinginkan

// Melakukan binary search untuk mencari index dengan id tertentu
int binSearchId(ListDinUser * UserData, int id);

// Melakukan sequential search untuk mencari index dengan username tertentu
int seqSearchName(ListDinUser * UserData, char * name);

// Menampilkan data dari pencarian id
void findId(ListDinUser * UserData, int type);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan data dari pencarian id

// Menampilkan data dari pencarian nama
void findName(ListDinUser * UserData, int type);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan data dari pencarian username

// Menampilkan list data dari pencarian penyakit
void tampilPenyakit(User *ptrs[], int base, int order, int length, char * penyakit);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan list data dari pencarian penyakit

// Menampilkan data dari pencarian penyakit
void findPenyakit(ListDinUser * UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan data dari pencarian penyakit

// Mencari data pengguna berdasarkan id atau nama
void cariUser(ListDinUser * UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan data pengguna berdasarkan query 

// Mencari data pasien berdasarkan id, nama, atau penyakit
void cariPasien(ListDinUser * UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan data pasien berdasarkan query 

// Mencari data dokter berdasarkan id atau nama
void cariDokter(ListDinUser * UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan data dokter berdasarkan query 

#endif