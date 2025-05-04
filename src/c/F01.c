#include "../header/F01.h"

void login(int * loginState, int * loginId, ListDinUser UserData){
    char Username[20];
    char Password[20];
    printf("Username: ");
    scanf("%s",Username);
    printf("Password: ");
    scanf("%s",Password);

    int idxUsername = indexOfUsername(UserData, Username);
    if(idxUsername == -1){
        printf("Tidak ada user di database dengan username %s!\n", Username);
    } else if(strcmp(UserData.buffer[idxUsername].password,Password) != 0){
        printf("Password yang dimasukkan salah!");
    } else{
        *loginId = idxUsername+1;
        if(strcmp(UserData.buffer[idxUsername].role,"manager")){
            printf("Halo Manager %s\n", Username);
            *loginState = 1;
        } else if(strcmp(UserData.buffer[idxUsername].role,"dokter")){
            printf("Halo Dokter %s\n", Username);
            *loginState = 2;
        } else if(strcmp(UserData.buffer[idxUsername].role,"pasien")){
            printf("Halo %s! Ada keluhan apa?\n", Username);
            *loginState = 3;
        }
    }

    return;
}

