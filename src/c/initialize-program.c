#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialize-program.h"
#include "general-parsing.h"
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"

int initializeProgram(ListObat *listObat, ListPenyakit *ListPenyakit){
    printf("===============\n");
    printf("SELAMAT DATANG\n");
    printf("===============\n");

    FILE *userFile = fopen("data/obat.csv", "r");
    FILE *obatFile = fopen("data/obat.csv", "r");
    FILE *penyakitFile = fopen("data/obat.csv", "r");
    FILE *obatPenyakitFile = fopen("data/obat.csv", "r");
    
    // Parsing dan pemasukan data obat
    char lineInput[1000];
    fgets(lineInput, sizeof(lineInput), obatFile);
    while(fgets(lineInput, sizeof(lineInput), obatFile)){
        Obat item;
        parsing(lineInput, "is", 2, &item.obat_id, item.nama_obat);
    }
    while(fgets(lineInput, sizeof(lineInput), penyakitFile)){
        Penyakit item;
        parsing(lineInput, "isffiiiiiiffiiffiiiiii", 22, &item.id, item.nama_penyakit, &item.suhu_tubuh_min, &item.suhu_tubuh_max, &item.tekanan_darah_sistolik_min, &item.tekanan_darah_sistolik_max, &item.tekanan_darah_diastolik_min, &item.tekanan_darah_diastolik_max, &item.detak_jantung_min, &item.detak_jantung_max, &item.kadar_gula_darah_min, &item.kadar_gula_darah_max, &item.berat_badan_min, &item.berat_badan_max, &item.berat_badan_min, &item.berat_badan_max, &item.tinggi_badan_min, &item.tinggi_badan_max, &item.kadar_kolesterol_min, &item.kadar_kolesterol_max, &item.trombosit_min, &item.trombosit_max);
    }
}