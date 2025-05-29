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
// I.S. Config terdefinisi, sembarang
// F.S. Seluruh komponen config terinisialisasi dengan nilai default

// Menampilkan data config pada layar
void printConfig(Config config);
// I.S. Config terdefinisi dan terisi
// F.S. Seluruh data pada config tampil pada layar

// Menuliskan data config pada file
void writeConfig(char * folderPath, Config *config);
// I.S. Config terdefinisi dan terisi
// F.S. File config.txt berada pada folder yang ditujukan

#endif
