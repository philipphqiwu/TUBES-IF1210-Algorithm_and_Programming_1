#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/map.h"
#include "../header/obat-penyakit.h"

void createMapObatPenyakit(MapObatPenyakit *map){
    for(int i = 0; i < MAX_MAP_SIZE; i++){
        map->items[i].penyakit_id = 0;
        for(int j = 0; j < MAX_OBAT_PER_PENYAKIT; j++){
            map->items[i].value[j].obat_id = 0;
        }
    }
    map->size = 0;
}

void insertObatPenyakitByID(MapObatPenyakit *map, MapPairObatPenyakit item){
    map->items[item.penyakit_id] = item;
    if(item.penyakit_id >= map->size){
        map->size = item.penyakit_id + 1;
    }
}

void insertObatPenyakitByRawData(MapObatPenyakit *map, int obatId, int penyakitId, int urutanMinum){
    map->items[penyakitId].penyakit_id = penyakitId;
    map->items[penyakitId].value[urutanMinum].urutan_minum = urutanMinum;
    map->items[penyakitId].value[urutanMinum].obat_id = obatId;
    if(penyakitId >= map->size){
        map->size = penyakitId + 1;
    }
}

void printMapObatPenyakit(MapObatPenyakit map){
    for(int i = 0; i < map.size; i++){
        if(!map.items[i].penyakit_id){
            continue;
        }
        printf("PenyakitId: %d\n", map.items[i].penyakit_id);
        for(int j = 0; j < MAX_OBAT_PER_PENYAKIT; j++){
            if(!map.items[i].value[j].obat_id){
                continue;
            }
            printf("\t%d. ObatId: %d\n", map.items[i].value[j].urutan_minum, map.items[i].value[j].obat_id);
        }
    }
}

void writeMapObatPenyakit( char * folderPath, MapObatPenyakit * mapObatPenyakit){
    char fullFilePath[300];
    snprintf(fullFilePath, sizeof(fullFilePath),"%s/obat_penyakit.csv", folderPath ); 
    FILE * file = fopen(fullFilePath, "w");
    fprintf(file, "obat_id;penyakit_id;urutan_minum\n");
    for(int i = 0; i < mapObatPenyakit->size; i++){
        if(!mapObatPenyakit->items[i].penyakit_id){
            continue;
        }
        for(int j = 0; j < MAX_OBAT_PER_PENYAKIT; j++){
            if(mapObatPenyakit->items[i].value[j].urutan_minum){
                fprintf(file, "%d;%d;%d\n", mapObatPenyakit->items[i].value[j].obat_id, mapObatPenyakit->items[i].penyakit_id, mapObatPenyakit->items[i].value[j].urutan_minum);
            }
            
        }
    }

    fclose(file);
}