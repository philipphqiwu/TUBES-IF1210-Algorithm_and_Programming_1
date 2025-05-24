#ifndef MATRIKS_DENAH_H
#define MATRIKS_DENAH_H
#include <stdio.h>
#include "queue.h"

#define MAX_KODE_RUANG_LENGTH 10

typedef struct{
    char kodeRuangan[MAX_KODE_RUANG_LENGTH];
    int dokterID;
    int *pasienID;
    Queue *antrian;
} KontenDenah;

typedef struct{
    KontenDenah **contents;
    int rows;
    int cols;
} MatriksDenah;

// I.S. matriks bertipe MatriksDenah (sembarang) terdefinisi, rows dan cols terdefinisi
// F.S. matriks berbentuk array 2D dengan ukuran rows x cols
void initializeMatriksDenah(MatriksDenah *matriks, int rows, int cols, int kapasitasRuangan, int kapasitasAntrian);

void freeMatriksDenah(MatriksDenah *matriks);

char* convertNumberToKodeRuangan(int rows, int cols);

#endif