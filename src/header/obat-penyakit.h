#ifndef OBAT_PENYAKIT_H
#define OBAT_PENYAKIT_H
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBAT_PER_PENYAKIT 10

typedef struct{
    int obat_id;
    int urutan_minum;
} ValueObat;

typedef struct {
    int penyakit_id; //ini key
    ValueObat value[MAX_OBAT_PER_PENYAKIT];
} MapPairObatPenyakit;

typedef struct {
    MapPairObatPenyakit items[MAX_MAP_SIZE]; // max = 100
    int size;
} MapObatPenyakit;

// Menginisialisasi map
void createMapObatPenyakit(MapObatPenyakit *map);
// I.S. map terdefinisi dan sembarang
// F.S. map.size bernilai 0, setiap elemen memiliki nilai penyakit_id = 0
//      setiap elemen memiliki value dengan obat_id = 0

// Menambahkan data berdasarkan ID penyakit
void insertObatPenyakitByID(MapObatPenyakit *map, MapPairObatPenyakit item);
// I.S. map dan item terdefinisi. item.obat_id bernilai dan dapat menjadi indeks yang valid.
// F.S. map.items[item.penyakit_id] terisi dengan data pada item
//      jika item.penyakit_id >= map.size, maka map.size = item.penyakit_id + 1

// Menambahkan data berdasarkan data raw dari .csv
void insertObatPenyakitByRawData(MapObatPenyakit *map, int obatId, int penyakitId, int urutanMinum);
// I.S. map, obatId, penyakitId, dan urutanMinum terdefinisi. indeks pada penyakitId valid.
// F.S. map.items[penyakitId].penyakit_id = penyakitId
//      map.items[penyakitId].value[urutanMinum].urutan_minum = urutanMinum
//      map.items[penyakitId].value[urutanMinum].obat_id = obatId
//      jika item.penyakit_id >= map.size, maka map.size = item.penyakit_id + 1

// Mencetak map obat penyakit
void printMapObatPenyakit(MapObatPenyakit map);
// I.S. map terdefinisi
// F.S. Tercetak pada terminal/layar seluruh isi data pada map

void writeMapObatPenyakit(char * folderPath, MapObatPenyakit * mapObatPenyakit);
#endif