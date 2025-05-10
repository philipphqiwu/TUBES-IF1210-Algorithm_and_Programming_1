#include "../header/F18.h"

void exitProgram(int * run){
    char input[100];
    char konfirmasi;
    do {
        printf("Apakah Anda mau melakukan penyimpanan file yang sudah diubah? (y/n) ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        // Check if input is exactly one character and valid
        if (strlen(input) == 1 && (input[0] == 'y' || input[0] == 'n')) {
            konfirmasi = input[0];
            break;
        } else {
            printf("Input tidak valid! Masukkan hanya satu karakter: 'y' atau 'n'.\n\n");
        }
    } while (1);


    if (konfirmasi == 'y') {
        printf("Data akan disimpan.\n");
        //save();
    } else {
        printf("Data tidak disimpan.\n");
    }
    *run = 0;
}
