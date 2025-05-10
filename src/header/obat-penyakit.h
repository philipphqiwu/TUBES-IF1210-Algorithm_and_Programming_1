#ifndef OBAT_PENYAKIT_H
#define OBAT_PENYAKIT_H
#include "map.h"

typedef struct{
    int id_obat;
    int urutan_minum;
} ValueObat;

typedef struct {
    int penyakit_id; //ini key
    ValueObat value[10];
} MapPairObatPenyakit;

typedef struct {
    MapPairObatPenyakit items[MAX_MAP_SIZE];
    int size;
} MapObatPenyakit;

#endif