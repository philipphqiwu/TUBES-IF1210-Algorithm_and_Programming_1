#include <stdio.h>
#include "../header/user.h"
#include "../header/config.h"


void readConfig(Config *rumahsakit, ListDinUser *UserData) {
    FILE *file = fopen("../data/config.txt", "r");
    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[256];
    char *ptr, *end;

    fgets(line, sizeof(line), file);
    rumahsakit->roomRow = (int)strtol(line, &end, 10);
    rumahsakit->roomCol = (int)strtol(end, &end, 10);

    fgets(line, sizeof(line), file);
    rumahsakit->roomCapacity = (int)strtol(line, &end, 10);

    while(fgetc(file) != '\n');

    for (int i = 0; i < rumahsakit->roomRow * rumahsakit->roomCol; i++) {
        if (!fgets(line, sizeof(line), file)) {
            printf("File tidak lengkap!\n");
            break;
        }

        for (int j = 0; j < 100; j++) {
            rumahsakit->room[i][j] = 0;
        }

        ptr = line;
        int counter = 0;
        char kodeRuang[3];
        int row = i / rumahsakit->roomCol;
        int col = i % rumahsakit->roomCol;
        
        while (*ptr && counter <= rumahsakit->roomCapacity) {

            while (*ptr == ' ') ptr++;
            

            long val = strtol(ptr, &end, 10);
            if (ptr == end) break;
            
            if (counter == 0) {

                snprintf(kodeRuang, sizeof(kodeRuang), "%c%c", 'A' + row, '1' + col);
                

                strncpy(UserData->buffer[val-1].ruang, kodeRuang, sizeof(UserData->buffer[0].ruang)-1);
            }
            
            rumahsakit->room[i][counter++] = (int)val - 1;
            ptr = end;
        }
    }


    fgets(line, sizeof(line), file);
    rumahsakit->jumlahPemilikobat = (int)strtol(line, &end, 10);


    for (int i = 0; i < rumahsakit->jumlahPemilikobat; i++) {
        if (!fgets(line, sizeof(line), file)) break;
        
        ptr = line;
        for (int j = 0; j < 6; j++) {
      
            while (*ptr == ' ') ptr++;
            
            long val = strtol(ptr, &end, 10);
            rumahsakit->inventoryPasien[i][j] = (int)val;
            ptr = end;
        }
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
