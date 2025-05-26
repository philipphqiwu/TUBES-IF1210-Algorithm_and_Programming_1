#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/F12.h"

void ngobatin(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    int found = 0;
    int indeksRuangan[2];
    for(int i = 0; i < config->denah.rows && !found; i++){
        for(int j = 0; j < config->denah.cols && !found; j++){
            if(config->denah.contents[i][j].dokterID == loginID){
                found = 1;
                indeksRuangan[0] = i;
                indeksRuangan[1] = j;
            }
        }
    }
    if(!found){
        printf("Anda belum terassign pada ruangan apapun.\n");
        return;
    }
    if(config->denah.contents[indeksRuangan[0]][indeksRuangan[1]].antrian->counter == 0){
        printf("Tidak ada pasien dalam ruangan.\n");
        return;
    }
    int pasienID = config->denah.contents[indeksRuangan[0]][indeksRuangan[1]].antrian->front->data;
    printf("Dokter sedang mengobati pasien!\n");
    int penyakitID = searchPenyakitIDByName(listPenyakit, listUser.buffer[pasienID].riwayat_penyakit);
    if(penyakitID == -1) {
        printf("Pasien tidak memiliki penyakit!\n");
        printf("Pasien belum didiagnosis!\n");
        return;
    }
    printf("Pasien memiliki penyakit %s\n", listPenyakit.items[penyakitID].nama_penyakit);
    printf("Obat yang harus diberikan: ");
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT && mapObatPenyakit.items[penyakitID].value[i].obat_id != 0; i++){
        printf("%d. %s\n", i, listObat.items[mapObatPenyakit.items[penyakitID].value[i].obat_id].nama_obat);
        config->inventoryPasien.contents[pasienID][i] = mapObatPenyakit.items[penyakitID].value[i].obat_id;
    }
    return;
}
