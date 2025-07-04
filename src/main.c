#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/user.h"
#include "header/obat.h"
#include "header/penyakit.h"
#include "header/obat-penyakit.h"
#include "header/input.h"
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
    // BAGIAN LOAD
    char folderPath[300];
    if (argc == 1){
        printf(COLOR_RED"Tidak ada nama folder yang diberikan!\nUsage : ./main <<nama_folder>>\n\n"COLOR_RESET);
        return 0;
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

    /* DEBUGGING PURPOSE CODE */
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
    }
    
    return 0;
}