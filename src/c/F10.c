#include "../header/F10.h"
#include "../header/set.h"

char ruangann[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};

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
        UserData->buffer[UserData->nEff].ruang[0] = '\0';
        UserData->nEff += 1;
    }
    return;
}

void assignDokter(ListDinUser * UserData, Config * rumahsakit){
    char Username[21];
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

    // Validasi input ruangan
    getchar();
    char input[100];
    while (1) {
        printf("Ruangan: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // Validasi: panjang harus 2, huruf kapital + digit angka
        if (strlen(input) == 2 &&
            input[0] >= 'A' && input[0] <= 'Z' &&
            input[1] >= '1' && input[1] <= '9'){
            break;
        } else {
            printf("Input tidak valid! Format harus 1 huruf kapital dan 1 angka (contoh: A1).\n\n");
        }
    }

    int baris = input[0] - 'A';
    int kolom = atoi(input + 1) - 1;
    int indeks = baris * rumahsakit->roomCol + kolom;
    
    int idx = -1;
    for(int i = 0; i < UserData->nEff; i++){
        if(strcmp(UserData->buffer[i].username,Username) == 0){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        printf("Tidak ada dokter bernama %s\n", Username);
        return;
    }

    if (baris < 0 || kolom < 0 || kolom >= rumahsakit->roomCol || baris >= rumahsakit->roomRow) {
        printf("Ruangan tidak ditemukan!\n");
        return;
    }

    if(strlen(UserData->buffer[idx].ruang) > 0){
        printf("Dokter %s sudah menempati ruangan %s\n", Username, UserData->buffer[idx].ruang);
    }
    if(rumahsakit->room[indeks][0] != -1){
        printf("Ruangan %s sudah ditempati oleh Dokter %s\n", input, UserData->buffer[rumahsakit->room[indeks][0]].username);
    }

    if(strlen(UserData->buffer[idx].ruang) == 0 &&
        rumahsakit->room[indeks][0] == -1){
        printf("Dokter %s berhasil diassign ke ruangan %s\n", Username, input);
        strcpy(UserData->buffer[idx].ruang, input);
        rumahsakit->room[indeks][0] = idx;
    }

}