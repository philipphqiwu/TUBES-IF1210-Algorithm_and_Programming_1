#ifndef OBAT_PENYAKIT_H
#define OBAT_PENYAKIT_H
#include "map.h"

typedef struct{
    int id_obat;
    int urutan_minum;
}Value;

typedef struct {
    int penyakit_id; //ini key
    Value value[10];
}MapPair;

typedef struct {
    MapPair items[MAX_MAP_SIZE];
    int size;
}Map;

#endif