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
        char RLEUsername[20];
        int RLEidx = 0;
        for(int i = 0; i < strlen(KodeUnik); i++){
            if((int) KodeUnik[i] >= 50 && (int) KodeUnik[i] <= 57){
                for(int j = 0; j < (int) KodeUnik[i] - 48; j++){
                    RLEUsername[RLEidx] = KodeUnik[i+1];
                    RLEidx++;
                }
                i++;
            } else{
                RLEUsername[RLEidx] = KodeUnik[i];
                RLEidx++;
            }
        }
        RLEUsername[RLEidx] = '\0';

        if(strcmp(to_lower(Username),to_lower(RLEUsername))==0){
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
