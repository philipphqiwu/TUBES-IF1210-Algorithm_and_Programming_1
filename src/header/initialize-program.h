#ifndef INITIALIZE_PROGRAM_H
#define INITIALIZE_PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "obat.h"
#include "penyakit.h"
#include "obat-penyakit.h"
#include "general-parsing.h"
#include "config.h"
#include "save.h"

#define MAX_INPUT_CHAR 1000
#define MAX_FILE_PATH_CHAR 300

// Dijalankan ketika awal program berjalan
int initializeProgram(char * folderPath, ListDinUser *listUser, ListObat *listObat, ListPenyakit *listPenyakit, MapObatPenyakit *mapObatPenyakit, Config *config);
// Mengembalikan nilai 1 bila berhasil, 0 bila gagal

#endif