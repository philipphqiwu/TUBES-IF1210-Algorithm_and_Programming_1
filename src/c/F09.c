// #include "../header/F09.h"
// #include "../header/config.h"
// #include "../header/user.h"
// #include <stdio.h>

// const char* cari_user(ListDinUser UserData, int id) {
//     for (int i = 0; i < UserData.nEff; i++) {
//         if (UserData.buffer[i].id == id) {
//             return UserData.buffer[i].username;
//         }
//     }
//     return "-";
// }

// char ruang[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
//                     'K', 'L', 'M', 'N', 'O', 'P','Q', 'R','S','T','U'
//                     ,'V', 'W', 'X','Y','Z'};

// void lihatAntrian(Config rumahsakit, ListDinUser UserData){

//     printf("    ");
//     for(int j = 0; j < rumahsakit.roomCol; j++) {
//         printf("  %d  ", j+1);
//     }
//     printf("\n");

//     printf("   +");
//     for(int j = 0; j < rumahsakit.roomCol; j++) {
//         printf("-----+");
//     }
//     printf("\n");


//     for(int i = 0; i < rumahsakit.roomRow; i++) {

//         printf(" %c |", ruang[i]);
//         for(int j = 0; j < rumahsakit.roomCol; j++) {
//              printf(" %c%-2d |", ruang[i], j+1); 
//         }
//         printf("\n");


//         printf("   +");
//         for(int j = 0; j < rumahsakit.roomCol; j++) {
//             printf("-----+");
//         }
//         printf("\n");
//     }

//     for(int baris = 0; baris < rumahsakit.roomRow; baris++){
//         for(int kolom = 0; kolom < rumahsakit.roomCol; kolom++){

//             int indeks = baris * rumahsakit.roomCol + kolom;
//             int id_dokter = rumahsakit.room[indeks][0];
//             const char* nama_dokter = cari_user(UserData, id_dokter+1);

//             if(id_dokter != 0 && strcmp(nama_dokter, "-") != 0){ //tampilkan jika ada dokter
//                 char koderuangan[3];
//                 koderuangan[0] = 'A' + baris;
//                 koderuangan[1] = '1' + kolom;
//                 koderuangan[2] = '\0';

//                 printf("\n============ %s ============\n", koderuangan);
//                 printf("Kapasitas  : %d\n", rumahsakit.roomCapacity);
//                 printf("Dokter     : %s\n", nama_dokter);

//                 printf("Pasien di dalam ruangan:\n");
//                 int pasien_count = 0;
//                 for (int i = 1; i <= rumahsakit.roomCapacity; i++) {
//                     int id_pasien = rumahsakit.room[indeks][i];
//                     if (id_pasien != 0) {
//                         printf("  %d. %s\n", ++pasien_count, cari_user(UserData, id_pasien+1));
//                     }
//                 }
//                 if (pasien_count == 0) printf("  Tidak ada pasien\n");

//                 printf("Pasien di antrian:\n");

//                 printf("------------------------------\n");
//             }
//         }
//     }
// }