#include <stdlib.h>
#include <string.h>
#include "set.h"

void createSet(Set *s, int capacity){
    s->data = (ElType *)malloc(capacity * sizeof(ElType));
    s->nEff = 0;
    s->capacity = capacity;
}

void freeSet(Set *s){
    free(s->data);
    s->nEff = 0;
    s->capacity = 0;
}

int setContain(Set *s, ElType data){
    for(int i = 0; i < s->nEff; i++){
        if(s->data[i] == data){
            return 1;
        }
    }
    return 0;
}

int setIndeksOf(Set *s, ElType data){
    if(setContain(s, data)){
        for(int i = 0; i < s->nEff; i++){
            if(s->data[i] == data){
                return i;
            }
        }
    }
    else{
        printf("Tidak ada data terkait.\n");
    }
}

void setInsert(Set *s, ElType data){
    if(!setContain(s, data) && s->nEff < s->capacity){
        strcpy(s->data[s->nEff], data);
        s->nEff++;
    }
    else if(setContain(s,data)){
        printf("Data sudah ada.\n");
    }
    else{
        printf("Set penuh.\n");
    }
}

void setDelete(Set *s, ElType data){
    if(setContain(s, data)){
        strcpy(s->data[s->nEff], data);
        s->nEff++;
    }
    else if(setContain(s,data)){
        printf("Data sudah ada.\n");
    }
    else{
        printf("Set penuh.\n");
    }
}

int setGetSize(Set *s){
    return s->nEff;
}