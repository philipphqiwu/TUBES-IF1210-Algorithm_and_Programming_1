#include "../header/F04.h"

void lupaPassword(ListDinUser * UserData){
    char Username[20];
    char KodeUnik[20];
    printf("Username: ");
    scanf("%s",Username);
    printf("KodeUnik: ");
    scanf("%s",KodeUnik);
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
            char NewPassword[20];
            scanf("%s",NewPassword);
            strcpy(UserData->buffer[idxUsername].password,NewPassword);
            printf("\n");
        } else{
            printf("Kode unik salah!\n");
        }
    }
    return;
}
