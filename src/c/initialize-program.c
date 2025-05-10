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

int initializeProgram(ListDinUser *listUser, ListObat *listObat, ListPenyakit *ListPenyakit){
    printf("===============\n");
    printf("SELAMAT DATANG\n");
    printf("===============\n");

    FILE *obatFile = fopen("../data/obat.csv", "r");
    if(!obatFile){
        printf("Gagal membuka file obat.csv\n");
        return -1;
    }
    FILE *penyakitFile = fopen("../data/penyakit.csv", "r");
    if(!penyakitFile){
        printf("Gagal membuka file penyakit.csv\n");
        return -1;
    }
    FILE *obatPenyakitFile = fopen("../data/obat_penyakit.csv", "r");
    if(!obatPenyakitFile){
        printf("Gagal membuka file obat_penyakit.csv\n");
        return -1;
    }

    // Parsing dan pemasukan data user
    parseUserData(listUser);

    // Parsing dan pemasukan data obat
    char lineInput[500];
    fgets(lineInput, sizeof(lineInput), obatFile);
    while(fgets(lineInput, sizeof(lineInput), obatFile)){
        Obat itemObat;
        parsing(lineInput, "is", 2, &itemObat.obat_id, itemObat.nama_obat);
        insertObatByID(listObat, itemObat);
    }
    // Parsing dan pemasukan data penyakit
    while(fgets(lineInput, sizeof(lineInput), penyakitFile)){
        Penyakit itemPenyakit;
        parsing(lineInput, "isffiiiiiiffiiffiiiiii", 22, &itemPenyakit.id, itemPenyakit.nama_penyakit, &itemPenyakit.suhu_tubuh_min, &itemPenyakit.suhu_tubuh_max, &itemPenyakit.tekanan_darah_sistolik_min, &itemPenyakit.tekanan_darah_sistolik_max, &itemPenyakit.tekanan_darah_diastolik_min, &itemPenyakit.tekanan_darah_diastolik_max, &itemPenyakit.detak_jantung_min, &itemPenyakit.detak_jantung_max, &itemPenyakit.kadar_gula_darah_min, &itemPenyakit.kadar_gula_darah_max, &itemPenyakit.berat_badan_min, &itemPenyakit.berat_badan_max, &itemPenyakit.berat_badan_min, &itemPenyakit.berat_badan_max, &itemPenyakit.tinggi_badan_min, &itemPenyakit.tinggi_badan_max, &itemPenyakit.kadar_kolesterol_min, &itemPenyakit.kadar_kolesterol_max, &itemPenyakit.trombosit_min, &itemPenyakit.trombosit_max);
        insertPenyakitByID(ListPenyakit, itemPenyakit);
    }

    // Parsing dan pemasukan data obat_penyakit
    return 1;
}