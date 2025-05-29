#ifndef F01_H
#define F01_H
#include "user.h"
#include "colors.h"
#include <stdio.h>
#include <string.h>

// User dapat login ke akun menggunakan username dan password
void login(int * loginState, int * loginId, ListDinUser UserData);
// I.S. Seluruh argumen terdefinisi dan user belum login sebelumnya
// F.S. User terlogin sebagai rolenya dan berdasarkan idnya

#endif