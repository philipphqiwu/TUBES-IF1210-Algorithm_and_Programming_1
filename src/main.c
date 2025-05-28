#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/user.h"
#include "header/obat.h"
#include "header/penyakit.h"
#include "header/obat-penyakit.h"
#include "header/input.h"
#include "header/parse-config.h"
#include "header/general-parsing.h"
#include "header/initialize-program.h"
#include "header/F01.h"
#include "header/F02.h"
#include "header/F03.h"
#include "header/F04.h"
#include "header/F06.h"
#include "header/save.h"
#include "header/colors.h"


int main(int argc, char *argv[]) {
    char folderPath[300];
    if (argc == 1){
        printf(COLOR_BLUE"Program akan menggunakan folder default yaitu ../data\n"COLOR_RESET);
        snprintf(folderPath, sizeof(folderPath), "../data");
    } else if (argc == 2) {
        char folderName[256];
        strcpy (folderName,argv[1]);
        folderName[strcspn(folderName, "\n")] = '\0';
        snprintf(folderPath, sizeof(folderPath), "../data/%s", folderName);
        if (!folderExists(folderPath)) {
            printf(COLOR_RED"FOLDER TIDAK DITEMUKAN! PASTIKAN FOLDER ADA DAN BERISI DATA YANG VALID!\n"COLOR_RESET);
            return 0;
        }
    } else{
        printf(COLOR_RED"INVALID ARGUMENT!\n"COLOR_RESET);
        return 0;
    }

    int loginState = 0;
    /*
    loginState
    0 : not logged in
    1 : logged in as manager
    2 : logged in as doctor
    3 : logged in as patient
    */
    int loginId = -1; // logged in dengan id berapa
    int run = 1;
    ListDinUser UserData;
    CreateListDinUser(&UserData, 100);
    ListObat listObat;
    createListObat(&listObat, 100);
    ListPenyakit listPenyakit;
    createListPenyakit(&listPenyakit, 100);
    MapObatPenyakit mapObatPenyakit;
    createMapObatPenyakit(&mapObatPenyakit);
    Config config;
    createConfig(&config);

    initializeProgram(folderPath, &UserData, &listObat, &listPenyakit, &mapObatPenyakit, &config);
    for (int i = 0; i < UserData.nEff; i++) {
        UserData.buffer[i].ruang[0] = '\0';
        UserData.buffer[i].antrian[0] = '\0';
    }

    // ini untuk set ruangan di adt user dari tiap orang yg ada di ruangannya yeeeeee
    for(int i = 0; i < config.denah.rows; i++){
        for(int j = 0; j < config.denah.cols; j++){
            int idxdokter = cariIdxUser(&UserData, config.denah.contents[i][j].dokterID);
            if(idxdokter != -1){
                strcpy(UserData.buffer[idxdokter].ruang,config.denah.contents[i][j].kodeRuangan);
            } else{
                continue;
            }
            if(isQueueEmpty(config.denah.contents[i][j].antrian)){
                continue;
            } else{
                Node* current = config.denah.contents[i][j].antrian->front;
                int count = 0;

                while (current != NULL) {
                    int idxPasien = cariIdxUser(&UserData, current->data);
                    if (count < config.kapasitasRuangan) {
                        strcpy(UserData.buffer[idxPasien].ruang, config.denah.contents[i][j].kodeRuangan);
                    } else {
                        strcpy(UserData.buffer[idxPasien].antrian, config.denah.contents[i][j].kodeRuangan);
                    }
                    count++;
                    current = current->next;
                }
            }
        }
    }
    
    // Config rumahsakit;
    // readConfig(folderPath, &rumahsakit, &UserData);

    // printf("Jumlah user: %d\n", UserData.nEff);
    // printList(UserData);
    // printf("List Obat: \n");
    // printListObat(listObat);
    // printf("List Penyakit: \n");
    // printListPenyakit(listPenyakit);
    // printf("Map Obat Penyakit: \n");
    // printMapObatPenyakit(mapObatPenyakit);
    // printf("Config: \n");
    // printConfig(config);
    
    while(run){
        input(&loginState, &loginId, &UserData, &listObat, &listPenyakit, &mapObatPenyakit, &run, &config);
        //printf("id: %d login: %d\n",loginId,loginState);
        //printList(UserData);
    }
    
    return 0;
}