#ifndef F16_H
#define F16_H
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"

// Memberikan opsi kepada user untuk meminum obat.
void minumObat(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit);
// I.S. Seluruh argumen terdefinisi, loginID merupakan ID seorang pasien.
// F.S. Ditampilkan opsi obat yang dapat diminum oleh pasien serta akan memasukan obat ke dalam perut pasien sesuai yang dipilih.

#endif