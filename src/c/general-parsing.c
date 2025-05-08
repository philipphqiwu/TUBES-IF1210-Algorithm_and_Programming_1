#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "general-parsing.h"

void parsing(char *input, int dataCount, ...){
    va_list args;
    va_start(args, dataCount);
    int indeksGet = 0;
    for(int i = 0; i < dataCount; i++){
        char parsedInput[20];
        int indeksPut = 0;
        char * output = va_arg(args, char *);
        while(input[indeksGet] != ','){
            parsedInput[indeksPut] = input[indeksGet];
            indeksGet++;
            indeksPut++;
        }
        parsedInput[indeksPut] = '\0';
        strcpy(output, parsedInput);
        indeksGet++;
    }
}