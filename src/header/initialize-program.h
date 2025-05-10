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

// Dijalankan ketika awal program berjalan
int initializeProgram(ListDinUser *listUser, ListObat *listObat, ListPenyakit *ListPenyakit);
// Mengembalikan nilai 1 bila berhasil, 0 bila gagal

#endif