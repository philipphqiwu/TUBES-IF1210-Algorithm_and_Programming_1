#ifndef SAVE_H
#define SAVE_H
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "config.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int isValidFolderName(const char *name);
int folderExists(const char *path);
void save(ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit, Config * rumahsakit);
#endif