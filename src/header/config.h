#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include <user.h>
#include "config_queue.h"
#include "matriks.h"
#include "matriks-denah.h"


#define MAX_RUANGAN 260
#define MAX_PASIEN 100
#define MAX_OBAT 6
#define CAPCITYANTRIAN 50
#define CAPACITYRUANGAN 50


// typedef struct{
//     char kodeRuangan[3];
//     int idDokter;
//     int ruangan[CAPACITYRUANGAN]; //😊 Hi!
//     QueueConfig antrian;
// } RoomComponent;

// typedef struct{
//     int roomRow;
//     int roomCol;
//     int roomCapacity;
//     int queueCapacity;
//     RoomComponent room[MAX_RUANGAN];
//     int jumlahPemilikobat;
//     Matriks inventoryPasien;
// } Config;

typedef struct{
    MatriksDenah denah;
    int kapasitasRuangan;
    int kapasitasAntrian;
    int jumlahPemilikObat;
    Matriks inventoryPasien;
} Config;

void writeConfig(Config *rumahsakit, ListDinUser *UserData);
void readConfig(Config *rumahsakit, ListDinUser *UserData);

#endif
