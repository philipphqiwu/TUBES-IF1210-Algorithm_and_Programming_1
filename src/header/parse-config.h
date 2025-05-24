#ifndef PARSE_CONFIG_H
#define PARSE_CONFIG_H
#include <stdio.h>
#include "config.h"

#define MAX_FILE_PATH_CHAR 300
#define MAX_INPUT_CHAR 1000
#define MAX_PARSED_INPUT_CHAR 100

void readConfig(char * folderPath, Config * Config);
void writeConfig(const Config *rs);

#endif