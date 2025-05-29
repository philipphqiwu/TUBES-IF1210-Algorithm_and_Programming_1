#ifndef F11_H
#define F11_H
#include "user.h"
#include "penyakit.h"
#include <stdio.h>
#include "config.h"

int cekPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien);
boolean assignPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien);
boolean punyaRiwayat(char* riwayat_penyakit);
int diagnosis(ListPenyakit krirteriapenyakit, Config rumahsakit, ListDinUser *UserData, int loginId);

#endif