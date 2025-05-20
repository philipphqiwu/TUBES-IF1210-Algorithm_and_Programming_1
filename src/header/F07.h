#ifndef F07_H
#define F07_H
#include "user.h"
#include "to-lower.h"
#include <string.h>
#include <stdio.h>

void sortBased(int * base, int * order);
void alphabetSort(User *ptrs[], int length);
void tampilList(User *ptrs[], int type, int base, int order, int length);
void lihatUser(ListDinUser UserData);
void lihatPasien(ListDinUser UserData);
void lihatDokter(ListDinUser UserData);

#endif