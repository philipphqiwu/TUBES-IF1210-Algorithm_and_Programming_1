#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include "config_queue.h"
#include "matriks.h"


#define Max_ruangan 260
#define Max_pasien 100
#define Max_obat 6
#define CAPCITYANTRIAN 50
#define CAPACITYRUANGAN 50


typedef struct{
    int idDokter;
    char kodeRuangan[3];
    int ruangan[CAPACITYRUANGAN]; //😊 Hi!
    QueueConfig antrian;
}roomComponent;

typedef struct{
    int roomRow;
    int roomCol;
    int roomCapacity;
    int queueCapacity;
    roomComponent room[Max_ruangan];
    int jumlahPemilikobat;
    Matriks inventoryPasien;
    } Config;

void writeConfig(Config *rumahsakit, ListDinUser *UserData);
void readConfig(Config *rumahsakit, ListDinUser *UserData);

#endif
