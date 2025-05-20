#ifndef PARSE_CONFIG_H
#define PARSE_CONFIG_H
#include <stdio.h>
#include "config.h"
#include "user.h"

void readConfig(char * folderPath, Config * rumahsakit, ListDinUser * UserData);
void writeConfig(const Config *rs);

#endif