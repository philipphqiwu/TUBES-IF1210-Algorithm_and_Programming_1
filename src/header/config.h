#include <stdio.h>

FILE * file = fopen("../data/config.txt","r");
    typedef struct{
        int roomRow;
        int roomCol;
        int roomCapacity;
        int room[260][100];
        int jumlahPemilikobat;
        int inventoryPasien[260*99][6];
    }Config;
  