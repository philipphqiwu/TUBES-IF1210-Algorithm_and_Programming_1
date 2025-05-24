#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/config.h"
#include "../header/parse-config.h"

// void readConfig(char * folderPath, Config * Config){
//     char filePathConfig[MAX_FILE_PATH_CHAR];
//     snprintf(filePathConfig, sizeof(filePathConfig),"%s/obat.txt", folderPath );
//     FILE *configFile = fopen(filePathConfig, "r");
//     if(!configFile){
//         printf("Gagal membuka file config.txt\n");
//         fclose(configFile);
//         return 0;
//     }
//     char lineInput[MAX_INPUT_CHAR];
//     char parsedInput[MAX_PARSED_INPUT_CHAR];
//     fgets(lineInput, sizeof(lineInput), configFile);
    
// }