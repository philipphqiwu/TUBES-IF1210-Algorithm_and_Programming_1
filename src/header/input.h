#ifndef INPUT_H
#define INPUT_H
#include <string.h>
#include <stdio.h>
#include "obat.h"
#include "penyakit.h"
#include "user.h"
#include "colors.h"
#include "obat-penyakit.h"
#include "config.h"

// Menerima input 
void input(int * loginState, int * loginId, ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit, MapObatPenyakit * mapObatPenyakit, int * run, Config * rumahsakit);
// I.S. Seluruh argumen terdefinisi
// F.S. Ditampilan menu input

#endif