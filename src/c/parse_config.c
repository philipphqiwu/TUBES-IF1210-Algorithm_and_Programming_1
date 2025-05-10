#include <stdio.h>
#include "user.h"
#include "config.h"

void READ_CONFIG(){
    FILE * file = fopen("../data/config.txt","r");
    Config rumahsakit;
    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }
   
    fscanf(file, "%d %d", &rumahsakit.roomRow, &rumahsakit.roomCol);
    fscanf(file, "%d", &rumahsakit.roomCapacity);
    for (int i = 0; i < rumahsakit.roomRow*rumahsakit.roomCol; i++){
        fscanf(file, "%d %d %d %d", 
            &rumahsakit.room[i][0], 
            &rumahsakit.room[i][1], 
            &rumahsakit.room[i][2], 
            &rumahsakit.room[i][3]);
    }
    fscanf(file, "%d", &rumahsakit.jumlahPemilikobat);
    for (int i = 0; i < rumahsakit.jumlahPemilikobat; i++){
        fscanf(file, "%d %d %d %d %d %d", 
            &rumahsakit.inventoryPasien[i][0], 
            &rumahsakit.inventoryPasien[i][1], 
            &rumahsakit.inventoryPasien[i][2], 
            &rumahsakit.inventoryPasien[i][3], 
            &rumahsakit.inventoryPasien[i][4], 
            &rumahsakit.inventoryPasien[i][5]);
    }
    fclose(file);

}

void WRITE_CONFIG(const Config *rs) {
    FILE *file = fopen("config.txt", "w");
    if (!file) {
        printf("Gagal membuat/membuka file.\n");
        return;
    }

    fprintf(file, "%d %d\n", rs->roomRow, rs->roomCol);

    fprintf(file, "%d\n", rs->roomCapacity);

    for (int i = 0; i < rs->roomRow * rs->roomCol; i++) {
        fprintf(file, "%d %d %d %d\n", 
                rs->room[i][0],
                rs->room[i][1],
                rs->room[i][2],
                rs->room[i][3]);
    }

    
    fprintf(file, "%d\n", rs->jumlahPemilikobat);

    
    for (int i = 0; i < rs->jumlahPemilikobat; i++) {
        fprintf(file, "%d %d %d %d %d %d\n",
                rs->inventoryPasien[i][0],
                rs->inventoryPasien[i][1],
                rs->inventoryPasien[i][2],
                rs->inventoryPasien[i][3],
                rs->inventoryPasien[i][4],
                rs->inventoryPasien[i][5]);
    }

    fclose(file); 
}