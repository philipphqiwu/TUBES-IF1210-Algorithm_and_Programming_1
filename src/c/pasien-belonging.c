#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pasien-belonging.h"

void createListPasienBelonging(ListPasienBelonging *list, int capacity){
    list->nEff = 0;
    list->capacity = capacity;
    list->items = (PasienBelonging*) malloc (capacity*sizeof(PasienBelonging));
}

void printListPasienBelonging(ListPasienBelonging list){
    for(int i = 0; i < list.nEff; i++){
        if(list.items[i].pasienID == 0){
            continue;
        }
        printf("Pasien id: %d\n", list.items[i].pasienID);
        printf("Inventory (dalam id):\n");
        for(int j = 0; j < INVENTORY_CAP; j++){
            printf("%d ", list.items[i].inventory[j]);
        }
        printf("\n");
        printf("Perut (dalam id):\n");
        for(int j = 0; j < PERUT_CAP; j++){
            printf("%d ", list.items[i].perut[j]);
        }
        printf("\n");
    }
}

void insertPasienBelonging(ListPasienBelonging *list, PasienBelonging item){
    list->items[list->nEff] = item;
    list->nEff++; 
}

void insertPasienBelongingByID(ListPasienBelonging *list, PasienBelonging item){
    list->items[item.pasienID] = item;
    if(list->nEff <= item.pasienID){
        list->nEff = item.pasienID + 1;
    }
}

void freeListPasienBelonging(ListPasienBelonging *list){
    free(list->items);
    list->nEff = 0;
    list->capacity = 0;
}