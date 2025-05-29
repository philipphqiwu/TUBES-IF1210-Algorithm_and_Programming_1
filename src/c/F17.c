#include "../header/F17.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minumPenawar(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    if(config->perutPasien[loginID].head == NULL){
        printf("Perut kosong!! Belum ada obat yang dimakan.\n");
        return;
    }
    int obatID = pop(&(config->perutPasien[loginID]));
    int obatIdx = cariIdxObat(&listObat, obatID);
    printf("Uwekkk!!! %s keluar dan kembali ke inventory.\n", listObat.items[obatIdx].nama_obat);
    for(int i = 1; i < MAX_OBAT_PER_PENYAKIT; i++){
        if(config->inventoryPasien.contents[loginID][i] == 0){
            config->inventoryPasien.contents[loginID][i] = obatID;
            return;
        }
    }
}