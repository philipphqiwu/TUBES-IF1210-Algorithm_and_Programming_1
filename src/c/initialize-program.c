#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/initialize-program.h"
#include "../header/general-parsing.h"
#include "../header/parse-user.h"
#include "../header/user.h"
#include "../header/obat.h"
#include "../header/penyakit.h"
#include "../header/obat-penyakit.h"
#include "../header/save.h"

int initializeProgram(char * folderPath, ListDinUser *listUser, ListObat *listObat, ListPenyakit *listPenyakit , MapObatPenyakit *mapObatPenyakit){
    printf("===============\n");
    printf("SELAMAT DATANG\n");
    printf("===============\n");


    char filePathObat[300];
    snprintf(filePathObat, sizeof(filePathObat),"%s/obat.csv", folderPath ); 
    char filePathPenyakit[300];
    snprintf(filePathPenyakit, sizeof(filePathPenyakit),"%s/penyakit.csv", folderPath ); 
    char filePathObatPenyakit[300];
    snprintf(filePathObatPenyakit, sizeof(filePathObatPenyakit),"%s/obat_penyakit.csv", folderPath ); 
    char filePathUser[300];
    snprintf(filePathUser, sizeof(filePathUser),"%s/user.csv", folderPath ); 

    FILE *obatFile = fopen(filePathObat, "r");
    if(!obatFile){
        printf("Gagal membuka file obat.csv\n");
        fclose(obatFile);
        return 0;
    }
    FILE *penyakitFile = fopen(filePathPenyakit, "r");
    if(!penyakitFile){
        printf("Gagal membuka file penyakit.csv\n");
        fclose(obatFile);
        fclose(penyakitFile);
        return 0;
    }
    FILE *obatPenyakitFile = fopen(filePathObatPenyakit, "r");
    if(!obatPenyakitFile){
        printf("Gagal membuka file obat_penyakit.csv\n");
        fclose(obatFile);
        fclose(penyakitFile);
        fclose(obatPenyakitFile);
        return 0;
    }
    FILE *userFile = fopen(filePathUser, "r");
    if(!userFile){
        printf("Gagal membuka file user.csv\n");
        fclose(obatFile);
        fclose(penyakitFile);
        fclose(obatPenyakitFile);
        fclose(userFile);
        return 0;
    }
    char lineInput[1000];
    // Parsing dan pemasukan data user
    // parseUserData(listUser);
    fgets(lineInput, sizeof(lineInput), userFile);
    while(fgets(lineInput, sizeof(lineInput), userFile)){
        User itemUser;
        parsing(lineInput, "issssfiiififiiii", &itemUser.id, itemUser.username, itemUser.password, itemUser.role, itemUser.riwayat_penyakit, &itemUser.suhu_tubuh, &itemUser.tekanan_darah_sistolik, &itemUser.tekanan_darah_diastolik, &itemUser.detak_jantung, &itemUser.saturasi_oksigen, &itemUser.kadar_gula_darah, &itemUser.berat_badan, &itemUser.tinggi_badan, &itemUser.kadar_kolesterol, &itemUser.kadar_kolesterol_ldl, &itemUser.trombosit);
        insertUserByID(listUser, itemUser);
    }
    fclose(userFile);
    // Parsing dan pemasukan data obat
    fgets(lineInput, sizeof(lineInput), obatFile);
    while(fgets(lineInput, sizeof(lineInput), obatFile) != NULL){
        Obat itemObat;
        parsing(lineInput, "is", &itemObat.obat_id, itemObat.nama_obat);
        insertObatByID(listObat, itemObat);
    }
    fclose(obatFile);
    // Parsing dan pemasukan data penyakit
    fgets(lineInput, sizeof(lineInput), penyakitFile);
    while(fgets(lineInput, sizeof(lineInput), penyakitFile) != NULL){
        Penyakit itemPenyakit;
        parsing(lineInput, "isffiiiiiiffiiffiiiiii", &itemPenyakit.id, itemPenyakit.nama_penyakit, &itemPenyakit.suhu_tubuh_min, &itemPenyakit.suhu_tubuh_max, &itemPenyakit.tekanan_darah_sistolik_min, &itemPenyakit.tekanan_darah_sistolik_max, &itemPenyakit.tekanan_darah_diastolik_min, &itemPenyakit.tekanan_darah_diastolik_max, &itemPenyakit.detak_jantung_min, &itemPenyakit.detak_jantung_max, &itemPenyakit.saturasi_oksigen_min, &itemPenyakit.saturasi_oksigen_max,  &itemPenyakit.kadar_gula_darah_min, &itemPenyakit.kadar_gula_darah_max, &itemPenyakit.berat_badan_min, &itemPenyakit.berat_badan_max, &itemPenyakit.tinggi_badan_min, &itemPenyakit.tinggi_badan_max, &itemPenyakit.kadar_kolesterol_min, &itemPenyakit.kadar_kolesterol_max, &itemPenyakit.trombosit_min, &itemPenyakit.trombosit_max);
        insertPenyakitByID(listPenyakit, itemPenyakit);
    }
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
    
    return 1;
}