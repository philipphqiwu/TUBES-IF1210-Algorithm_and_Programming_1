#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/initialize-program.h"
#include "../header/general-parsing.h"
#include "../header/user.h"
#include "../header/obat.h"
#include "../header/penyakit.h"
#include "../header/obat-penyakit.h"
#include "../header/config.h"
#include "../header/save.h"
#include "../header/logo.h"

int initializeProgram(char * folderPath, ListDinUser *listUser, ListObat *listObat, ListPenyakit *listPenyakit , MapObatPenyakit *mapObatPenyakit, Config *config){
    printLogo();
    printf("\n");
    printf("===============\n");
    printf("SELAMAT DATANG\n");
    printf("===============\n");


    char filePathObat[MAX_FILE_PATH_CHAR];
    snprintf(filePathObat, sizeof(filePathObat),"%s/obat.csv", folderPath ); 
    char filePathPenyakit[MAX_FILE_PATH_CHAR];
    snprintf(filePathPenyakit, sizeof(filePathPenyakit),"%s/penyakit.csv", folderPath ); 
    char filePathObatPenyakit[MAX_FILE_PATH_CHAR];
    snprintf(filePathObatPenyakit, sizeof(filePathObatPenyakit),"%s/obat_penyakit.csv", folderPath ); 
    char filePathUser[MAX_FILE_PATH_CHAR];
    snprintf(filePathUser, sizeof(filePathUser),"%s/user.csv", folderPath );
    char filePathConfig[MAX_FILE_PATH_CHAR];
    snprintf(filePathConfig, sizeof(filePathConfig), "%s/config.txt", folderPath );

    FILE *obatFile = fopen(filePathObat, "r");
    if(!obatFile){
        printf(COLOR_RED"Gagal membuka file obat.csv\n");
        fclose(obatFile);
        return 0;
    }
    FILE *penyakitFile = fopen(filePathPenyakit, "r");
    if(!penyakitFile){
        printf(COLOR_RED"Gagal membuka file penyakit.csv\n");
        fclose(obatFile);
        fclose(penyakitFile);
        return 0;
    }
    FILE *obatPenyakitFile = fopen(filePathObatPenyakit, "r");
    if(!obatPenyakitFile){
        printf(COLOR_RED"Gagal membuka file obat_penyakit.csv\n");
        fclose(obatFile);
        fclose(penyakitFile);
        fclose(obatPenyakitFile);
        return 0;
    }
    FILE *userFile = fopen(filePathUser, "r");
    if(!userFile){
        printf(COLOR_RED"Gagal membuka file user.csv\n");
        fclose(obatFile);
        fclose(penyakitFile);
        fclose(obatPenyakitFile);
        fclose(userFile);
        return 0;
    }
    FILE *configFile = fopen(filePathConfig, "r");
    if(!configFile){
        printf(COLOR_RED"Gagal membuka file config.txt\n");
        fclose(obatFile);
        fclose(penyakitFile);
        fclose(obatPenyakitFile);
        fclose(userFile);
        fclose(configFile);
        return 0;
    }

    char lineInput[MAX_INPUT_CHAR];
    // Parsing dan pemasukan data user
    // parseUserData(listUser);
    fgets(lineInput, sizeof(lineInput), userFile);
    while(fgets(lineInput, sizeof(lineInput), userFile)){
        User itemUser;
        parsing(lineInput, "issssfiiififiiiii", &itemUser.id, itemUser.username, itemUser.password, itemUser.role, itemUser.riwayat_penyakit, &itemUser.suhu_tubuh, &itemUser.tekanan_darah_sistolik, &itemUser.tekanan_darah_diastolik, &itemUser.detak_jantung, &itemUser.saturasi_oksigen, &itemUser.kadar_gula_darah, &itemUser.berat_badan, &itemUser.tinggi_badan, &itemUser.kadar_kolesterol, &itemUser.trombosit, &itemUser.nyawa, &itemUser.aura);
        insertLast(listUser, itemUser);
    }
    fclose(userFile);
    sortUser(listUser);
    // Parsing dan pemasukan data obat
    fgets(lineInput, sizeof(lineInput), obatFile);
    while(fgets(lineInput, sizeof(lineInput), obatFile) != NULL){
        Obat itemObat;
        parsing(lineInput, "is", &itemObat.obat_id, itemObat.nama_obat);
        insertObat(listObat, itemObat);
    }
    fclose(obatFile);
    sortObat(listObat);
    // Parsing dan pemasukan data penyakit
    fgets(lineInput, sizeof(lineInput), penyakitFile);
    while(fgets(lineInput, sizeof(lineInput), penyakitFile) != NULL){
        Penyakit itemPenyakit;
        parsing(lineInput, "isffiiiiiiffiiffiiiiii", &itemPenyakit.id, itemPenyakit.nama_penyakit, &itemPenyakit.suhu_tubuh_min, &itemPenyakit.suhu_tubuh_max, &itemPenyakit.tekanan_darah_sistolik_min, &itemPenyakit.tekanan_darah_sistolik_max, &itemPenyakit.tekanan_darah_diastolik_min, &itemPenyakit.tekanan_darah_diastolik_max, &itemPenyakit.detak_jantung_min, &itemPenyakit.detak_jantung_max, &itemPenyakit.saturasi_oksigen_min, &itemPenyakit.saturasi_oksigen_max,  &itemPenyakit.kadar_gula_darah_min, &itemPenyakit.kadar_gula_darah_max, &itemPenyakit.berat_badan_min, &itemPenyakit.berat_badan_max, &itemPenyakit.tinggi_badan_min, &itemPenyakit.tinggi_badan_max, &itemPenyakit.kadar_kolesterol_min, &itemPenyakit.kadar_kolesterol_max, &itemPenyakit.trombosit_min, &itemPenyakit.trombosit_max);
        insertPenyakit(listPenyakit, itemPenyakit);
    }
    sortPenyakit(listPenyakit);
    fclose(penyakitFile);
    // Parsing dan pemasukan data obat_penyakit
    fgets(lineInput, sizeof(lineInput), obatPenyakitFile);
    while(fgets(lineInput, sizeof(lineInput), obatPenyakitFile) != NULL){
        int obatId;
        int penyakitId;
        int urutanMinum;
        parsing(lineInput, "iii", &obatId, &penyakitId, &urutanMinum);
        insertObatPenyakitByRawData(mapObatPenyakit, obatId, penyakitId, urutanMinum);
    }
    fclose(obatPenyakitFile);
    // Parsing dan pemasukan data config
    fgets(lineInput, sizeof(lineInput), configFile);
    configParsing(lineInput, "ii", &config->denah.rows, &config->denah.cols);
    fgets(lineInput, sizeof(lineInput), configFile);
    configParsing(lineInput, "ii", &config->kapasitasRuangan, &config->kapasitasAntrian);
    for(int i = 0; i < config->denah.rows * config->denah.cols; i++){
        int row = i/config->denah.cols;
        int col = i%config->denah.cols;
        fgets(lineInput, sizeof(lineInput), configFile);
        configParsing(lineInput, "i", &config->denah.contents[row][col].dokterID);
        int indeksGet = 1;
        while(lineInput[indeksGet] != ' '){
            indeksGet++;
        }
        // config->denah.contents[row][col].antrian = createQueue();
        while(lineInput[indeksGet] != '\n' && lineInput[indeksGet] != '\0' && lineInput[indeksGet] != '0'){
            if(lineInput[indeksGet] == ' '){
                indeksGet++;
            }
            else{
                char stringAngka[10];
                int indeksPut = 0;
                stringAngka[indeksPut] = lineInput[indeksGet];
                indeksPut++;
                indeksGet++;
                while(lineInput[indeksGet] != ' ' && lineInput[indeksGet] != '\n' && lineInput[indeksGet] != '\0'){
                    stringAngka[indeksPut] = lineInput[indeksGet];
                    indeksGet++;
                    indeksPut++;
                }
                stringAngka[indeksPut] = '\0';
                int pasienID = atoi(stringAngka);
                enqueue(config->denah.contents[row][col].antrian, pasienID);
            }
        }
    }
    fgets(lineInput, sizeof(lineInput), configFile);
    configParsing(lineInput, "i", &config->jumlahPemilikObat);
    for(int i = 0; i < config->jumlahPemilikObat; i++){
        fgets(lineInput, sizeof(lineInput), configFile);
        int pasienID;
        configParsing(lineInput, "i", &pasienID);
        int indeksGet = 1;
        int indeksPut = 0;
        while(lineInput[indeksGet] != '\n' && lineInput[indeksGet] != '\0'){
            if(lineInput[indeksGet] == ' '){
                indeksGet++;
            }
            else{
                char stringAngka[10];
                int indeksPutAngka = 0;
                while(lineInput[indeksGet] != ' ' && lineInput[indeksGet] != '\n' && lineInput[indeksGet] != '\0'){
                    stringAngka[indeksPutAngka] = lineInput[indeksGet];
                    indeksGet++;
                    indeksPutAngka++;
                }
                stringAngka[indeksPutAngka] = '\0';
                int obatID = atoi(stringAngka);
                insertMatrixByIndex(&(config->inventoryPasien), pasienID, indeksPut, obatID);
                indeksGet++;
                indeksPut++;
            }
        }
    }
    fgets(lineInput, sizeof(lineInput), configFile);
    configParsing(lineInput, "i", &config->jumlahPerutPasien);
    for(int i = 0; i < config->jumlahPerutPasien; i++){
        fgets(lineInput, sizeof(lineInput), configFile);
        int pasienID;
        configParsing(lineInput, "i", &pasienID);
        int indeksGet = 1;
        while(lineInput[indeksGet] != '\n' && lineInput[indeksGet] != '\0'){
            if(lineInput[indeksGet] == ' '){
                indeksGet++;
            }
            else{
                char stringAngka[10];
                int indeksPutAngka = 0;
                while(lineInput[indeksGet] != ' ' && lineInput[indeksGet] != '\n' && lineInput[indeksGet] != '\0'){
                    stringAngka[indeksPutAngka] = lineInput[indeksGet];
                    indeksGet++;
                    indeksPutAngka++;
                }
                stringAngka[indeksPutAngka] = '\0';
                int obatID = atoi(stringAngka);
                push(&(config->perutPasien[pasienID]), obatID);
                indeksGet++;
            }
        }
    }
    fclose(configFile);

    for (int i = 0; i < listUser->nEff; i++) {
        listUser->buffer[i].ruang[0] = '\0';
        listUser->buffer[i].antrian[0] = '\0';
    }

    // ini untuk set ruangan di adt user dari tiap orang yg ada di ruangannya yeeeeee
    for(int i = 0; i < config->denah.rows; i++){
        for(int j = 0; j < config->denah.cols; j++){
            int idxdokter = cariIdxUser(listUser, config->denah.contents[i][j].dokterID);
            if(idxdokter != -1){
                strcpy(listUser->buffer[idxdokter].ruang,config->denah.contents[i][j].kodeRuangan);
            } else{
                continue;
            }
            if(isQueueEmpty(config->denah.contents[i][j].antrian)){
                continue;
            } else{
                Node* current = config->denah.contents[i][j].antrian->front;
                int count = 0;

                while (current != NULL) {
                    int idxPasien = cariIdxUser(listUser, current->data);
                    if (count < config->kapasitasRuangan) {
                        strcpy(listUser->buffer[idxPasien].ruang, config->denah.contents[i][j].kodeRuangan);
                    } else {
                        strcpy(listUser->buffer[idxPasien].antrian, config->denah.contents[i][j].kodeRuangan);
                    }
                    count++;
                    current = current->next;
                }
            }
        }
    }
    
    return 1;
}