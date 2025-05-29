#ifndef F14_H
#define F14_H
#include "user.h"
#include "queue.h"
#include "config.h"
#include <stdio.h>

void daftarCheckUp(ListDinUser *UserData, Config *rumahsakit, int loginId);
const char* cari_user(ListDinUser UserData, int ID);

#endif