#include "../header/user.h"
#include "../header/config.h"
#include "../header/queue.h"
#include "../header/F06.h"
#include "../header/F15.h"
#include <stdio.h>

void antrianSaya(ListDinUser *UserData, Config *rumahsakit, int loginId){
    for (int i = 0; i < rumahsakit->denah.rows; i++) {
        for (int j = 0; j < rumahsakit->denah.cols; j++) {
            Node *current = rumahsakit->denah.contents[i][j].antrian->front;
            while (current != NULL) {
                if (current->data == loginId) {
                    if(rumahsakit->denah.contents[i][j].antrian->counter <= 3){
                        printf(COLOR_RED"Anda sedang berada di dalam ruangan dokter!\n"COLOR_RESET);
                    }else{
                        printf(COLOR_YELLOW"Status antrian anda:\n");
                        printf("Dokter: Dr. %s\n", cariUsername(*UserData, rumahsakit->denah.contents[i][j].dokterID));
                        printf("Ruangan: %s\n", rumahsakit->denah.contents[i][j].kodeRuangan);
                        printf("Posisi antrian: %d dari %d\n"COLOR_RESET, (rumahsakit->denah.contents[i][j].antrian->counter - rumahsakit->kapasitasRuangan), rumahsakit->kapasitasAntrian);
                    }
                    return;
                }
                current = current->next;
            }
        }
    }
    //kalau ga ketemu id pasien dalam antrian manapun
    printf(COLOR_RED"Anda belum terdaftar dalam antrian check-up!\n");
    printf("Silakan daftar terlebih dahulu dengan command DAFTAR_CHECKUP.\n"COLOR_RESET);
}