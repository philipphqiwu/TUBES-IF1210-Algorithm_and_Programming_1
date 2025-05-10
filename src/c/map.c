#include "../header/map.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void initializeMap(Map *m){
    m->size = 0;
}

bool isMapEmpty(const Map *m){
    return (m->size == 0);
}

bool isMapFull(const Map *m){
    return (m->size == MAX_MAP_SIZE);
}

void addMap(Map *m, const char *key, const char *value){
    if(isMapFull(m)){
        printf("Error! Map is full\n");
        return;
    }
    strcpy(m->items[m->size].key, key);
    strcpy(m->items[m->size].value, value);
    m->size++;
}

const char* getMap(Map *m, const char *key){
    for(int i = 0; i < m->size; i++){
        if(strcmp(m->items[i].key, key) == 0){
            return m->items[i].value;
        }
    }
    return NULL;
}

void removeMap(Map *m, const char *key){
    for(int i = 0; i < m->size; i++){
        if(strcmp(m->items[i].key, key) == 0){
            //geser elemen berikutnya ke kiri
            for(int j = i; j < m->size - 1; j++){
                strcpy(m->items[j].key, m->items[j+1].key);
                strcpy(m->items[j].value, m->items[j+1].value);
            }
            m->size--;
            return;
        }
    }
    printf("Key not found.\n");
}

void printMap(const Map *m){
    if (isMapEmpty(m)) {
        printf("Maaf, map saat ini sedang kosong.\n");
        return;
    }

    printf("Berikut adalah isi dari current map.\n");
    printf("---------------------------------\n");
    printf(" %-20s | %-20s \n", "Key", "Value");  //ini buat header tabel
    printf("---------------------------------\n");

    for (int i = 0; i < m->size; i++) {
        printf(" %-20s | %-20s \n", m->items[i].key, m->items[i].value);
    }

    printf("---------------------------------\n");
    printf("Total entri: %d\n", m->size);
}