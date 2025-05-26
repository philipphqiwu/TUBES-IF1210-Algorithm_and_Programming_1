#include "../header/F18.h"
#include <stdio.h>

void exitProgram(int * run, ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit,  MapObatPenyakit * mapObatPenyakit, Config * rumahsakit){
    while (getchar() != '\n'); // Clear input buffer
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
        save(UserData, listObat, listPenyakit, mapObatPenyakit, rumahsakit);
    } else {
        printf("Data tidak disimpan.\n");
    }
    printf("THANK YOU FOR USING OUR SERVICE !!!");
    *run = 0;
}
