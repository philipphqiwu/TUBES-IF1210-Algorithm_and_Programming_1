#ifndef DENAH_H
#define DENAH_H
#include <stdio.h>

#define MAX_NAME_LENGTH 21

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

// Memasukan data ke dalam matriks sesuai letaknya
void insertMatrixByIndex(Matriks *matriks, int row, int col, int data);
// I.S. Semua argumen terdefinisi, matriks.contents[row][col] valid
// F.S. matriks.contents[row][col] terisi data. 
//      matriks.rows = row + 1 jika row >= matriks.rows
//      matriks.cols = col + 1 jika col >= matriks.cols

// Mengecek apakah matriks empty (ditandai dengan semua elemen bernilai 0)
int isMatriksEmpty(Matriks matriks);
// Mengembalikan 1 jika kosong, 0 jika tidak.

// mengembalikan banyak ruangan pada denah
int matriksSize(Matriks *arr);

#endif