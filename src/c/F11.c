#include "../header/F11.h"
#include <stdio.h>
#include "../header/user.h"
#include "../header/config.h"
#include "../header/Boolean.h"
#include "../header/penyakit.h"


// Merupakan fungsi untuk mengecek apakah pasien terkena suatu penyakit
int cekPenyakit(ListPenyakit kriteriaPenyakit, ListDinUser UserData, int idPasien){
    for (int i = 0; i <= 5; i++) {
       
        boolean allMatch = true;
        
        // 1. Pengecekan Suhu tubuh
        if (UserData.buffer[idPasien].suhu_tubuh < kriteriaPenyakit.items[i].suhu_tubuh_min || 
            UserData.buffer[idPasien].suhu_tubuh > kriteriaPenyakit.items[i].suhu_tubuh_max) {
            allMatch = false;
        }
        
        // 2. Pengecekan Tekanan darah sistolik
        if (allMatch && (UserData.buffer[idPasien].tekanan_darah_sistolik < kriteriaPenyakit.items[i].tekanan_darah_sistolik_min || 
            UserData.buffer[idPasien].tekanan_darah_sistolik > kriteriaPenyakit.items[i].tekanan_darah_sistolik_max)) {
            allMatch = false;
        }
        
        // 3. Pengecekan Tekanan darah diastolik
        if (allMatch && (UserData.buffer[idPasien].tekanan_darah_diastolik < kriteriaPenyakit.items[i].tekanan_darah_diastolik_min || 
            UserData.buffer[idPasien].tekanan_darah_diastolik > kriteriaPenyakit.items[i].tekanan_darah_diastolik_max)) {
            allMatch = false;
        }
        
        // 4. Pencekan Detak jantung
        if (allMatch && (UserData.buffer[idPasien].detak_jantung < kriteriaPenyakit.items[i].detak_jantung_min || 
            UserData.buffer[idPasien].detak_jantung > kriteriaPenyakit.items[i].detak_jantung_max)) {
            allMatch = false;
        }
        
        // 5. Pengecekan Saturasi oksigen
        if (allMatch && (UserData.buffer[idPasien].saturasi_oksigen < kriteriaPenyakit.items[i].saturasi_oksigen_min || 
            UserData.buffer[idPasien].saturasi_oksigen > kriteriaPenyakit.items[i].saturasi_oksigen_max)) {
            allMatch = false;
        }
        
        // 6. Pengecekan Kadar gula darah
        if (allMatch && (UserData.buffer[idPasien].kadar_gula_darah < kriteriaPenyakit.items[i].kadar_gula_darah_min || 
            UserData.buffer[idPasien].kadar_gula_darah > kriteriaPenyakit.items[i].kadar_gula_darah_max)) {
            allMatch = false;
        }
        
        // 7. Pengecekan Berat badan
        if (allMatch && (UserData.buffer[idPasien].berat_badan < kriteriaPenyakit.items[i].berat_badan_min || 
            UserData.buffer[idPasien].berat_badan > kriteriaPenyakit.items[i].berat_badan_max)) {
            allMatch = false;
        }
        
        // 8. Pengecekan Tinggi badan
        if (allMatch && (UserData.buffer[idPasien].tinggi_badan < kriteriaPenyakit.items[i].tinggi_badan_min || 
            UserData.buffer[idPasien].tinggi_badan > kriteriaPenyakit.items[i].tinggi_badan_max)) {
            allMatch = false;
        }
        
        // 9. Pengecekan Kadar kolesterol
        if (allMatch && (UserData.buffer[idPasien].kadar_kolesterol < kriteriaPenyakit.items[i].kadar_kolesterol_min || 
            UserData.buffer[idPasien].kadar_kolesterol > kriteriaPenyakit.items[i].kadar_kolesterol_max)) {
            allMatch = false;
        }
        
        // 10. Pngecekan Trombosit
        if (allMatch && (UserData.buffer[idPasien].trombosit < kriteriaPenyakit.items[i].trombosit_min || 
            UserData.buffer[idPasien].trombosit > kriteriaPenyakit.items[i].trombosit_max)) {
            allMatch = false;
        }
        
        // Jika semua parameter cocok, return ID penyakit
        if (allMatch) {
            return i;
        }
    }
    // Kalau tidak ada penyaki yang cocok maka akan di return -1

    return -1;
}

// Melalukan assign penyakit ketika telah dicek penyakitnya melalui cekPenyakit
boolean assignPenyakit(ListPenyakit kriteriaPenyakit, ListDinUser* UserData, int idPasien){
    int kondisipasien = cekPenyakit(kriteriaPenyakit, *UserData, idPasien);
    if (kondisipasien != -1){
        strcpy(UserData->buffer[idPasien].riwayat_penyakit, kriteriaPenyakit.items[kondisipasien].nama_penyakit);
        return true;
    }
    else{
        return false;
    }
}

// Untuk melakukan pengecekan apakah pasien punya riwayat penyakit sebelumnya
boolean punyaRiwayat(char* riwayat_penyakit) {
    return (riwayat_penyakit != NULL &&  strlen(riwayat_penyakit) > 0 &&  strcmp(riwayat_penyakit, "") != 0);
}



int diagnosisPenyakit (ListPenyakit krirteriapenyakit, Config rumahsakit, ListDinUser *UserData, int loginId){
    int idxKolom, idxBaris;
    // mencari ruangan pasien
    for (int i = 0; i < rumahsakit.denah.rows; i++){
        for (int j = 0; j < rumahsakit.denah.cols; j++){
            if (rumahsakit.denah.contents[i][j].dokterID == loginId){
                idxKolom = j;
                idxBaris = i;
            }
        }
    }
    int idxDokter = cariIdxUser(UserData, loginId); // Mencari id dokter 

    // validasi ruangan dari dokter
    if (idxDokter != -1){
        // validasi dari pasien terdepan yang akan diobati
        int idxPasien = cariIdxUser(UserData, rumahsakit.denah.contents[idxBaris][idxKolom].antrian->front->data);
        if (idxPasien != -1){
            int idPenyakitSekarang = cekPenyakit(krirteriapenyakit, *UserData, idxPasien);
            // Kemungkinan 1 : pasien pernah didiagnosis
            if (punyaRiwayat(UserData->buffer[idxPasien].riwayat_penyakit)) {
                // Jika pasien sudah sembuh
                if (idPenyakitSekarang == -1) {
                    printf("%s tidak terdiagnosa penyakit apapun!\n", UserData->buffer[idxPasien].username);
                    strcpy(UserData->buffer[idxPasien].riwayat_penyakit, "");
                    return 0; // Diagnosis selesai
                } 
                // Jika pasien masih sakit
                else {
                    printf("%s masih menderita %s\n", UserData->buffer[idxPasien].username, UserData->buffer[idxPasien].riwayat_penyakit);
                    return 0;
                }
            }   
            // Kemungkinan 2 : pasien belum pernah didiagnosis
            else {
                // Pasien punya penyakit
                if (assignPenyakit(krirteriapenyakit, UserData, idxPasien)) {
                    printf("%s terdiagnosa penyakit %s!\n", UserData->buffer[idxPasien].username, UserData->buffer[idxPasien].riwayat_penyakit);
                    return 0; 
                } 
                // pasien tidak punya penyakit
                else {
                    printf("%s tidak terdiagnosa penyakit apapun!\n", UserData->buffer[idxPasien].username);
                    return 0;
                }
            }
        }
    
        else{
            printf("Tidak ada pasien di ruangan Anda saat ini\n");
            return 0;
        }
    }

    
    else{
        printf("Anda tidak sedang bertugas di ruangan manapun\n");
        return 0;
    }
    
    return 0; 
     
}



        


     

