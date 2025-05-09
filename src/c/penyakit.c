#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/penyakit.h"

void createListPenyakit(ListPenyakit *list, int capacity){
    list->nEff = 0;
    list->capacity = capacity;
    list->items = (Penyakit*) malloc (capacity*sizeof(Penyakit));
}

void printListPenyakit(ListPenyakit list){
    for(int i = 0; i < list.nEff; i++){
        printf("%d, %s, %f, %f, %d, %d, %d, %d, %d, %d, %f, %f, %d, %d, %f, %f, %d, %d, %d, %d, %d, %d\n", 
            list.items[i].id, list.items[i].nama_penyakit ,list.items[i].suhu_tubuh_min, list.items[i].suhu_tubuh_max,
            list.items[i].tekanan_darah_sistolik_min, list.items[i].tekanan_darah_sistolik_max, list.items[i].tekanan_darah_diastolik_min, list.items[i].tekanan_darah_diastolik_max ,
            list.items[i].detak_jantung_min, list.items[i].detak_jantung_max ,list.items[i].saturasi_oksigen_min, list.items[i].saturasi_oksigen_max,
            list.items[i].kadar_gula_darah_min, list.items[i].kadar_gula_darah_max ,list.items[i].berat_badan_min, list.items[i].berat_badan_max,    
            list.items[i].tinggi_badan_min, list.items[i].tinggi_badan_max ,list.items[i].kadar_kolesterol_min, list.items[i].kadar_kolesterol_max,
            list.items[i].trombosit_min, list.items[i].trombosit_max);
    }
}

void insertPenyakit(ListPenyakit *list, Penyakit item){
    list->items[list->nEff] = item;
    list->nEff++; 
}