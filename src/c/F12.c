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
        printf(COLOR_RED"Anda belum terassign pada ruangan apapun.\n"COLOR_RESET);
        return;
    }
    if(config->denah.contents[indeksRuangan[0]][indeksRuangan[1]].antrian->counter == 0){
        printf(COLOR_RED"Tidak ada pasien dalam ruangan.\n"COLOR_RESET);
        return;
    }
    if(!isMatriksRowEmpty(config->inventoryPasien, loginID) || (config->perutPasien[loginID].head != NULL)){
        printf(COLOR_RED"Pasien sudah diobati!\n"COLOR_RESET);
        return;
    }
    int pasienID = config->denah.contents[indeksRuangan[0]][indeksRuangan[1]].antrian->front->data;
    int pasienIdx = cariIdxUser(&listUser, pasienID);
    printf(COLOR_CYAN"Dokter sedang mengobati pasien!\n\n");
    // printf("[DEBUG] riwayat_penyakit: %s\n", listUser.buffer[pasienIdx].riwayat_penyakit);
    int penyakitID = searchPenyakitIDByName(listPenyakit, listUser.buffer[pasienIdx].riwayat_penyakit);
    if(penyakitID == -1) {
        printf(COLOR_RED"Pasien tidak memiliki penyakit!\n");
        printf(COLOR_RED"Pasien belum didiagnosis!\n"COLOR_RESET);
        return;
    }
    int penyakitIdx = cariIdxPenyakit(&listPenyakit, penyakitID);
    printf(COLOR_CYAN"Pasien memiliki penyakit %s\n", listPenyakit.items[penyakitIdx].nama_penyakit);
    // printf("[DEBUG] penyakitIdx: %d\n", penyakitIdx);
    config->jumlahPemilikObat++;
    printf("Obat yang harus diberikan: \n");
    for(int i = 1; i < MAX_OBAT_PER_PENYAKIT; i++){
        int obatID = mapObatPenyakit.items[penyakitID].value[i].obat_id;
        // printf("[DEBUG] obatID: %d\n", mapObatPenyakit.items[penyakitID].value[i].obat_id);
        if(obatID == 0) break;
        int obatIdx = cariIdxObat(&listObat, obatID);
        printf("%d. %s\n", i, listObat.items[obatIdx].nama_obat);
        insertMatrixByIndex(&config->inventoryPasien, pasienID, i-1, listObat.items[obatIdx].obat_id);
        //config->inventoryPasien.contents[pasienID][i-1] = listObat.items[obatIdx].obat_id;
    }
    printf(COLOR_RESET);
    return;
}
