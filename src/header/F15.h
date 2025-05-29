#ifndef F15_H
#define F15_H
#include "user.h"
#include "config.h"
#include "queue.h"
#include <stdio.h>

void antrianSaya(ListDinUser *UserData, Config *rumahsakit, int loginId);
const char* cari_user(ListDinUser UserData, int ID);

#endif