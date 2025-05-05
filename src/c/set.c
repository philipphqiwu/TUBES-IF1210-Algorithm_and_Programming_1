#include <stdlib.h>
#include <string.h>
#include "../header/set.h"

void createSet(Set *s, int capacity){
    s->data = (SetElType *)malloc(capacity * sizeof(SetElType));
    s->nEff = 0;
    s->capacity = capacity;
}

void freeSet(Set *s){
    free(s->data);
    s->nEff = 0;
    s->capacity = 0;
}

int setContain(Set *s, SetElType data){
    for(int i = 0; i < s->nEff; i++){
        if(strcmp(s->data[i], data) == 0){
            return 1;
        }
    }
    return 0;
}

int setIndeksOf(Set *s, SetElType data){
    if(setContain(s, data)){
        for(int i = 0; i < s->nEff; i++){
            if(strcmp(s->data[i], data) == 0){
                return i;
            }
        }
    }
    return -1; // undefined index
    
}

void setInsert(Set *s, SetElType data){
    if(!setContain(s, data) && s->nEff < s->capacity){
        strcpy(s->data[s->nEff], data);
        s->nEff++;
    }
}

void setDelete(Set *s, SetElType data){
    if(setContain(s, data)){
        strcpy(s->data[s->nEff], data);
        s->nEff++;
    }
}

int setGetSize(Set *s){
    return s->nEff;
}