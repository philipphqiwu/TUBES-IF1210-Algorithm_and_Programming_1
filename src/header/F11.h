#ifndef F11_H
#define F11_H
#include "user.h"
#include "penyakit.h"
#include <stdio.h>
#include "config.h"
#include "colors.h"

int cekPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien);
boolean assignPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien);
boolean punyaRiwayat(char* riwayat_penyakit);
void diagnosis(ListPenyakit krirteriapenyakit, Config rumahsakit, ListDinUser *UserData, int loginId);

#endif