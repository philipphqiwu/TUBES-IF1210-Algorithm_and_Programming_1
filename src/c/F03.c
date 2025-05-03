#include "../header/F03.h"

void logout(int * loginState, int * loginId){
    if(*loginState == 0){
        printf("Logout gagal!\n");
        printf("Anda belum login, silahkan login terlebih dahulu sebelum melakukan logout\n");
    } else{
        *loginState = 0;
        *loginId = -1;
        printf("\nSampai Jumpa\n");
    }
    return;
}

