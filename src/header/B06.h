#ifndef B06_H
#define B06_H
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"
#include "colors.h"

// Memindahkan pasien ke antrian paling depan.
void skipAntrian(int loginID, Config *config, ListDinUser listUser);
// I.S. Semua argumen terdefinisi, loginID adalah ID pasien.
// F.S. Posisi pasien dalam antrian menjadi terdepan jika pasien terdapat pada antrian.
//      Selain itu, tidak dilakukan apapun.

// Menghapus pasien dari antrian.
void cancelAntrian(int loginID, Config *config, ListDinUser *listUser);
// I.S. Semua argumen terdefinisi, loginID adalah ID pasien.
// F.S. Pasien hilang dari antrian yang ditempatinya jika pasien terdapat pada antrian.
//      Selain itu, tidak dilakukan apapun.

#endif