#include <stdio.h>
#include "../header/config.h"
#include "../header/user.h"
#include "../header/F06.h"
#include <stdio.h>
#include "../header/config.h"
#include "../header/user.h"
#include "../header/F06.h"


// mencari nama pasien dalam ruangan
const char* cariUsername(ListDinUser UserData, int idPasien) {
    int idxUser = cariIdxUser(&UserData, idPasien);
    if (idxUser == -1) {
        return "-";
    }
    return UserData.buffer[idxUser].username;
}

char ruangan[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};


void lihatDenah(Config rumahsakit) {
    // print bagian pertama dari ruangan
    printf("    ");
    // print banyak kolom
    for(int j = 0; j < rumahsakit.denah.cols; j++) {
        printf("  %d  ", j+1);
    }
    printf("\n");
    // Print gari pertama dalam dneah
    printf("   +");
    for(int j = 0; j < rumahsakit.denah.cols; j++) {
        printf("-----+");
    }
    printf("\n");


    for(int i = 0; i < rumahsakit.denah.rows; i++) {
        // print baris dan kolomnya
        printf(" %c |", ruangan[i]);
        for(int j = 0; j < rumahsakit.denah.cols; j++) {
             printf(" %c%-2d |", ruangan[i], j+1); 
        }
        printf("\n");

        // print garis
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


    // validasi jika besar ruangan tidak valid
    if (baris < 0 || kolom < 0 || kolom >= rumahsakit.denah.cols || baris >= rumahsakit.denah.rows) {
        printf("Ruangan tidak ditemukan!\n");
    }
    
    else{
        int idDokter = rumahsakit.denah.contents[baris][kolom].dokterID;
        int pasienCount = 0;
        int id_pasien;
        Node* temp = rumahsakit.denah.contents[baris][kolom].antrian->front;
        printf("\n--- Detail Ruangan %s ---\n", kodeRuangan);
        printf("Kapasitas  : %d\n", rumahsakit.kapasitasRuangan);
        printf("Dokter     : %s\n", (idDokter == 0) ? "-" : cariUsername(UserData, idDokter));
        printf("Pasien di dalam ruangan:\n");
        
        // mengambil data pasien di queue linked list dan melakukan print setiap pasien hingga NULL
        while (temp != NULL && pasienCount < rumahsakit.kapasitasRuangan &&  strcmp(cariUsername(UserData, idDokter), "-") != 0 )
        {
            id_pasien = temp->data;
        if (id_pasien != 0) {
                printf("  %d. %s\n", ++pasienCount, cariUsername(UserData, id_pasien));
            }
            temp = temp->next;
        }

        if (pasienCount == 0) printf("  Tidak ada pasien\n");
        printf("------------------------------\n");
    }
}