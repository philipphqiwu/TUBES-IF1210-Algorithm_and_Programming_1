#ifndef F06_H
#define F06_H
#include <stdio.h>
#include "colors.h"
#include "config.h"

// User dapat melihat denah rumah sakit
void lihatDenah(Config rumahsakit);
// I.S. Config terdefinisi dan terisi
// F.S. Ditampilkan denah dari rumah sakit

// Manager dapat melihat isi ruangan dari suatu ruang
void lihatRuangan(Config rumahsakit, ListDinUser UserData);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilkan isi ruangan, id dokter, id-id pasien yang berada di dalam ruangan

#endif