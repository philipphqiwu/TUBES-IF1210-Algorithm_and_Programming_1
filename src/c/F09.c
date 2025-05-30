#include "../header/F06.h"
#include "../header/F09.h"
#include "../header/config.h"
#include "../header/user.h"
#include "../header/matriks-denah.h"
#include "../header/queue.h"
#include <stdio.h>

char ruang[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};

void lihatAntrian(Config rumahsakit, ListDinUser UserData){

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

        printf(" %c |", ruang[i]);
        for(int j = 0; j < rumahsakit.denah.cols; j++) {
             printf(" %c%-2d |", ruang[i], j+1); 
        }
        printf("\n");


        printf("   +");
        for(int j = 0; j < rumahsakit.denah.cols; j++) {
            printf("-----+");
        }
        printf("\n");
    }

    for(int baris = 0; baris < rumahsakit.denah.rows; baris++){
        for(int kolom = 0; kolom < rumahsakit.denah.cols; kolom++){
            if(rumahsakit.denah.contents[baris][kolom].dokterID == 0){
                continue;
            }
            printf("\n============ %s ============\n", rumahsakit.denah.contents[baris][kolom].kodeRuangan);
            printf("Kapasitas  : %d\n", rumahsakit.kapasitasRuangan);
            printf("Dokter     : %s\n", cariUsername(UserData, rumahsakit.denah.contents[baris][kolom].dokterID));

            printf("Pasien di dalam ruangan:\n");
            int pasien_count = 0;
            int nomor_urut = 1;
            Node* temp = rumahsakit.denah.contents[baris][kolom].antrian->front;
            while(temp != NULL && pasien_count < rumahsakit.kapasitasRuangan){
                const char* nama = cariUsername(UserData, temp->data);
                if (strcmp(nama, "-") != 0 && strcmp(nama, "") != 0){
                    printf("  %d. %s\n", nomor_urut++, nama);
                    pasien_count++;
                }
                temp = temp->next;
            }
            if (pasien_count == 0) printf("  Tidak ada pasien\n");

            printf("Pasien di antrian:\n");
            int nomor = 1;
            int antrian_count = 0;
            while(temp != NULL && antrian_count < rumahsakit.kapasitasAntrian){
                const char* nama = cariUsername(UserData, temp->data);
                if (strcmp(nama, "-") != 0 && strcmp(nama, "") != 0){
                    printf("  %d. %s\n", nomor++, nama);
                    antrian_count++;
                }
                temp = temp->next;
            }
            if(antrian_count == 0) printf("  Tidak ada pasien di antrian luar ruangan\n");
            printf("------------------------------\n");
        }
    }
}