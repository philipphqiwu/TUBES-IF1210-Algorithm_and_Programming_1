#include <stdio.h>
#include <stdlib.h>
#include "../header/user.h"
#include "../header/config.h"
#include "../header/config_queue.h"


void readConfig(Config *rumahsakit, ListDinUser *UserData) {
   
    FILE *file = fopen("../data/config.txt", "r");
    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[100];
    char *ptr, *end;

    fgets(line, sizeof(line), file);
    rumahsakit->roomRow = (int)strtol(line, &end, 10);
    rumahsakit->roomCol = (int)strtol(end, &end, 10);

    fgets(line, sizeof(line), file);
    rumahsakit->roomCapacity = (int)strtol(line, &end, 10);
    rumahsakit->queueCapacity = (int)strtol(end, &end, 10);

    int totalRooms = rumahsakit->roomRow * rumahsakit->roomCol;

    for (int i = 0; i < totalRooms; i++) {
        initQueue(&rumahsakit->room[i].antrian);
        rumahsakit->room[i].idDokter = 0;
        for (int k = 0; k < CAPACITYRUANGAN; k++) {
            rumahsakit->room[i].ruangan[k] = 0;
        }
        fgets(line, sizeof(line), file);
        ptr = line;
        int counter = 0;
        int roomPatientCount = 0;
        int queuePatientCount = 0;

        if (*ptr == '0' && (*(ptr+1) == '\n' || *(ptr+1) == '\0' || *(ptr+1) == ' ')) {
            continue;
        }
        while (*ptr && *ptr != '\n') {

            while (*ptr == ' ' || *ptr == '\t') ptr++;
            if (*ptr == '\n' || *ptr == '\0') break;

            long val = strtol(ptr, &end, 10);
            if (ptr == end) break; // Tidak ada angka valid ditemukan

            if (counter == 0) {
                // Angka pertama adalah ID dokter
                rumahsakit->room[i].idDokter = (int)val;
            } else if (roomPatientCount < rumahsakit->roomCapacity) {
           
                rumahsakit->room[i].ruangan[roomPatientCount] = (int)val;
                roomPatientCount++;
            } else if (queuePatientCount < rumahsakit->queueCapacity) {
           
                enqueue(&rumahsakit->room[i].antrian, (int)val);
                queuePatientCount++;
            }
            
            counter++;
            ptr = end;
        }
    
}

    fgets(line, sizeof(line), file);
    rumahsakit->jumlahPemilikobat = (int)strtol(line, &end, 10);

    initializeMatriks(rumahsakit->inventoryPasien.contents, rumahsakit->jumlahPemilikobat, Max_obat);
    for (int i = 0; i < rumahsakit->jumlahPemilikobat; i++) {
        if (!fgets(line, sizeof(line), file)) break;
        
        ptr = line;
        for (int j = 0; j < Max_obat; j++) {
      
            while (*ptr == ' ') ptr++;
            if (*ptr == '\n' || *ptr == '\0') break;

            long val = strtol(ptr, &end, 10);
            if (ptr == end) break;
            rumahsakit->inventoryPasien.contents[i][j] = (int)val;
            ptr = end;
        }
    }

    fclose(file);
}
