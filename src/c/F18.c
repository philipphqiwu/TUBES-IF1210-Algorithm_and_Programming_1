#include "../header/F18.h"

void EXIT(){
    char konfirmasi;
    do{
        printf("Apakah Anda mau melakukan penyimpanan file yang sudah diubah? (y/n) ");
        scanf("%d", &konfirmasi);
        printf("\n");
    }while(konfirmasi != 'y' || konfirmasi != 'n');
    if (konfirmasi == 'y'){
        SAVE();
    }
}
