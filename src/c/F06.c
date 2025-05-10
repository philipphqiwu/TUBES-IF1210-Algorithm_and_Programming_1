#include <stdio.h>
#include "../header/F06.h"

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
    getchar();
    char input[100];
    while (1) {
        printf("Masukkan kode ruangan yang ingin dilihat: ");
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

    int baris = -1, kolom = -1;
    
    char huruf = input[0];
    for (int i = 0; i < rumahsakit.roomRow; i++) {
        if (ruangan[i] == huruf) {
            baris = i;
            break;
        }
    }
    
    kolom = (int) input[1] - 48;
    
    if (baris == -1 || kolom < 0 || kolom >= rumahsakit.roomCol) {
        printf("Ruangan tidak ditemukan!\n");
        return;
    }
    
    int indeks = baris * rumahsakit.roomCol + kolom;
    
    printf("--- Detail Ruangan %s ---\n", input);
    printf("Kapasitas  : %d\n", rumahsakit.roomCapacity);
    
    int id_dokter = rumahsakit.room[indeks][0];
    if (id_dokter == 0) { 
        printf("Dokter     : -\n");
    } else {
        const char* nama_dokter = UserData.buffer[id_dokter].username; 
        printf("Dokter     : %s\n", nama_dokter ? nama_dokter : "-");
    }
    // asumsikan ada fungsi cari nama dokter dan cari nama pasien
    printf("Pasien di dalam ruangan:\n");
    int pasien_count = 0;
    for (int i = 1; i <= rumahsakit.roomCapacity; i++) { 
        int id_pasien = rumahsakit.room[indeks][i];
        if (id_pasien != 0) { 
            const char* nama_pasien = UserData.buffer[id_pasien].username;
            if (nama_pasien) {
                printf("  %d. %s\n", ++pasien_count, nama_pasien);
            }
        }
    }
    
    if (pasien_count == 0) {
        printf("  Tidak ada pasien di dalam ruangan saat ini.\n");
    }
    
    printf("------------------------------\n");
}