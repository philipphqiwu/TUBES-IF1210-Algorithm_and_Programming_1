#include <stdio.h>
#include "../header/config.h"
#include "../header/user.h"
#include "../header/F06.h"

const char* cari_username(ListDinUser UserData, int id) {
    for (int i = 0; i < UserData.nEff; i++) {
        if (UserData.buffer[i].id == id) {
            return UserData.buffer[i].username;
        }
    }
    return "-";
}

char ruangan[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};

void lihatDenah(Config rumahsakit) {

    printf("    ");
    for(int j = 0; j < rumahsakit.roomCol; j++) {
        printf("  %d  ", j+1);
    }
    printf("\n");

    printf("   +");
    for(int j = 0; j < rumahsakit.roomCol; j++) {
        printf("-----+");
    }
    printf("\n");


    for(int i = 0; i < rumahsakit.roomRow; i++) {

        printf(" %c |", ruangan[i]);
        for(int j = 0; j < rumahsakit.roomCol; j++) {
             printf(" %c%-2d |", ruangan[i], j+1); 
        }
        printf("\n");


        printf("   +");
        for(int j = 0; j < rumahsakit.roomCol; j++) {
            printf("-----+");
        }
        printf("\n");
        }
}


void lihatRuangan(Config rumahsakit, ListDinUser UserData) {
    char koderuangan[100];
        // Validasi input ruangan
    getchar();
    while (1) {
        printf("Ruangan: ");
        fgets(koderuangan, sizeof(koderuangan), stdin);
        koderuangan[strcspn(koderuangan, "\n")] = '\0';

        // Validasi: panjang harus 2, huruf kapital + digit angka
        if (strlen(koderuangan) == 2 &&
            koderuangan[0] >= 'A' && koderuangan[0] <= 'Z' &&
            koderuangan[1] >= '1' && koderuangan[1] <= '9'){
            break;
        } else {
            printf("Input tidak valid! Format harus 1 huruf kapital dan 1 angka (contoh: A1).\n\n");
        }
    }



    int baris = koderuangan[0] - 'A';
    int kolom = atoi(koderuangan + 1) - 1;
    int indeks = baris * rumahsakit.roomCol + kolom;

    
    if (baris < 0 || kolom < 0 || kolom >= rumahsakit.roomCol || baris >= rumahsakit.roomRow) {
        printf("Ruangan tidak ditemukan!\n");
        return;
    }

    printf("\n--- Detail Ruangan %s ---\n", koderuangan);
    printf("Kapasitas  : %d\n", rumahsakit.roomCapacity);
    

    int id_dokter = rumahsakit.room[indeks][0];
    printf("Dokter     : %s\n", (id_dokter == 0) ? "-" : cari_username(UserData, id_dokter+1));

    printf("Pasien di dalam ruangan:\n");
    int pasien_count = 0;
    for (int i = 1; i <= rumahsakit.roomCapacity; i++) {
        int id_pasien = rumahsakit.room[indeks][i];
        if (id_pasien != 0) {
            printf("  %d. %s\n", ++pasien_count, cari_username(UserData, id_pasien+1));
        }
    }
    if (pasien_count == 0) printf("  Tidak ada pasien\n");
    printf("------------------------------\n");
}