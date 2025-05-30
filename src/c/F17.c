#include "../header/F17.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minumPenawar(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    if(config->perutPasien[loginID].head == NULL){
        printf(COLOR_RED"Perut kosong!! Belum ada obat yang dimakan.\n"COLOR_RESET);
        return;
    }
    int obatID = pop(&(config->perutPasien[loginID]));
    int obatIdx = cariIdxObat(&listObat, obatID);
    printf(COLOR_YELLOW"Uwekkk!!! %s keluar dan kembali ke inventory.\n"COLOR_RESET, listObat.items[obatIdx].nama_obat);
    if(config->inventoryPasien.contents[loginID][0] == 0){
        config->jumlahPemilikObat++;
    }
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        if(config->inventoryPasien.contents[loginID][i] == 0){
            config->inventoryPasien.contents[loginID][i] = obatID;
            break;
        }
    }
    if(config->perutPasien[loginID].head == NULL){
        config->jumlahPerutPasien--;
    }
}