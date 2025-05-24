#include <stdio.h>
#include "../header/user.h"
#include "../header/config.h"
#include "../header/matriks.h"



void writeConfig(Config *rumahsakit, ListDinUser *UserData) {
    FILE *file = fopen("../data/config.txt", "w");
    if (!file) {
        printf("Gagal membuka file untuk ditulis.\n");
        return;
    }

    fprintf(file, "%d %d\n", rumahsakit->roomRow, rumahsakit->roomCol);

    fprintf(file, "%d %d\n", rumahsakit->roomCapacity, rumahsakit->queueCapacity);

    int totalrooms = rumahsakit->roomRow * rumahsakit->roomCol;
    for (int i = 0; i < totalrooms; i++) {
        int isFirstElement = 1;

        // Jika tidak di assign dokter
        if (rumahsakit->room[i].idDokter == 0) {
            fprintf(file, "0\n");
            continue;
        }
        // Jika ada dokter
        fprintf(file, "%d", rumahsakit->room[i].idDokter);
        isFirstElement = 0;

        for (int j = 0; j < rumahsakit->roomCapacity; j++) {
            if (rumahsakit->room[i].ruangan[j] != 0) {
                if (!isFirstElement) {
                    fprintf(file, " ");
                }
                fprintf(file, "%d", rumahsakit->room[i].ruangan[j]);
                isFirstElement = 0;
            }
        }

        QueueConfig tempQueue = rumahsakit->room[i].antrian;

        while (!isQueueEmpty(tempQueue)) {
            int pasienId;
            dequeue(&tempQueue, &pasienId);
            if (!isFirstElement) {
                fprintf(file, " ");
            }
            fprintf(file, "%d", pasienId);
            isFirstElement = 0;
        }

        fprintf(file, "\n");
    }

    fprintf(file, "%d\n", rumahsakit->jumlahPemilikobat);

    for (int i = 0; i < rumahsakit->jumlahPemilikobat; i++) {
        int isFirstElement = 1;
        for (int j = 0; j < Max_obat; j++) {
            if (rumahsakit->inventoryPasien.contents[i][j] != 0) {
                if (!isFirstElement) {
                    fprintf(file, " ");
                }
                fprintf(file, "%d", rumahsakit->inventoryPasien.contents[i][j]);
                isFirstElement = 0;
            }
        }
        fprintf(file, "\n");
    }

   

    fclose(file);
}

// void readConfig(Config *rumahsakit, ListDinUser * UserData) {
//     FILE *file = fopen("../data/config.txt", "r");
//     if (!file) {
//         printf("Gagal membuka file.\n");
//         return;
//     }

//     fscanf(file, "%d %d", &rumahsakit->roomRow, &rumahsakit->roomCol);


//     fscanf(file, "%d", &rumahsakit->roomCapacity);
//     int c;
//     while ((c = fgetc(file)) != '\n' && c != EOF); 

//     char buffer[256];
//     for (int i = 0; i < rumahsakit->roomRow * rumahsakit->roomCol; i++) {
//         if (fgets(buffer, sizeof(buffer), file) == NULL) {
//             printf("File tidak lengkap!\n");
//             break;
//         }

//         for (int j = 0; j < 100; j++) {
//             rumahsakit->room[i][j] = 0;
//         }

//         char *token = strtok(buffer, " ");
//         int counter = 0;
//         char kodeRuang[3];
//         int row = i / rumahsakit->roomCol;
//         int col = i % rumahsakit->roomCol;
//         while (token != NULL && counter <= rumahsakit->roomCapacity) {
//             if(counter == 0){
//                 sprintf(kodeRuang, "%c%c", 'A' + row, '1' + col);
//                 strcpy(UserData->buffer[atoi(token)-1].ruang,kodeRuang);
//             }
//             rumahsakit->room[i][counter++] = atoi(token)-1;
//             token = strtok(NULL, " ");
//         }
//     }

//     fscanf(file, "%d", &rumahsakit->jumlahPemilikobat);
//     for (int i = 0; i < rumahsakit->jumlahPemilikobat; i++) {
//         for (int j = 0; j < 6; j++) {
//             fscanf(file, "%d", &rumahsakit->inventoryPasien[i][j]);
//         }
//     }

//     fclose(file);
// }
