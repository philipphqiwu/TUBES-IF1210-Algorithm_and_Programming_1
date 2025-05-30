#ifndef F17_H
#define F17_H
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"
#include "colors.h"

// Mengeluarkan obat yang ada pada bagian TOP perut
void minumPenawar(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit);
// I.S. Seluruh argumen terdefinisi, loginID merupakan ID seorang pasien.
// F.S. Obat yang ada di TOP perut dikeluarkan dan dimasukan ke dalam inventory pasien.

#endif