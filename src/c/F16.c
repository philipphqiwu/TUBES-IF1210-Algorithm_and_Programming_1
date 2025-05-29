#include "../header/F16.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minumObat(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    if(isMatriksEmpty(config->inventoryPasien)){
        printf("Pasien tidak memiliki obat!\n");
        return;
    }
    printf("============ DAFTAR OBAT ============\n");
    int nomorObat = 1;
    int obatAvailable[MAX_OBAT_PER_PENYAKIT];
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        int obatID = config->inventoryPasien.contents[loginID][i];
        if(obatID == 0) continue;
        printf("%d. %s\n", nomorObat, listObat.items[obatID].nama_obat);
        obatAvailable[nomorObat] = obatID;
        nomorObat++;
    }
    printf("Pilih obat untuk diminum: ");
    int obatPilihan;
    scanf("%d", &obatPilihan);
    while(obatPilihan <= 0 || obatPilihan >= nomorObat){
        printf("Pilihan nomor tidak tersedia!\n");
        printf("Pilih obat untuk diminum: ");
        scanf("%d", &obatPilihan);
    }
    printf("GLEKGLEKGLEK... %s berhasil diminum!!!\n", listObat.items[obatAvailable[obatPilihan]].nama_obat);
    push(config->perutPasien, obatAvailable[obatPilihan]);
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        if(config->inventoryPasien.contents[loginID][i] == obatAvailable[obatPilihan]){
            config->inventoryPasien.contents[loginID][i] = 0;
            break;
        }
    }
}