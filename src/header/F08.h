#ifndef F08_H
#define F08_H
#include "user.h"
#include "colors.h"
#include "to-lower.h"
#include <stdio.h>

#include "F07.h"

void findBased(int * base, int type);
int binSearchId(ListDinUser * UserData, int id);
int seqSearchName(ListDinUser * UserData, char * name);
void findId(ListDinUser * UserData, int type);
void findName(ListDinUser * UserData, int type);
void tampilPenyakit(User *ptrs[], int base, int order, int length, char * penyakit);
void findPenyakit(ListDinUser * UserData);

void cariUser(ListDinUser * UserData);
void cariPasien(ListDinUser * UserData);
void cariDokter(ListDinUser * UserData);

#endif