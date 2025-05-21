#ifndef DENAH_H
#define DENAH_H
#include <stdio.h>

#define MAX_NAME_LENGTH 20

// typedef struct{
//     int kapasitas;
//     char dokter[MAX_NAME_LENGTH+1];
//     char *pasien[];
// } KontenDenah;

typedef struct{
    int **contents;
    int rows;
    int cols;
} Matriks;

// I.S. matriks bertipe MatriksDenah (sembarang) terdefinisi, rows dan cols terdefinisi
// F.S. matriks berbentuk array 2D dengan ukuran rows x cols
void initializeMatriks(Matriks *arr, int rows, int cols);

void freeMatriks(Matriks *arr);

// mengembalikan banyak ruangan pada denah
int matriksSize(Matriks *arr);

#endif