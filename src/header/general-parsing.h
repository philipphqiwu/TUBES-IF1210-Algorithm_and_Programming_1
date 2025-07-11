#ifndef GENERAL_PARSING_H
#define GENERAL_PARSING_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Parsing untuk .csv file
void parsing(char *input, char *format, ...);
// I.S. input terdefinisi, variabel untuk tujuan pemasukan terdefinisi
// F.S. variabel tujuan berisi data yang didapat dari input

// Parsing untuk .txt file
void configParsing(char *input, char *format, ...);
// I.S. input terdefinisi, variabel untuk tujuan pemasukan terdefinisi
// F.S. variabel tujuan berisi data yang didapat dari input

#endif