#include <stdlib.h>
#include "../header/matriks.h"

void freeMatriks(Matriks*arr){
    if (arr->contents != NULL){
        for (int i = 0; i < arr->rows; i++){
            if (arr->contents[i] != NULL){
                free(arr->contents[i]);
                arr->contents[i] = NULL;
            }
        }
        free(arr->contents);
        arr->contents = NULL;
    }
    arr ->rows = 0;
    arr ->cols = 0;
}

void initializeMatriks(Matriks *arr, int rows, int cols){
    // freeMatriks(arr);
    arr->rows = 0;
    arr->cols = 0;
    arr->contents = (int **)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++){
        arr->contents[i] = (int *)malloc(cols*sizeof(int));
        for(int j = 0; j < cols; j++){
            arr->contents[i][j] = 0;
        }
    }
}

void insertMatrixByIndex(Matriks *matriks, int row, int col, int data){
    matriks->contents[row][col] = data;
    if(row >= matriks->rows){
        matriks->rows = row+1;
    }
    if(col >= matriks->cols){
        matriks->cols = col+1;
    }
}

int isMatriksEmpty(Matriks matriks){
    if(matriks.rows == 0 || matriks.cols == 0){
        return 1;
    }
    for(int i = 0; i < matriks.rows; i++){
        for(int j = 0; j < matriks.cols; j++){
            if(matriks.contents[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int matriksSize(Matriks *arr){
    return arr->cols * arr->rows;
}