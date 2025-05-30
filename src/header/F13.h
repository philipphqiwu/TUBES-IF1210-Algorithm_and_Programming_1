#ifndef F13_H
#define F13_H
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"
#include "colors.h"

// "Memulangkan" pasien dengan mengeluarkannya dari antrian serta mereset data user.
void pulangDok(int loginID, Config *config, ListDinUser *listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit);
// I.S. Semua argumen terdefinisi.
// F.S. Pasien dengan ID = loginID keluar antrian dan datanya terreset jika
//      - pasien ada pada antrian urutan pertama,
//      - pasien sudah didagnosis, diobatin, dan sudah minum obat sesuai urutannya.

// Mengecek apakah obat yang diminum pasien sesuai dengan urutannya.
int cekPerutDenganUrutan(Stack perut, int penyakitID, MapObatPenyakit mapObatPenyakit);
// Mengembalikan 0 jika sesuai, i jika tidak (i > 0) dengan i adalah urutan pertama yang salah.

#endif