#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/F12.h"

void ngobatin(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    int found = 0;
    int indeksRuangan[2];
    // printf("[DEBUG] loginID: %d\n", loginID);
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
    int pasienIdx = cariIdxUser(&listUser, pasienID);
    printf("Dokter sedang mengobati pasien!\n\n");
    // printf("[DEBUG] riwayat_penyakit: %s\n", listUser.buffer[pasienIdx].riwayat_penyakit);
    int penyakitID = searchPenyakitIDByName(listPenyakit, listUser.buffer[pasienIdx].riwayat_penyakit);
    if(penyakitID == -1) {
        printf("Pasien tidak memiliki penyakit!\n");
        printf("Pasien belum didiagnosis!\n");
        return;
    }
    int penyakitIdx = cariIdxPenyakit(&listPenyakit, penyakitID);
    printf("Pasien memiliki penyakit %s\n", listPenyakit.items[penyakitIdx].nama_penyakit);
    // printf("[DEBUG] penyakitIdx: %d\n", penyakitIdx);
    config->jumlahPemilikObat++;
    printf("Obat yang harus diberikan: \n");
    for(int i = 1; i < MAX_OBAT_PER_PENYAKIT; i++){
        int obatID = mapObatPenyakit.items[penyakitID].value[i].obat_id;
        // printf("[DEBUG] obatID: %d\n", mapObatPenyakit.items[penyakitID].value[i].obat_id);
        if(obatID == 0) break;
        int obatIdx = cariIdxObat(&listObat, obatID);
        printf("%d. %s\n", i, listObat.items[obatIdx].nama_obat);
        config->inventoryPasien.contents[pasienID][i] = listObat.items[obatIdx].obat_id;
    }
    return;
}
