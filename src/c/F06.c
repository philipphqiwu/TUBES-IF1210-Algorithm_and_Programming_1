#include <stdio.h>
#include "../header/F06.h"


void LIHAT_DENAH() {
    // Rows dan cols akan menggunakan parse_config
    printf("      ");                      
    for (int c = 1; c <= cols; c++) {
        printf("%-5d", c);               
    }
    printf("\n");

    printf("   +");
    for (int c = 1; c <= cols; c++) {
        printf("-----+");
    }
    printf("\n");

    for (int r = 0; r < rows; r++) {
        char rowLabel = 'A' + r;         
  
        printf(" %c |", rowLabel);
        for (int c = 1; c <= cols; c++) {

            printf(" %c%d  |", rowLabel, c);
        }
        printf("\n");
        printf("   +");
        for (int c = 1; c <= cols; c++) {
            printf("-----+");
        }
        printf("\n");
    }
}
void LIHAT_RUANGAN(char koderuangan[2]){
    printf("--- Detail Ruangan %s ---\n", koderuangan);
    printf("            : %d\n", kapasistas);
    if (namadokter == NULL){
        printf("            : -\n");
    }
    else{
        printf("            : %s\n" namadokter);
    }
    printf("Pasien di dalam ruangan:\n");
    if (banyakpasien == 0){
        printf("   Tidak ada pasien di dalam ruangan saat ini.\n");
    }
    else{
        for(int i = 0; i < banyakpasien; i++){
            printf("    %d. %s\n", i, pasien[i]);
        }
    }
}