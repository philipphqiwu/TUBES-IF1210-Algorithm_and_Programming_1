#include "../header/F04.h"

void lupaPassword(ListDinUser * UserData){
    char Username[21];
    char KodeUnik[21];
    // Username input validation loop
    while (1) {
        printf("Username (max 20 characters): ");
        scanf("%s", Username);

        // Validasi username hanya huruf alfabet
        int isValid = 1;  // Flag to track if the username is valid
        for (int i = 0; i < strlen(Username); i++) {
            if((int)Username[i] < 65 || (int)Username[i] > 122 ||((int)Username[i]>90 && (int)Username[i]<97)){
                isValid = 0;  
                printf("Username hanya boleh terdiri atas huruf alfabet!\n");
                break;
            }
        }

        if (strlen(Username) > 20) {
            printf("Error: Username melebihi 20 characters.\n");
        } else if (!isValid) {
            continue; 
        } else {
            break;
        }
    }
    printf("KodeUnik: ");
    scanf("%20s",KodeUnik);
    printf("\n");

    int idxUsername = indexOfUsername(*UserData, Username);
    if(idxUsername == -1){
        printf("Tidak ada user di database dengan username %s!\n", Username);
    } else{
        char RLEKode[20];
        int RLEidx = 0;
        char* uname = to_lower(Username);

        for(int i = 0; i < strlen(Username); i++){
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

        if(strcmp(to_lower(KodeUnik),to_lower(RLEKode))==0){
            if(strcmp(UserData->buffer[idxUsername].role,"manager") == 0){
                printf("Halo Manager %s\n", Username);
            } else if(strcmp(UserData->buffer[idxUsername].role,"dokter") == 0){
                printf("Halo Dokter %s\n", Username);
            } else if(strcmp(UserData->buffer[idxUsername].role,"pasien") == 0){
                printf("Halo %s! Ada keluhan apa?\n", Username);
            }
            printf("Password Baru: ");
            char NewPassword[21];
            scanf("%s",NewPassword);
            strcpy(UserData->buffer[idxUsername].password,NewPassword);
            printf("\n");
        } else{
            printf("Kode unik salah!\n");
        }
    }
    return;
}
