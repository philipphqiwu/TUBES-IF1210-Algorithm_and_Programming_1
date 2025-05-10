#include <stdio.h>
#include "../header/listdinuser.h"
#include "../header/config.h"

void readConfig(Config *rumahsakit) {
    FILE *file = fopen("../data/config.txt", "r");
    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }

    fscanf(file, "%d %d", &rumahsakit->roomRow, &rumahsakit->roomCol);


    fscanf(file, "%d", &rumahsakit->roomCapacity);
    int c;
    while ((c = fgetc(file)) != '\n' && c != EOF); 

    char buffer[256];
    for (int i = 0; i < rumahsakit->roomRow * rumahsakit->roomCol; i++) {
        if (fgets(buffer, sizeof(buffer), file) == NULL) {
            printf("File tidak lengkap!\n");
            break;
        }

        for (int j = 0; j < 100; j++) {
            rumahsakit->room[i][j] = 0;
        }

        char *token = strtok(buffer, " ");
        int counter = 0;
        while (token != NULL && counter <= rumahsakit->roomCapacity) {
            rumahsakit->room[i][counter++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    fscanf(file, "%d", &rumahsakit->jumlahPemilikobat);
    for (int i = 0; i < rumahsakit->jumlahPemilikobat; i++) {
        for (int j = 0; j < 6; j++) {
            fscanf(file, "%d", &rumahsakit->inventoryPasien[i][j]);
        }
    }

    fclose(file);
}
// void writeConfig(const Config *rs) {
//     FILE *file = fopen("config.txt", "w");
//     if (!file) {
//         printf("Gagal membuat/membuka file.\n");
//         return;
//     }

//     fprintf(file, "%d %d\n", rs->roomRow, rs->roomCol);

//     fprintf(file, "%d\n", rs->roomCapacity);

//     for (int i = 0; i < rs->roomRow * rs->roomCol; i++) {
//         int j = 0;
//         while (fprintf(file, "%d\n",  rs->room[i][j]) != \n){
//             j++
//         }
//     }

    
//     fprintf(file, "%d\n", rs->jumlahPemilikobat);

    
//     for (int i = 0; i < rs->jumlahPemilikobat; i++) {
//         fprintf(file, "%d %d %d %d %d %d\n",
//                 rs->inventoryPasien[i][0],
//                 rs->inventoryPasien[i][1],
//                 rs->inventoryPasien[i][2],
//                 rs->inventoryPasien[i][3],
//                 rs->inventoryPasien[i][4],
//                 rs->inventoryPasien[i][5]);
//     }

//     fclose(file); 
// }