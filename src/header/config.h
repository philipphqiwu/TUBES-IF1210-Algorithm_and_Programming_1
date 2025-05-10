#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>

typedef struct{
    int roomRow;
    int roomCol;
    int roomCapacity;
    int room[260][100];
    int jumlahPemilikobat;
    int inventoryPasien[260*99][6];
} Config;

#endif
