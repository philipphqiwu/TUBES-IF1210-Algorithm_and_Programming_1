#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/queue.h"
#include "../header/matriks-denah.h"

void initializeMatriksDenah(MatriksDenah *matriks){
    matriks->rows = 0;
    matriks->cols = 0;
    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            strcpy(matriks->contents[i][j].kodeRuangan, convertNumberToKodeRuangan(i, j));
            matriks->contents[i][j].dokterID = 0;
            matriks->contents[i][j].antrian = createQueue();
        }
    }
}

void freeMatriksDenah(MatriksDenah *matriks){
    matriks->rows = 0;
    matriks->cols = 0;
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
    char stringAngka[MAX_KODE_RUANG_LENGTH+1];
    snprintf(stringAngka, MAX_KODE_RUANG_LENGTH+2, "%d", cols+1);
    for(int i = 0; i < strlen(stringAngka); i++){
        output[indeksPut] = stringAngka[i];
        indeksPut++;
    }
    output[indeksPut] = '\0';

    return output;
}