#ifndef F12_H
#define F12_H
#include <stdio.h>
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"
#include "colors.h"

void ngobatin(int loginID, Config *config, ListDinUser listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit);

#endif