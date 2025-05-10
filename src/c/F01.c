#include "../header/F01.h"

void login(int * loginState, int * loginId, ListDinUser UserData){
    char Username[21];
    char Password[21];

    // Username input validation loop
    while (1) {
        printf("Username (max 20 characters): ");
        scanf("%s", Username);

        if (strlen(Username) > 20) {
            printf("Error: Username melebihi 20 characters.\n");
        } else {
            break;  
        }
    }
    // Password input validation loop
    while (1) {
        printf("Password (max 20 characters): ");
        scanf("%s", Password);
        if (strlen(Password) > 20) {
            printf("Error: Password melebihi 20 characters.\n");
        } else {
            break;
        }
    }

    int idxUsername = indexOfUsername(UserData, Username);
    if(idxUsername == -1){
        printf("Tidak ada user di database dengan username %s!\n", Username);
    } else if(strcmp(UserData.buffer[idxUsername].password,Password) != 0){
        printf("Password yang dimasukkan salah!\n");
    } else{
        *loginId = idxUsername+1;
        if(strcmp(UserData.buffer[idxUsername].role,"manager") == 0){
            printf("Halo Manager %s\n", Username);
            *loginState = 1;
        } else if(strcmp(UserData.buffer[idxUsername].role,"dokter") == 0){
            printf("Halo Dokter %s\n", Username);
            *loginState = 2;
        } else if(strcmp(UserData.buffer[idxUsername].role,"pasien") == 0){
            printf("Halo %s! Ada keluhan apa?\n", Username);
            *loginState = 3;
        }
    }

    return;
}

