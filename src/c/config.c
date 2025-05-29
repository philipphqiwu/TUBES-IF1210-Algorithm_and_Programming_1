#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/config.h"

void createConfig(Config *config){
    initializeMatriksDenah(&(config->denah));
    config->kapasitasRuangan = 0;
    config->kapasitasAntrian = 0;
    initializeMatriks(&(config->inventoryPasien), MAX_PASIEN, MAX_OBAT);
    for(int i = 0; i < MAX_PASIEN; i++){
        createStack(&(config->perutPasien[i]));
    }
}

void printConfig(Config config){
    printf("Ukuran denah %dx%d\n", config.denah.rows, config.denah.cols);
    printf("Kapasitas ruang: %d; Kapasitas antrian: %d\n", config.kapasitasRuangan, config.kapasitasAntrian);
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
    printf("Jumlah perut pasien terisi: %d\n", config.jumlahPerutPasien);
    for(int i = 0; i < MAX_PASIEN; i++){
        if(isStackEmpty(config.perutPasien[i])) continue;
        printf("Perut pasien %d: ", i);
        printStack(config.perutPasien[i]);
    }
}

void writeConfig(char * folderPath, Config *config){
    char fullFilePath[300];
    snprintf(fullFilePath, sizeof(fullFilePath),"%s/config.txt", folderPath ); 
    FILE * file = fopen(fullFilePath, "w");
    // rows dan cols
    fprintf(file, "%d %d\n", config->denah.rows, config->denah.cols);
    // kapasitas ruangan dan antrian
    fprintf(file,"%d %d\n", config->kapasitasRuangan, config->kapasitasAntrian);
    // isi tiap ruang dan antrian
    for(int i = 0; i < config->denah.rows; i++){
        for(int j = 0; j < config->denah.cols; j++){
            fprintf(file, "%d", config->denah.contents[i][j].dokterID);
            if(config->denah.contents[i][j].dokterID == 0){
                fprintf(file, "\n");
                continue;
            }
            // Traverse the Queue and print each element
            Node* temp = config->denah.contents[i][j].antrian->front;
            while (temp != NULL) {
                fprintf(file, " %d", temp->data);
                temp = temp->next;
            }
            fprintf(file,"\n");
        }
    }
    // pemilik obat
    fprintf(file,"%d\n", config->jumlahPemilikObat);
    // inventori
    for(int i = 0; i < config->inventoryPasien.rows; i++){
        if(config->inventoryPasien.contents[i][0] == 0) continue;
        fprintf(file, "%d", i);
        for(int j = 0; j < config->inventoryPasien.cols; j++){
            if(config->inventoryPasien.contents[i][j] == 0) break;
            fprintf(file, " %d", config->inventoryPasien.contents[i][j]);
        }
        fprintf(file, "\n");
    }

    // perut
    fprintf(file, "%d\n", config->jumlahPerutPasien);
    for(int i = 0; i < MAX_PASIEN; i++){
        if(isStackEmpty(config->perutPasien[i])) continue;
        fprintf(file, "%d", i);

        Stack stackReverse;
        createStack(&stackReverse);
        Node* temp = config->perutPasien[i].head;
        while(temp != NULL){
            push(&stackReverse, temp->data);
            temp = temp->next;
        }
        

        
        Node* tempReverse = stackReverse.head;
        while(tempReverse != NULL){
            fprintf(file, " %d", tempReverse->data);
            tempReverse = tempReverse->next;
        }
        fprintf(file, "\n");
    }

    fclose(file);
}