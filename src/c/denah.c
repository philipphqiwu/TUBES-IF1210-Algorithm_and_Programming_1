#include <stdlib.h>
#include "../header/denah.h"

void initializeMatriks(MatriksDenah *denah, int rows, int cols){
    denah->ruang = (KontenDenah **)malloc(rows * sizeof(KontenDenah *));
    for(int i = 0; i < rows; i++){
        denah->ruang[i] = (KontenDenah *)malloc(cols *sizeof(KontenDenah));
    }
    denah->rows = rows;
    denah->cols = cols;
}

int denahSize(MatriksDenah *denah){
    return denah->rows * denah->cols;
}