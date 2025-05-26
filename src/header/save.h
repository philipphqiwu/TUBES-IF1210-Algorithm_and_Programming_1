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

int isValidFolderName(const char *name);
int folderExists(const char *path);
void save(ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit,  MapObatPenyakit * mapObatPenyakit, Config * rumahsakit);
#endif