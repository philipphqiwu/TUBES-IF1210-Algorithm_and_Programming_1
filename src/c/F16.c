#include "../header/F16.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minumObat(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    // int userIdx = cariIdxUser(&listUser, loginID);
    if(isMatriksRowEmpty(config->inventoryPasien, loginID)){
        printf(COLOR_RED"Kamu tidak memiliki obat!\n"COLOR_RESET);
        return;
    }
    printf(COLOR_YELLOW"============ DAFTAR OBAT ============\n");
    int nomorObat = 1;
    int obatAvailable[MAX_OBAT_PER_PENYAKIT];
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        int obatID = config->inventoryPasien.contents[loginID][i];
        int obatIdx = cariIdxObat(&listObat, obatID);
        if(obatID == 0) continue;
        printf("%d. %s\n", nomorObat, listObat.items[obatIdx].nama_obat);
        obatAvailable[nomorObat] = obatID;
        nomorObat++;
    }
    printf("Pilih obat untuk diminum: ");
    int obatPilihan;
    
    while(scanf("%d", &obatPilihan) !=  1 || obatPilihan <= 0 || obatPilihan >= nomorObat){
        printf(COLOR_RED"Pilihan nomor tidak tersedia!\n"COLOR_RESET);
        printf(COLOR_YELLOW"Pilih obat untuk diminum: ");
        while (getchar() != '\n');
    }
    int obatIdx = cariIdxObat(&listObat, obatAvailable[obatPilihan]);
    if(config->perutPasien[loginID].head == NULL){
        config->jumlahPerutPasien++;
    }
    printf("GLEKGLEKGLEK... %s berhasil diminum!!!\n"COLOR_RESET, listObat.items[obatIdx].nama_obat);
    push(&(config->perutPasien[loginID]), obatAvailable[obatPilihan]);
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        if(config->inventoryPasien.contents[loginID][i] == obatAvailable[obatPilihan]){
            for(int j = i; j < MAX_OBAT_PER_PENYAKIT-1; j++){
                if(config->inventoryPasien.contents[loginID][j] == 0){
                    config->inventoryPasien.contents[loginID][j+1] = 0;
                    break;
                }
                config->inventoryPasien.contents[loginID][j] = config->inventoryPasien.contents[loginID][j+1];
            }
            break;
        }
    }
    if(config->inventoryPasien.contents[loginID][0] == 0){
        config->jumlahPemilikObat--;
    }
}