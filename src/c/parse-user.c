#include "../header/parse-user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void parseUserData(ListDinUser * UserData){
    FILE * file = fopen("../data/user.csv","r");

    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    char c;
    char buffer[100];
    int bufIdx = 0;
    int field = 0;
    User currentUser;

    // Skip header
    while ((c = fgetc(file)) != EOF && c != '\n');

    while ((c = fgetc(file)) != EOF) {
        if (c == ',' || c == '\n') {
            buffer[bufIdx] = '\0';

            switch (field) {
                case 0: currentUser.id = atoi(buffer); break;
                case 1: strcpy(currentUser.username, buffer); break;
                case 2: strcpy(currentUser.password, buffer); break;
                case 3: strcpy(currentUser.role, buffer); break;
                case 4: strcpy(currentUser.riwayat_penyakit, buffer); break;
                case 5: currentUser.suhu_tubuh = atof(buffer); break;
                case 6: currentUser.tekanan_darah_sistolik = atoi(buffer); break;
                case 7: currentUser.tekanan_darah_diastolik = atoi(buffer); break;
                case 8: currentUser.detak_jantung = atoi(buffer); break;
                case 9: currentUser.saturasi_oksigen = atof(buffer); break;
                case 10: currentUser.kadar_gula_darah = atoi(buffer); break;
                case 11: currentUser.berat_badan = atof(buffer); break;
                case 12: currentUser.tinggi_badan = atoi(buffer); break;
                case 13: currentUser.kadar_kolesterol = atoi(buffer); break;
                case 14: currentUser.kadar_kolesterol_ldl = atoi(buffer); break;
                case 15: currentUser.trombosit = atoi(buffer); break;
            }

            bufIdx = 0;
            field++;

            if (c == '\n') {
                insertLast(UserData, currentUser);
                field = 0;
            }
        } else {
            if (bufIdx < 99) {
                buffer[bufIdx++] = c;
            }
        }
    }

    // Insert last user
    if (field > 0) {
        buffer[bufIdx] = '\0';
        if (field == 15) currentUser.trombosit = atoi(buffer);
        insertLast(UserData, currentUser);
    }

    fclose(file);
    return;
}