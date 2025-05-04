#ifndef DENAH_H
#define DENAH_H
#include <stdio.h>

#define MAX_NAME_LENGTH 20

typedef struct{
    int kapasitas;
    char dokter[MAX_NAME_LENGTH+1];
    char *pasien[];
} KontenDenah;

typedef struct{
    KontenDenah **ruang;
    int rows;
    int cols;
} MatriksDenah;

// I.S. matriks bertipe MatriksDenah (sembarang) terdefinisi, rows dan cols terdefinisi
// F.S. matriks berbentuk array 2D dengan ukuran rows x cols
void initializeMatriks(MatriksDenah *denah, int rows, int cols);

// mengembalikan banyak ruangan pada denah
int denahSize(MatriksDenah *denah);

#endif