#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include "user.h"
#include "config_queue.h"
#include "matriks.h"
#include "matriks-denah.h"
#include "stack-linked.h"

#define MAX_PASIEN 1000
#define MAX_OBAT 10

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
    int jumlahPerutPasien;
    Stack perutPasien[MAX_PASIEN];
} Config;

// Menginisialisasi struktur data config
void createConfig(Config *config);
// I.S. config terdefinisi, sembarang
// F.S. seluruh komponen config terinisialisasi dengan nilai default

// Menampilkan data config pada layar
void printConfig(Config config);
// I.S. config terdefinisi dan terisi
// F.S. seluruh data pada config tampil pada layar

// void writeConfig(Config *rumahsakit, ListDinUser *UserData);
// void readConfig(Config *rumahsakit, ListDinUser *UserData);

#endif
