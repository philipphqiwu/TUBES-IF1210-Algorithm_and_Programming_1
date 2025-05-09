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
        printf("%d %s\n", list.items[i].obat_id, list.items[i].nama_obat);
    }
}

void insertObat(ListObat *list, Obat item){
    list->items[list->nEff] = item;
    list->nEff++; 
}