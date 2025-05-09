#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obat.h"

void createListObat(ListObat *list, int capacity){
    Obat obatKosong;
    obatKosong.obat_id = NULL;
    strcpy(obatKosong.nama_obat, "");

    list->items = malloc(capacity * sizeof(Obat));
    if(list->items == NULL){
        perror("Failed to alocate memory for ListObat");
    }
    for(int i = 0; i < capacity; i++){
        list->items[i] = obatKosong;
    }
    list->indeksEmpty = 0;
    list->size = 0;
    list->capacity = capacity;
}

void updateIndeksEmptyListObat(ListObat *list){
    while(1){
        if(list->items[list->indeksEmpty].obat_id == NULL && list->indeksEmpty < list->capacity){
            break;
        }
        list->indeksEmpty++;
    }
}

void increaseCapacityListObat(ListObat *list){
    Obat obatKosong;
    obatKosong.obat_id = NULL;
    strcpy(obatKosong.nama_obat, "");

    int newCapacity = list->capacity*2;
    Obat *newItems = realloc(list->items, newCapacity * sizeof(Obat));
    if(newItems == NULL){
        perror("Failed to increase alocated memory for ListObat");
    }
    for(int i = list->capacity; i < newCapacity; i++){
        list->items[i] = obatKosong;
    }
    list->items = newItems;
    list->capacity = newCapacity;
}

void insertObatByID(ListObat *list, int id, Obat item){
    if(id >= list->capacity){
        increaseCapacityListObat(list);
    }
    list->items[id] = item;
    list->size++;
    updateIndeksEmptyListObat(list);
}

void deleteObat(ListObat *list, int id){
    Obat obatKosong;
    obatKosong.obat_id = NULL;
    strcpy(obatKosong.nama_obat, "");
    list->items[id] = obatKosong;
    if(id == list->size-1){
        list->size--;
    }
    if(id < list->indeksEmpty){
        list->indeksEmpty = id;
    }
}

void freeListObat(ListObat *list){
    free(list->items);
    list->items = NULL;
    list->size = 0;
    list->capacity = 0;
}