#ifndef F11_H
#define F11_H
#include "user.h"
#include "penyakit.h"
#include <stdio.h>
#include "config.h"
#include "colors.h"

// Mengembalikan nilai ID penyakit ketika ditemukan penyakit yang sesuai, -1 jika tidak.
int cekPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien);

// Mengembalikan nilai true jika berhasil melakukan assign penyakit, false jika tidak.
boolean assignPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien);
// I.S. Semua argumen terdefinisi.
// F.S. Pasien dalam UserData terassign penyakit pada komponen riwayat_penyakit.

// Mengembalikan nilai true jika riwayat_penyakit terdapat pada data, false jika tidak.
boolean punyaRiwayat(char* riwayat_penyakit);

// Mengembalikan nilai 0
int diagnosis(ListPenyakit kriteriapenyakit, Config rumahsakit, ListDinUser *UserData, int loginId);
// I.S. Semua argumen terdefinisi, loginId merupakan ID dokter.
// F.S. komponen riwayat_penyakit pasien yang dilayani terassign riwayat_penyakit baru sesuai dengan kondisi tubuhnya.

#endif