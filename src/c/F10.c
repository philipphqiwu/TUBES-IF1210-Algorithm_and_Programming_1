#include "../header/F02.h"
#include "../header/set.h"

void tambahDokter(ListDinUser * UserData){
    char Username[21];
    char Password[21];
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

    Set setUsername;
    createSet(&setUsername,100);
    for(int i = 0; i < UserData->nEff; i++){
        setInsert(&setUsername, to_lower(UserData->buffer[i].username));
    }

    if(setContain(&setUsername, to_lower(Username))){
        printf("Penambahan dokter gagal! Sudah ada Dokter bernama %s!\n", Username);
    } else{
        printf("Dokter %s berhasil ditambahkan!\n", Username);        
        UserData->buffer[UserData->nEff].id = UserData->nEff+1;
        strcpy(UserData->buffer[UserData->nEff].username, Username);
        strcpy(UserData->buffer[UserData->nEff].password, Password);
        strcpy(UserData->buffer[UserData->nEff].role, "dokter");
        UserData->nEff += 1;
    }


    return;
}
