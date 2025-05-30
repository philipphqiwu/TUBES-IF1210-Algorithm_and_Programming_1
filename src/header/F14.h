#ifndef F14_H
#define F14_H
#include "user.h"
#include "queue.h"
#include "config.h"
#include "colors.h"
#include <stdio.h>

// Mendaftarkan pasien ke dalam suatu ruangan sesuai pilihannya.
void daftarCheckUp(ListDinUser *UserData, Config *rumahsakit, int loginId);
// I.S. Semua argumen terdefinisi, loginId merupakan ID pasien.
// F.S. Pasien yang belum terdaftar akan disuruh untuk mengisi data kondisi tubuh,
//      lalu memilih ruangan yang terdapat dokter di dalamnya dan antriannya tidak penuh.
//      Pasien akan masuk ke dalam antrian pada ruangan yang dipilih.

#endif