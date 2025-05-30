#ifndef F12_H
#define F12_H
#include <stdio.h>
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"
#include "colors.h"

// Memberikan obat pada pasien antrian pertama yang sedang dilayani oleh dokter.
void ngobatin(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit);
// I.S. Semua argumen terdefinisi, loginID merupakan ID dokter.
// F.S. Obat yang sesuai dengan penyakit pasien dimasukkan ke dalam inventory pasien yang dilayani dengan syarat
//      - dokter terassign pada ruangan,
//      - terdapat pasien dalam ruangan,
//      - pasien sudah check-up,
//      - pasien sudah terdiagnosis,
//      - pasien belum mendapatkan obat.

#endif