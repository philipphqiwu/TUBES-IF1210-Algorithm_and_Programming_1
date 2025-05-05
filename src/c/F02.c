#include "../header/F02.h"
#include "../header/set.h"

void registerPasien(ListDinUser * UserData){
    char Username[20];
    char Password[20];
    printf("Username: ");
    scanf("%s",Username);
    printf("Password: ");
    scanf("%s",Password);
    printf("\n");

    // Validasi username hanya huruf alfabet
    for(int i = 0; i < strlen(Username); i++){
        if((int)Username[i] < 65 || (int)Username[i] > 122 ||((int)Username[i]>90 && (int)Username[i]<97)){
            printf("Username hanya boleh terdiri atas huruf alfabet!\n");
            return;
        }
    }

    Set setUsername;
    createSet(&setUsername,100);
    for(int i = 0; i < UserData->nEff; i++){
        setInsert(&setUsername, to_lower(UserData->buffer[i].username));
    }

    if(setContain(&setUsername, to_lower(Username))){
        printf("Registrasi gagal! Pasien dengan nama %s sudah terdaftar.\n", Username);
    } else{
        printf("Pasien %s berhasil ditambahkan!\n", Username);        
        UserData->buffer[UserData->nEff].id = UserData->nEff+1;
        strcpy(UserData->buffer[UserData->nEff].username, Username);
        strcpy(UserData->buffer[UserData->nEff].password, Password);
        strcpy(UserData->buffer[UserData->nEff].role, "pasien");
        UserData->nEff += 1;
    }


    return;
}
