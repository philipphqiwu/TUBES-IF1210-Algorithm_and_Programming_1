#ifndef SAVE_H
#define SAVE_H
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "config.h"
#include "colors.h"
#include <sys/stat.h>
#include <sys/types.h>

// Mengecek apakah nama dapat dijadikan sebagai nama folder di Linux
int isValidFolderName(const char *name);

// Mengecek apakah sudah terdapat folder tertentu
int folderExists(const char *path);

// Menyimpan kondisi rumah sakit
void save(ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit,  MapObatPenyakit * mapObatPenyakit, Config * rumahsakit);
// I.S. Seluruh argumen terdefinisi
// F.S. Data disimpan di dalam suatu folder yang ditentukan user

#endif