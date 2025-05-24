#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/queue.h"
#include "../header/matriks-denah.h"

void initializeMatriksDenah(MatriksDenah *matriks, int rows, int cols, int kapasitasRuangan, int kapasitasAntrian){
    matriks->rows = rows;
    matriks->cols = cols;
    matriks->contents = (KontenDenah**)malloc(rows * sizeof(KontenDenah*));
    for(int i = 0; i < rows; i++){
        matriks->contents[i] = (KontenDenah*)malloc(cols * sizeof(KontenDenah));
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; i < cols; i++){
            strcpy(matriks->contents[i][j].kodeRuangan, convertNumberToKodeRuangan(i, j));
            matriks->contents[i][j].dokterID = 0;
            matriks->contents[i][j].pasienID = (int*)malloc(kapasitasRuangan * sizeof(int));
            for(int p = 0; p < kapasitasRuangan; p++){
                matriks->contents[i][j].pasienID[p] = 0;
            }
            matriks->contents[i][j].antrian = createQueue();
        }
    }
}

void freeMatriksDenah(MatriksDenah *matriks){
    for(int i = 0; i < matriks->rows; i++){
        for(int j = 0; j < matriks->cols; j++){
            free(matriks->contents[i][j].pasienID);
        }
        free(matriks->contents[i]);
    }
    free(matriks->contents);
}

char* convertNumberToKodeRuangan(int rows, int cols){
    char *output = (char*)malloc(MAX_KODE_RUANG_LENGTH * sizeof(char));
    int indeksPut = 0;
    int banyakHuruf = 1;
    int pangkat = 26;
    while(pangkat <= rows){
        banyakHuruf++;
        pangkat *= 26;
    }
    for(int i = banyakHuruf; i > 0; i--){
        pangkat /= 26;
        output[indeksPut] = (char) rows/pangkat + 'A';
        if(i != 1){
            output[indeksPut]--;
        }
        rows = rows%pangkat;
        indeksPut++;
    }
    char stringAngka[MAX_KODE_RUANG_LENGTH];
    sprintf(stringAngka, "%d", cols+1);
    for(int i = 0; i < strlen(stringAngka); i++){
        output[indeksPut] = stringAngka[i];
        indeksPut++;
    }
    output[indeksPut] = '\0';

    return output;
}