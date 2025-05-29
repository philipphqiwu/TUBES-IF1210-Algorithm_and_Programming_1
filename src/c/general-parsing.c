#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../header/general-parsing.h"

void parsing(char *input, char *format, ...){
    va_list args;
    int dataCount = strlen(format);
    va_start(args, format);
    int indeksGet = 0;
    for(int i = 0; i < dataCount; i++){
        char parsedInput[100];
        int indeksPut = 0;
        while(input[indeksGet] != ',' && input[indeksGet] != ';' && input[indeksGet] != '\n' && input[indeksGet] != '\0'){
            // printf("debug %c ", input[indeksGet]);
            // printf("\n");
            if(input[indeksGet] == '\r'){
                indeksGet++;
                continue;
            }
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

void configParsing(char *input, char *format, ...){
    va_list args;
    int dataCount = strlen(format);
    va_start(args, format);
    int indeksGet = 0;
    for(int i = 0; i < dataCount; i++){
        char parsedInput[100];
        int indeksPut = 0;
        while(input[indeksGet] != ',' && input[indeksGet] != ' ' && input[indeksGet] != ';' && input[indeksGet] != '\n' && input[indeksGet] != '\0'){
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