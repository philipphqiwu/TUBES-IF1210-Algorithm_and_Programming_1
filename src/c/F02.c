#include "../header/F02.h"
#include "../header/set.h"

void registerPasien(ListDinUser * UserData){
    char Username[21];
    char Password[21];
    // Username input validation loop
    while (1) {
        printf(COLOR_GREEN"Username (max 20 characters): "COLOR_RESET);
        scanf("%s", Username); 

        // Validasi username hanya huruf alfabet
        int isValid = 1;  // Flag to track if the username is valid
        for (int i = 0; i < strlen(Username); i++) {
            if((int)Username[i] < 65 || (int)Username[i] > 122 ||((int)Username[i]>90 && (int)Username[i]<97)){
                isValid = 0;  
                printf(COLOR_RED"Username hanya boleh terdiri atas huruf alfabet!\n"COLOR_RESET);
                break;
            }
        }

        if (strlen(Username) > 20) {
            printf(COLOR_RED"Error: Username melebihi 20 characters.\n"COLOR_RESET);
        } else if (!isValid) {
            continue; 
        } else {
            break;
        }
    }

    // Password input validation loop
    while (1) {
        printf(COLOR_GREEN"Password (max 20 characters): "COLOR_RESET);
        scanf("%s", Password);
        if (strlen(Password) > 20) {
            printf(COLOR_RED"Error: Password melebihi 20 characters.\n"COLOR_RESET);
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
        printf(COLOR_RED"Registrasi gagal! User dengan nama %s sudah terdaftar.\n"COLOR_RESET, Username);
    } else{
        printf(COLOR_BLUE"Pasien %s berhasil ditambahkan!\n"COLOR_RESET, Username);
        UserData->buffer[UserData->nEff] = createEmptyUser();        
        UserData->buffer[UserData->nEff].id = UserData->buffer[UserData->nEff-1].id+1;
        strcpy(UserData->buffer[UserData->nEff].username, Username);
        strcpy(UserData->buffer[UserData->nEff].password, Password);
        strcpy(UserData->buffer[UserData->nEff].role, "pasien");
        UserData->buffer[UserData->nEff].ruang[0] = '\0';
        UserData->buffer[UserData->nEff].antrian[0] = '\0';
        UserData->nEff += 1;
    }

    return;
}
