#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/penyakit.h"

void createListPenyakit(ListPenyakit *list, int capacity){
    list->nEff = 0;
    list->capacity = capacity;
    list->items = (Penyakit*) malloc (capacity*sizeof(Penyakit));
    for(int i = 0; i < capacity; i++){
        list->items[i].id = 0;
    }
}

void printListPenyakit(ListPenyakit list){
    for(int i = 0; i < list.nEff; i++){
        if(list.items[i].id == 0) continue;
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

void insertPenyakitByID(ListPenyakit *list, Penyakit item){
    list->items[item.id] = item;
    if(list->nEff <= item.id){
        list->nEff = item.id + 1;
    }
}

int searchIDByName(ListPenyakit list, char nama[]){
    int result = -1;
    for(int i = 0; i < list.nEff && result == -1; i++){
        if(!list.items[i].id){ // Ketika elemen tidak terisi
            continue;
        }
        if(!strcmp(list.items[i].nama_penyakit, nama)){
            result = i;
        }
    }
    return result;
}

void freeListPenyakit(ListPenyakit *list){
    free(list->items);
    list->nEff = 0;
    list->capacity = 0;
}

void writeListPenyakit(char * folderPath, ListPenyakit *list){
    char fullFilePath[300];
    snprintf(fullFilePath, sizeof(fullFilePath), "%s/penyakit.csv", folderPath); 
    FILE * file = fopen(fullFilePath, "w");
    fprintf(file, "id;nama_penyakit;suhu_tubuh_min;suhu_tubuh_max;tekanan_darah_sistolik_min;tekanan_darah_sistolik_max;tekanan_darah_diastolik_min;tekanan_darah_diastolik_max;detak_jantung_min;detak_jantung_max;saturasi_oksigen_min;saturasi_oksigen_max;kadar_gula_darah_min;kadar_gula_darah_max;berat_badan_min;berat_badan_max;tinggi_badan_min;tinggi_badan_max;kadar_kolesterol_min;kadar_kolesterol_max;trombosit_min;trombosit_max\n");
    for(int i = 1; i<list->nEff; i++){
        fprintf(file, "%d;%s;%f;%f;%d;%d;%d;%d;%d;%d;%f;%f;%d;%d;%f;%f;%d;%d;%d;%d;%d;%d\n", 
            list->items[i].id, list->items[i].nama_penyakit ,list->items[i].suhu_tubuh_min, list->items[i].suhu_tubuh_max,
            list->items[i].tekanan_darah_sistolik_min, list->items[i].tekanan_darah_sistolik_max, list->items[i].tekanan_darah_diastolik_min, list->items[i].tekanan_darah_diastolik_max ,
            list->items[i].detak_jantung_min, list->items[i].detak_jantung_max ,list->items[i].saturasi_oksigen_min, list->items[i].saturasi_oksigen_max,
            list->items[i].kadar_gula_darah_min, list->items[i].kadar_gula_darah_max ,list->items[i].berat_badan_min, list->items[i].berat_badan_max,    
            list->items[i].tinggi_badan_min, list->items[i].tinggi_badan_max ,list->items[i].kadar_kolesterol_min, list->items[i].kadar_kolesterol_max,
            list->items[i].trombosit_min, list->items[i].trombosit_max);
    }

    fclose(file);
}