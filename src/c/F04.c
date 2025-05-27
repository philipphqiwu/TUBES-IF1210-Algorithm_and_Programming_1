#include "../header/F04.h"

void lupaPassword(ListDinUser * UserData){
    char uname[21];
    char KodeUnik[21];
    // Username input validation loop
    while (1) {
        printf(COLOR_GREEN"Username (max 20 characters): ");
        scanf("%s", uname);
        printf(COLOR_RESET);

        // Validasi username hanya huruf alfabet
        int isValid = 1;  // Flag to track if the username is valid
        for (int i = 0; i < strlen(uname); i++) {
            if((int)uname[i] < 65 || (int)uname[i] > 122 ||((int)uname[i]>90 && (int)uname[i]<97)){
                isValid = 0;  
                printf(COLOR_RED"Username hanya boleh terdiri atas huruf alfabet!\n"COLOR_RESET);
                break;
            }
        }

        if (strlen(uname) > 20) {
            printf(COLOR_RED"Error: Username melebihi 20 characters.\n"COLOR_RESET);
        } else if (!isValid) {
            continue; 
        } else {
            break;
        }
    }
    printf(COLOR_GREEN"KodeUnik: ");
    scanf("%20s",KodeUnik);
    printf("\n"COLOR_RESET);

    int idxUsername = indexOfUsername(*UserData, uname);
    if(idxUsername == -1){
        printf(COLOR_RED"Tidak ada user di database dengan username %s!\n"COLOR_RESET, uname);
    } else{
        char RLEKode[20];
        int RLEidx = 0;

        for(int i = 0; i < strlen(uname); i++){
            char currentChar = uname[i];
            int count = 1;

            while (i + 1 < strlen(uname) && uname[i + 1] == currentChar) {
                count++;
                i++;
            }

            if (count > 1) {
                RLEidx += sprintf(&RLEKode[RLEidx], "%d", count);
            }
            RLEKode[RLEidx++] = currentChar;
        }
        RLEKode[RLEidx] = '\0';

        if(strcmp(KodeUnik,RLEKode)==0){
            if(strcmp(UserData->buffer[idxUsername].role,"manager") == 0){
                printf(COLOR_MAGENTA"Halo Manager %s\n"COLOR_RESET, uname);
            } else if(strcmp(UserData->buffer[idxUsername].role,"dokter") == 0){
                printf(COLOR_CYAN"Halo Dokter %s\n"COLOR_RESET, uname);
            } else if(strcmp(UserData->buffer[idxUsername].role,"pasien") == 0){
                printf(COLOR_YELLOW"Halo %s! Ada keluhan apa?\n"COLOR_RESET, uname);
            }
            printf(COLOR_GREEN"Password Baru: ");
            char NewPassword[21];
            scanf("%s",NewPassword);
            strcpy(UserData->buffer[idxUsername].password,NewPassword);
            printf("\n"COLOR_RESET);
        } else{
            printf(COLOR_RED"Kode unik salah!\n"COLOR_RESET);
        }
    }
    return;
}
