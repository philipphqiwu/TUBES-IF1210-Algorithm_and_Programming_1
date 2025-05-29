#include "../header/F03.h"

void logout(int * loginState, int * loginId){
    if(*loginState == 0){
        printf(COLOR_RED"Logout gagal!\n");
        printf("Anda belum login, silahkan login terlebih dahulu sebelum melakukan logout\n"COLOR_RESET);
    } else{
        *loginState = 0;
        *loginId = -1;
        printf(COLOR_BLUE"\nSampai Jumpa\n"COLOR_RESET);
    }
    return;
}

