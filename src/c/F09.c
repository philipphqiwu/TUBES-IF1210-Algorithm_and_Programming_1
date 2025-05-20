#include "../header/F09.h"
#include "../header/config.h"
#include "../header/user.h"
#include <stdio.h>

const char* cari_username(ListDinUser UserData, int id) {
    for (int i = 0; i < UserData.nEff; i++) {
        if (UserData.buffer[i].id == id) {
            return UserData.buffer[i].username;
        }
    }
    return "-";
}

char ruangan[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                    'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
                    ,'V', 'W', 'X','Y','Z'};

void lihatAntrian(Config rumahsakit, ListDinUser UserData){

    printf("    ");
    for(int j = 0; j < rumahsakit.roomCol; j++) {
        printf("  %d  ", j+1);
    }
    printf("\n");

    printf("   +");
    for(int j = 0; j < rumahsakit.roomCol; j++) {
        printf("-----+");
    }
    printf("\n");


    for(int i = 0; i < rumahsakit.roomRow; i++) {

        printf(" %c |", ruangan[i]);
        for(int j = 0; j < rumahsakit.roomCol; j++) {
             printf(" %c%-2d |", ruangan[i], j+1); 
        }
        printf("\n");


        printf("   +");
        for(int j = 0; j < rumahsakit.roomCol; j++) {
            printf("-----+");
        }
        printf("\n");
    }

    char koderuangan[100];
    int baris = koderuangan[0] - 'A';
    int kolom = atoi(koderuangan + 1) - 1;
    int indeks = baris * rumahsakit.roomCol + kolom;


}