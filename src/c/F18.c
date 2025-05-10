#include "../header/F18.h"
#include <stdio.h>

void EXIT(){
    char konfirmasi;
    do{
        printf("Apakah Anda mau melakukan penyimpanan file yang sudah diubah? (y/n) ");
        scanf("%c", &konfirmasi);
        printf("\n");
    }while(konfirmasi != 'y' || konfirmasi != 'n');
    if (konfirmasi == 'y'){
        // SAVE();
    }
}
