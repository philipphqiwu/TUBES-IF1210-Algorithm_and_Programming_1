#include <stdio.h>
#include "../header/config.h"
#include "../header/user.h"
#include "../header/F06.h"
#include <stdio.h>
#include "../header/config.h"
#include "../header/user.h"
#include "../header/F06.h"

const char* cari_username(ListDinUser UserData, int idPasien) {
    int idxUser = cariIdxUser(&UserData, idPasien);
    if (idPasien == 1){
        printf("kayaknya pasiennya gaada\n");
        printf("%d\n", idxUser);
    }
    
    
    if (idxUser == -1) {
        return "-";
    }
    
    return UserData.buffer[idxUser].username;
}

char ruangan[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};


void lihatDenah(Config rumahsakit) {

    printf("    ");
    for(int j = 0; j < rumahsakit.denah.cols; j++) {
        printf("  %d  ", j+1);
    }
    printf("\n");

    printf("   +");
    for(int j = 0; j < rumahsakit.denah.cols; j++) {
        printf("-----+");
    }
    printf("\n");


    for(int i = 0; i < rumahsakit.denah.rows; i++) {

        printf(" %c |", ruangan[i]);
        for(int j = 0; j < rumahsakit.denah.cols; j++) {
             printf(" %c%-2d |", ruangan[i], j+1); 
        }
        printf("\n");


        printf("   +");
        for(int j = 0; j < rumahsakit.denah.cols; j++) {
            printf("-----+");
        }
        printf("\n");
        }
}


void lihatRuangan(Config rumahsakit, ListDinUser UserData) {
    char kodeRuangan[100];
    // Validasi input ruangan
    getchar();
    while (1) {
        printf("Ruangan: ");
        fgets(kodeRuangan, sizeof(kodeRuangan), stdin);
        kodeRuangan[strcspn(kodeRuangan, "\n")] = '\0';

        // Validasi: panjang harus 2, huruf kapital + digit angka
        if (strlen(kodeRuangan) == 2 &&
            kodeRuangan[0] >= 'A' && kodeRuangan[0] <= 'Z' &&
            kodeRuangan[1] >= '1' && kodeRuangan[1] <= '9'){
            break;
        } else {
            printf("Input tidak valid! Format harus 1 huruf kapital dan 1 angka (contoh: A1).\n\n");
        }
    }

    int baris = kodeRuangan[0] - 'A';
    int kolom = atoi(kodeRuangan + 1) - 1;

    
    if (baris < 0 || kolom < 0 || kolom >= rumahsakit.denah.cols || baris >= rumahsakit.denah.rows) {
        printf("Ruangan tidak ditemukan!\n");
        return;
    }

    printf("\n--- Detail Ruangan %s ---\n", kodeRuangan);
    printf("Kapasitas  : %d\n", rumahsakit.kapasitasRuangan);
    

    int idDokter = rumahsakit.denah.contents[baris][kolom].dokterID;
    printf("Dokter     : %s\n", (idDokter == 0) ? "-" : cari_username(UserData, idDokter+1));
    printf("Dokter     : %s\n", (idDokter == 0) ? "-" : cari_username(UserData, idDokter));
    
    int id_pasien;

    char *adadokter = cari_username(UserData, idDokter);
   
    while (temp != NULL && pasienCount < rumahsakit.kapasitasRuangan &&  strcmp(adadokter, "-") != 0)
    {
        id_pasien = temp->data;
        

       if (id_pasien != 0) {
            printf("  %d. %s\n", ++pasienCount, cari_username(UserData, id_pasien));
        }

        temp = temp->next;
    }

    if (pasienCount == 0) printf("  Tidak ada pasien\n");
    printf("------------------------------\n");
}