#include <stdio.h>
#include "config.h"
#include "user.h"

#include "../header/F06.h"

char ruangan[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};
void LIHAT_DENAH(Config rumahsakit) {

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

void LIHAT_RUANGAN(char koderuangan[2], Config rumahsakit, ListDinUser UserData) { 
  
    int baris = -1, kolom = -1;
    
    char huruf = koderuangan[0];
    for (int i = 0; i < rumahsakit.roomRow; i++) {
        if (ruangan[i] == huruf) {
            baris = i;
            break;
        }
    }
    
    kolom = atoi(koderuangan + 1) - 1;
    
    if (baris == -1 || kolom < 0 || kolom >= rumahsakit.roomCol) {
        printf("Ruangan tidak ditemukan!\n");
        return;
    }
    
    int indeks = baris * rumahsakit.roomCol + kolom;
    
    printf("--- Detail Ruangan %s ---\n", koderuangan);
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