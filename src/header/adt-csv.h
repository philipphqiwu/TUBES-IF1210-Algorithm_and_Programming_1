#ifndef ADT_CSV_H
#define ADT_CSV_H
#include <stdio.h>

typedef struct{
    int obat_id;
    char nama_obat[20]; 
} Obat;

#endif

typedef struct{
    int obat_id;
    int penyakit_id;
    int urutan_minum;
} ObatPenyakit;

typedef struct{
    int id;
    char nama_penyakit[20];
    float suhu_tubuh_min;
    float suhu_tubuh_max;
    int tekanan_darah_sistole;
    int tekanan_datah_diastole;
    int detak_jantung_min;
    int detak_jantung_max;
    int saturasi_oksigen_min;
    int saturasi_oksigen_max;
    int kadar_gula_darah_min;
    int kadar_gula_darah_max;
    int berat_badan_min;
    int berat_badan_max;
    int kadar_kolesterol_min;
    int kadar_kolesterol_max;
    int trombosit_min;
    int trombosit_max;
} Penyakit;
