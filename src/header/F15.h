#ifndef F15_H
#define F15_H
#include "user.h"
#include "config.h"
#include "queue.h"
#include "colors.h"
#include <stdio.h>

// Menampilkan antrian pasien.
void antrianSaya(ListDinUser *UserData, Config *rumahsakit, int loginId);
// I.S. Semua argumen terdefinisi, loginId adalah ID pasien.
// F.S. Ditampilkan pada layar antrian yang sedang ditempati pasien.

#endif