#ifndef F18_H
#define F18_H
#include "user.h"
#include "config.h"
#include "colors.h"
#include "obat.h"
#include "penyakit.h"
#include "save.h"
#include <stdio.h>

void exitProgram(int * run, ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit, MapObatPenyakit * mapObatPenyakit, Config * rumahsakit);

#endif