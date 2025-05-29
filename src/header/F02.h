#ifndef F02_H
#define F02_H
#include "user.h"
#include "colors.h"
#include "to-lower.h"
#include <stdio.h>

// User dapat mendaftarkan akun pasien baru
void registerPasien(ListDinUser * UserData);
// I.S. List UserData terdefinisi
// F.S. Terdapat akun pasien baru di list UserData jikalau usernamenya unik

#endif