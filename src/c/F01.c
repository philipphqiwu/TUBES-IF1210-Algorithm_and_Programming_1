#include "../header/F01.h"

void login(int * loginState, int * loginId, ListDinUser UserData){
    char Username[21];
    char Password[21];

    // Username input validation loop
    while (1) {
        printf("Username (max 20 characters): ");
        scanf("%21s", Username);
        printf(COLOR_RESET);
        if (strlen(Username) > 20) {
            printf(COLOR_RED"Error: Username melebihi 20 characters.\n"COLOR_RESET);
        } else {
            break;  
        }
    }
    // Password input validation loop
    while (1) {
        printf("Password (max 20 characters): ");
        scanf("%21s", Password);
        printf(COLOR_RESET);
        if (strlen(Password) > 20) {
            printf(COLOR_RED"Error: Password melebihi 20 characters.\n"COLOR_RESET);
        } else {
            break;
        }
    }

    int idxUsername = indexOfUsername(UserData, Username);
    if(idxUsername == -1){
        printf(COLOR_RED"Tidak ada user di database dengan username %s!\n"COLOR_RESET, Username);
    } else if(strcmp(UserData.buffer[idxUsername].password,Password) != 0){
        printf(COLOR_RED"Password yang dimasukkan salah!\n"COLOR_RESET);
    } else{
        *loginId = UserData.buffer[idxUsername].id;
        if(strcmp(UserData.buffer[idxUsername].role,"manager") == 0){
            printf(COLOR_MAGENTA"Halo Manager %s\n"COLOR_RESET, Username);
            *loginState = 1;
        } else if(strcmp(UserData.buffer[idxUsername].role,"dokter") == 0){
            printf(COLOR_CYAN"Halo Dokter %s\n"COLOR_RESET, Username);
            *loginState = 2;
        } else if(strcmp(UserData.buffer[idxUsername].role,"pasien") == 0){
            printf(COLOR_YELLOW"Halo %s! Ada keluhan apa?\n"COLOR_RESET, Username);
            *loginState = 3;
        }
    }

    return;
}

