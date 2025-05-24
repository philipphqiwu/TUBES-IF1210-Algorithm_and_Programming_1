#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/user.h"
#include "header/obat.h"
#include "header/penyakit.h"
#include "header/obat-penyakit.h"
#include "header/input.h"
#include "header/parse-user.h"
#include "header/parse-config.h"
#include "header/general-parsing.h"
#include "header/initialize-program.h"
#include "header/F01.h"
#include "header/F02.h"
#include "header/F03.h"
#include "header/F04.h"
#include "header/F06.h"
#include "header/save.h"


int main(int argc, char *argv[]) {
    char folderPath[300];
    if (argc == 1){
        printf("Program akan menggunakan folder default yaitu ../data\n");
        snprintf(folderPath, sizeof(folderPath), "../data");
        printf("hit\n");
    } else if (argc == 2) {
        char folderName[256];
        strcpy (folderName,argv[1]);
        folderName[strcspn(folderName, "\n")] = '\0';
        snprintf(folderPath, sizeof(folderPath), "../data/%s", folderName);
        if (!folderExists(folderPath)) {
            printf("FOLDER TIDAK DITEMUKAN! PASTIKAN FOLDER ADA DAN BERISI DATA YANG VALID!\n");
            return 0;
        }
    } else{
        printf("INVALID ARGUMENT!\n");
        return 0;
    }

    printf("hit\n");

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
    printf("hit1\n");
    ListObat listObat;
    createListObat(&listObat, 100);
    printf("hit2\n");
    ListPenyakit listPenyakit;
    createListPenyakit(&listPenyakit, 100);
    printf("hit3\n");
    MapObatPenyakit mapObatPenyakit;
    createMapObatPenyakit(&mapObatPenyakit);
    printf("hit4\n");
    Config config;
    createConfig(&config);
    printf("hit5\n");

    printf("hit6\n");

    initializeProgram(folderPath, &UserData, &listObat, &listPenyakit, &mapObatPenyakit, &config);
    for (int i = 0; i < UserData.nEff; i++) {
        UserData.buffer[i].ruang[0] = '\0';
    }
    
    // Config rumahsakit;
    // readConfig(folderPath, &rumahsakit, &UserData);

    printf("Jumlah user: %d\n", UserData.nEff);
    printList(UserData);
    printf("List Obat: \n");
    printListObat(listObat);
    printf("List Penyakit: \n");
    printListPenyakit(listPenyakit);
    printf("Map Obat Penyakit: \n");
    printMapObatPenyakit(mapObatPenyakit);
    printf("Config: \n");
    printConfig(config);
    
    while(run){
        input(&loginState, &loginId, &UserData, &listObat, &listPenyakit, &mapObatPenyakit, &run, &config);
        //printf("id: %d login: %d\n",loginId,loginState);
        //printList(UserData);
    }
    
    return 0;
}