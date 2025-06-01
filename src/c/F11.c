#include "../header/F11.h"
#include <stdio.h>
#include "../header/user.h"
#include "../header/config.h"
#include "../header/Boolean.h"
#include <string.h>
#include "../header/penyakit.h"
#include "../header/ascii-art.h"


// "" untuk pasien yang belum pernah di diagnosis
// "-" untuk pasien yang sudah pernah di diagnosis dan tidak terdiagnosis penyakit

int cekPenyakit(ListPenyakit kriteriaPenyakit, ListDinUser* UserData, int idxPasien){
    if (strcmp(UserData->buffer[idxPasien].riwayat_penyakit, "-") == 0) return -1;
    for (int i = 0; i <= 5; i++) {
       
        boolean allMatch = true;
        
        // 1. Pengecekan Suhu tubuh
        if (UserData->buffer[idxPasien].suhu_tubuh < kriteriaPenyakit.items[i].suhu_tubuh_min || 
            UserData->buffer[idxPasien].suhu_tubuh > kriteriaPenyakit.items[i].suhu_tubuh_max) {
            allMatch = false;
        }
        
        // 2. Pengecekan Tekanan darah sistolik
        if (allMatch && (UserData->buffer[idxPasien].tekanan_darah_sistolik < kriteriaPenyakit.items[i].tekanan_darah_sistolik_min || 
            UserData->buffer[idxPasien].tekanan_darah_sistolik > kriteriaPenyakit.items[i].tekanan_darah_sistolik_max)) {
            allMatch = false;
        }
        
        // 3. Pengecekan Tekanan darah diastolik
        if (allMatch && (UserData->buffer[idxPasien].tekanan_darah_diastolik < kriteriaPenyakit.items[i].tekanan_darah_diastolik_min || 
            UserData->buffer[idxPasien].tekanan_darah_diastolik > kriteriaPenyakit.items[i].tekanan_darah_diastolik_max)) {
            allMatch = false;
        }
        
        // 4. Pencekan Detak jantung
        if (allMatch && (UserData->buffer[idxPasien].detak_jantung < kriteriaPenyakit.items[i].detak_jantung_min || 
            UserData->buffer[idxPasien].detak_jantung > kriteriaPenyakit.items[i].detak_jantung_max)) {
            allMatch = false;
        }
        
        // 5. Pengecekan Saturasi oksigen
        if (allMatch && (UserData->buffer[idxPasien].saturasi_oksigen < kriteriaPenyakit.items[i].saturasi_oksigen_min || 
            UserData->buffer[idxPasien].saturasi_oksigen > kriteriaPenyakit.items[i].saturasi_oksigen_max)) {
            allMatch = false;
        }
        
        // 6. Pengecekan Kadar gula darah
        if (allMatch && (UserData->buffer[idxPasien].kadar_gula_darah < kriteriaPenyakit.items[i].kadar_gula_darah_min || 
            UserData->buffer[idxPasien].kadar_gula_darah > kriteriaPenyakit.items[i].kadar_gula_darah_max)) {
            allMatch = false;
        }
        
        // 7. Pengecekan Berat badan
        if (allMatch && (UserData->buffer[idxPasien].berat_badan < kriteriaPenyakit.items[i].berat_badan_min || 
            UserData->buffer[idxPasien].berat_badan > kriteriaPenyakit.items[i].berat_badan_max)) {
            allMatch = false;
        }
        
        // 8. Pengecekan Tinggi badan
        if (allMatch && (UserData->buffer[idxPasien].tinggi_badan < kriteriaPenyakit.items[i].tinggi_badan_min || 
            UserData->buffer[idxPasien].tinggi_badan > kriteriaPenyakit.items[i].tinggi_badan_max)) {
            allMatch = false;
        }
        
        // 9. Pengecekan Kadar kolesterol
        if (allMatch && (UserData->buffer[idxPasien].kadar_kolesterol < kriteriaPenyakit.items[i].kadar_kolesterol_min || 
            UserData->buffer[idxPasien].kadar_kolesterol > kriteriaPenyakit.items[i].kadar_kolesterol_max)) {
            allMatch = false;
        }
        
        // 10. Pngecekan Trombosit
        if (allMatch && (UserData->buffer[idxPasien].trombosit < kriteriaPenyakit.items[i].trombosit_min || 
            UserData->buffer[idxPasien].trombosit > kriteriaPenyakit.items[i].trombosit_max)) {
            allMatch = false;
        }
        
        // Jika semua parameter cocok, return ID penyakit
        if (allMatch) {
            return i;
        }
    }
    // Kalau tidak ada penyakit yang cocok maka akan di return -1

    return -1;
}

// Melalukan assign penyakit ketika telah dicek penyakitnya melalui cekPenyakit
boolean assignPenyakit(ListPenyakit kriteriaPenyakit, ListDinUser* UserData, int idxPasien){
    int kondisipasien = cekPenyakit(kriteriaPenyakit, UserData, idxPasien);
    if (kondisipasien != -1){
        strcpy(UserData->buffer[idxPasien].riwayat_penyakit, kriteriaPenyakit.items[kondisipasien].nama_penyakit);
        return true;
    }
    else{
        return false;
    }
}

// Untuk melakukan pengecekan apakah pasien punya riwayat penyakit sebelumnya
boolean punyaRiwayat(char* riwayatPenyakit) {
    return (riwayatPenyakit != NULL &&  strlen(riwayatPenyakit) > 0 &&  strcmp(riwayatPenyakit, "-") == 0);
}

void diagnosis(ListPenyakit kriteriapenyakit, Config rumahsakit, ListDinUser *UserData, int loginId){
    int idxKolom, idxBaris, dokterFoundruangan = 0;;
    // mencari ruangan pasien
    for (int i = 0; i < rumahsakit.denah.rows; i++){
        for (int j = 0; j < rumahsakit.denah.cols; j++){
            if (rumahsakit.denah.contents[i][j].dokterID == loginId){
                idxKolom = j;
                idxBaris = i;
                dokterFoundruangan = 1;
            }
        }
    }
    int idxDokter = cariIdxUser(UserData, loginId); // Mencari id dokter 
    printf(COLOR_CYAN);
    // validasi ruangan dari dokter
    if (idxDokter != -1 && dokterFoundruangan == 1){
        // validasi dari pasien terdepan yang akan diobati
        int idxPasien = cariIdxUser(UserData, peekQueue(rumahsakit.denah.contents[idxBaris][idxKolom].antrian));
        if (idxPasien != -1){
            int idPenyakitSekarang = cekPenyakit(kriteriapenyakit, UserData, idxPasien);
            // Kemungkinan 1 : pasien pernah didiagnosis
            if (punyaRiwayat(UserData->buffer[idxPasien].riwayat_penyakit)) {
                // Jika pasien sudah sembuh
                if (idPenyakitSekarang == -1) {
                    printf(COLOR_CYAN"%s sudah tidak terdiagnosa penyakit apapun!\n", UserData->buffer[idxPasien].username);
                    // resetUserData(&(UserData->buffer[idxPasien]));
                    strcpy(UserData->buffer[idxPasien].riwayat_penyakit, "-");
                    return; // Diagnosis selesai
                } 
                // Jika pasien masih sakit
                else {
                    printf(COLOR_CYAN"%s masih menderita %s\n", UserData->buffer[idxPasien].username, UserData->buffer[idxPasien].riwayat_penyakit);
                    return;
                }
            }   
            // Kemungkinan 2 : pasien belum pernah didiagnosis
            else {
                // Pasien punya penyakit
                if (assignPenyakit(kriteriapenyakit, UserData, idxPasien)) {
                    printAsciiDiagnosis();
                    printf(COLOR_CYAN"%s terdiagnosa penyakit %s!\n", UserData->buffer[idxPasien].username, UserData->buffer[idxPasien].riwayat_penyakit);
                    return; 
                } 
                // pasien tidak punya penyakit
                else {
                    printf(COLOR_CYAN"%s tidak terdiagnosa penyakit apapun!\n", UserData->buffer[idxPasien].username);
                    // resetUserData(&(UserData->buffer[idxPasien]));
                    strcpy(UserData->buffer[idxPasien].riwayat_penyakit, "-");
                    return;
                }
            }
        }
        else{
            printf(COLOR_RED"Tidak ada pasien di ruangan Anda saat ini\n"COLOR_RESET);
        }
    }
    else{
        printf(COLOR_RED"Anda tidak sedang bertugas di ruangan manapun\n"COLOR_RESET);
    }
    
    return; 
}