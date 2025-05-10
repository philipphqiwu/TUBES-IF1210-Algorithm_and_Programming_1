#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../header/general-parsing.h"

void parsing(char *input, char *format, int dataCount, ...){
    va_list args;
    va_start(args, dataCount);
    int indeksGet = 0;
    for(int i = 0; i < dataCount; i++){
        char parsedInput[100];
        int indeksPut = 0;
        while(input[indeksGet] != ',' && input[indeksGet] != ';' && input[indeksGet] != '\n' && input[indeksGet] != '\0'){
            // printf("debug %c ", input[indeksGet]);
            // printf("\n");
            parsedInput[indeksPut] = input[indeksGet];
            // printf("debug %c ", parsedInput[indeksPut]);
            // printf("\n");
            indeksGet++;
            indeksPut++;
        }
        parsedInput[indeksPut] = '\0';
        if(format[i] == 'i'){
            int* output;
            output = va_arg(args, int*);
            *output = atoi(parsedInput);
        }
        else if(format[i] == 'c'){
            char* output;
            output = va_arg(args, char*);
            *output = parsedInput[0];
        }
        else if(format[i] == 'f'){
            float* output;
            output = va_arg(args, float*);
            *output = atof(parsedInput);
        }
        else if(format[i] == 's'){
            char* output;
            output = va_arg(args, char*);
            strcpy(output, parsedInput);
        }
        indeksGet++;
    }
    va_end(args);
}