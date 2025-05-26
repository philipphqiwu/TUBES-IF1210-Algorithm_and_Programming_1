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
        printf(COLOR_MAGENTA"Username (max 20 characters): ");
        scanf("%s", Username); 
        printf(COLOR_RESET);
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
        printf(COLOR_MAGENTA"Password (max 20 characters): ");
        scanf("%s", Password);
        printf(COLOR_RESET);
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
        printf(COLOR_RED"Penambahan dokter gagal! Sudah ada user bernama %s!\n"COLOR_RESET, Username);
    } else{
        printf(COLOR_MAGENTA"Dokter %s berhasil ditambahkan!\n"COLOR_RESET, Username);        
        UserData->buffer[UserData->nEff].id = UserData->buffer[UserData->nEff-1].id+1;
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
        printf(COLOR_MAGENTA"Username (max 20 characters): ");
        scanf("%s", Username); 
        printf(COLOR_RESET);
        if (strlen(Username) > 20) {
            printf(COLOR_RED"Error: Username melebihi 20 characters.\n"); 
        } else {
            break;
        }
    }

    // Validasi input ruangan
    getchar();
    char input[100];
    while (1) {
        printf(COLOR_MAGENTA"Ruangan: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        printf(COLOR_RESET);

        // Validasi: panjang harus 2, huruf kapital + digit angka
        if (strlen(input) == 2 &&
            input[0] >= 'A' && input[0] <= 'Z' &&
            input[1] >= '1' && input[1] <= '9'){
            break;
        } else {
            printf(COLOR_RED"Input tidak valid! Format harus 1 huruf kapital dan 1 angka (contoh: A1).\n\n");
        }
    }

    int baris = input[0] - 'A';
    int kolom = atoi(input + 1) - 1;
    
    int idx = -1;
    for(int i = 0; i < UserData->nEff; i++){
        if(strcmp(UserData->buffer[i].username,Username) == 0){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        printf(COLOR_RED"Tidak ada dokter bernama %s\n"COLOR_RESET, Username);
        return;
    }

    if (baris < 0 || kolom < 0 || kolom >= rumahsakit->denah.cols || baris >= rumahsakit->denah.rows) {
        printf(COLOR_RED"Ruangan tidak ditemukan!\n"COLOR_RESET);
        return;
    }

    if(strlen(UserData->buffer[idx].ruang) > 0){
        printf(COLOR_RED"Dokter %s sudah menempati ruangan %s\n"COLOR_RESET, Username, UserData->buffer[idx].ruang);
    }
    if(rumahsakit->denah.contents[baris][kolom].dokterID != 0){
        int idxOldDok = cariIdxUser(UserData, rumahsakit->denah.contents[baris][kolom].dokterID);
        printf(COLOR_RED"Ruangan %s sudah ditempati oleh Dokter %s\n"COLOR_RESET, input, UserData->buffer[idxOldDok].username);
    }

    if(strlen(UserData->buffer[idx].ruang) == 0 && rumahsakit->denah.contents[baris][kolom].dokterID == 0){
        printf(COLOR_BLUE"Dokter %s berhasil diassign ke ruangan %s\n"COLOR_RESET, Username, input);
        strcpy(UserData->buffer[idx].ruang, input);
        rumahsakit->denah.contents[baris][kolom].dokterID = UserData->buffer[idx].id;
    }
    
}