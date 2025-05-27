#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/obat.h"

void createListObat(ListObat *list, int capacity){
    list->nEff = 0;
    list->capacity = capacity;
    list->items = (Obat*) malloc (capacity*sizeof(Obat));
}

void printListObat(ListObat list){
    for(int i = 0; i < list.nEff; i++){
        if(list.items[i].obat_id == 0) continue;
        printf("%d %s\n", list.items[i].obat_id, list.items[i].nama_obat);
    }
}

void insertObat(ListObat *list, Obat item){
    list->items[list->nEff] = item;
    list->nEff++; 
}

void insertObatByID(ListObat *list, Obat item){
    list->items[item.obat_id] = item;
    if(list->nEff <= item.obat_id){
        list->nEff = item.obat_id + 1;
    }
}

void freeListObat(ListObat *list){
    free(list->items);
    list->nEff = 0;
    list->capacity = 0;
}

void sortObat(ListObat *list){
    for(int i = 0; i < list->nEff-1; i++){
        for(int j = 0; j < list->nEff-i-1; j++){
            if(list->items[j].obat_id>list->items[j+1].obat_id){
                Obat temp = list->items[j];
                list->items[j] = list->items[j+1];
                list->items[j+1] = temp;
            }
        }
    }
}

int cariIdxObat(ListObat * list, int id){
    int left = 0;
    int right = list->nEff - 1;
    int mid = (left + right)/2;

    while(left < right){
        if(list->items[mid].obat_id > id){
            right = mid;
            mid = (left+right)/2;
        } else if (list->items[mid].obat_id < id){
            left = mid+1;          
            mid = (left+right)/2;
        } else if(list->items[mid].obat_id == id){
            break;
        }
    }
    if(list->items[mid].obat_id == id){
        return mid;
    }
    return -1;
}

void writeListObat(char * folderPath, ListObat *list){
    char fullFilePath[300];
    snprintf(fullFilePath, sizeof(fullFilePath),"%s/obat.csv", folderPath ); 
    FILE * file = fopen(fullFilePath, "w");
    fprintf(file, "obat_id;nama_obat\n");
    for(int i = 0; i<list->nEff; i++){
        fprintf(file, "%d;%s\n", list->items[i].obat_id, list->items[i].nama_obat);
    }

    fclose(file);
}