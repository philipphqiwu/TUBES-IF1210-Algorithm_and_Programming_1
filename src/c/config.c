#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/config.h"

void createConfig(Config *config){
    initializeMatriksDenah(&(config->denah));
    config->kapasitasRuangan = 0;
    config->kapasitasAntrian = 0;
    initializeMatriks(&(config->inventoryPasien), MAX_PASIEN, MAX_OBAT);
}

void printConfig(Config config){
    printf("Ukuran denah %dx%d\n", config.denah.rows, config.denah.cols);
    printf("Kapatasitas ruang: %d; Kapasitas antrian: %d\n", config.kapasitasRuangan, config.kapasitasAntrian);
    for(int i = 0; i < config.denah.rows; i++){
        for(int j = 0; j < config.denah.cols; j++){
            if(config.denah.contents[i][j].dokterID == 0){
                continue;
            }
            printf("Ruangan %s\n", config.denah.contents[i][j].kodeRuangan);
            printf("\tID Dokter: %d\n", config.denah.contents[i][j].dokterID);
            printf("\tAntrian (ID Pasien): ");
            printQueue(config.denah.contents[i][j].antrian);
        }
        printf("\n");
    }
    printf("Jumlah pemilik obat: %d\n", config.jumlahPemilikObat);
    printf("Inventory Pasien\n");
    for(int i = 0; i < config.inventoryPasien.rows; i++){
        if(config.inventoryPasien.contents[i][0] == 0) continue;
        printf("Pasien ID: %d\n", i);
        printf("\tInventory: ");
        for(int j = 0; j < config.inventoryPasien.cols; j++){
            if(config.inventoryPasien.contents[i][j] == 0) break;
            printf("%d ", config.inventoryPasien.contents[i][j]);
        }
        printf("\n");
    }
}