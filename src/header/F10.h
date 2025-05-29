#ifndef F10_H
#define F10_H
#include "user.h"
#include "set.h"
#include "to-lower.h"
#include "colors.h"
#include "config.h"
#include <stdio.h>

// Manager dapat menambahkan dokter baru
void tambahDokter(ListDinUser * UserData);
// I.S. List user terdefinisi
// F.S. Terdapat dokter baru di list UserData jikalau usernamenya unik


// Manager dapat meletakkan dokter ke ruangan yang kosong
void assignDokter(ListDinUser * UserData, Config * rumahsakit);
// I.S. Seluruh argumen terdefinisi
// F.S. Dokter diassign ke ruangan yang ditentukan user jikalau dokter belum diassign dan ruangan kosong

#endif