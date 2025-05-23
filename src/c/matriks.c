#include <stdlib.h>
#include "../header/matriks.h"

void initializeMatriks(Matriks *arr, int rows, int cols){
    freematriks(arr->contents);
    arr->rows = rows;
    arr->cols = cols;
    arr->contents = (int **)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows ; i++){
        arr->contents[i] = (int *)malloc(cols*sizeof(int));
    }

}
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

int denahSize(Matriks *arr){
    return arr->cols * arr->rows;
}