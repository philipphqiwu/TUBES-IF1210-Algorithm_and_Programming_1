#include "../header/F11.h"
#include <stdio.h>
#include "../header/user.h"
#include "../header/config.h"
#include "../header/Boolean.h"
#include "../header/penyakit.h"



int cekpenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien){
    // int idPenyakit;
    for (int i = 0; i <= 5; i++) {
       
        boolean allMatch = true;
        
        // 1. Suhu tubuh
        if (UserData->buffer[idPasien].suhu_tubuh < kriteriapenyakit.items[i].suhu_tubuh_min || 
            UserData->buffer[idPasien].suhu_tubuh > kriteriapenyakit.items[i].suhu_tubuh_max) {
            allMatch = false;
        }
        
        // 2. Tekanan darah sistolik
        if (allMatch && (UserData->buffer[idPasien].tekanan_darah_sistolik < kriteriapenyakit.items[i].tekanan_darah_sistolik_min || 
            UserData->buffer[idPasien].tekanan_darah_sistolik > kriteriapenyakit.items[i].tekanan_darah_sistolik_max)) {
            allMatch = false;
        }
        
        // 3. Tekanan darah diastolik
        if (allMatch && (UserData->buffer[idPasien].tekanan_darah_diastolik < kriteriapenyakit.items[i].tekanan_darah_diastolik_min || 
            UserData->buffer[idPasien].tekanan_darah_diastolik > kriteriapenyakit.items[i].tekanan_darah_diastolik_max)) {
            allMatch = false;
        }
        
        // 4. Detak jantung
        if (allMatch && (UserData->buffer[idPasien].detak_jantung < kriteriapenyakit.items[i].detak_jantung_min || 
            UserData->buffer[idPasien].detak_jantung > kriteriapenyakit.items[i].detak_jantung_max)) {
            allMatch = false;
        }
        
        // 5. Saturasi oksigen
        if (allMatch && (UserData->buffer[idPasien].saturasi_oksigen < kriteriapenyakit.items[i].saturasi_oksigen_min || 
            UserData->buffer[idPasien].saturasi_oksigen > kriteriapenyakit.items[i].saturasi_oksigen_max)) {
            allMatch = false;
        }
        
        // 6. Kadar gula darah
        if (allMatch && (UserData->buffer[idPasien].kadar_gula_darah < kriteriapenyakit.items[i].kadar_gula_darah_min || 
            UserData->buffer[idPasien].kadar_gula_darah > kriteriapenyakit.items[i].kadar_gula_darah_max)) {
            allMatch = false;
        }
        
        // 7. Berat badan
        if (allMatch && (UserData->buffer[idPasien].berat_badan < kriteriapenyakit.items[i].berat_badan_min || 
            UserData->buffer[idPasien].berat_badan > kriteriapenyakit.items[i].berat_badan_max)) {
            allMatch = false;
        }
        
        // 8. Tinggi badan
        if (allMatch && (UserData->buffer[idPasien].tinggi_badan < kriteriapenyakit.items[i].tinggi_badan_min || 
            UserData->buffer[idPasien].tinggi_badan > kriteriapenyakit.items[i].tinggi_badan_max)) {
            allMatch = false;
        }
        
        // 9. Kadar kolesterol
        if (allMatch && (UserData->buffer[idPasien].kadar_kolesterol < kriteriapenyakit.items[i].kadar_kolesterol_min || 
            UserData->buffer[idPasien].kadar_kolesterol > kriteriapenyakit.items[i].kadar_kolesterol_max)) {
            allMatch = false;
        }
        
        // 10. Trombosit
        if (allMatch && (UserData->buffer[idPasien].trombosit < kriteriapenyakit.items[i].trombosit_min || 
            UserData->buffer[idPasien].trombosit > kriteriapenyakit.items[i].trombosit_max)) {
            allMatch = false;
        }
        
        // Jika semua parameter cocok, return ID penyakit
        if (allMatch) {
            return i;
        }
    }
    // Kalau tidak ada penyaki tyang cocok

    return -1;
}

boolean assignPenyakit(ListPenyakit kriteriapenyakit, ListDinUser* UserData, int idPasien){
    int kondisipasien = cekpenyakit(kriteriapenyakit, UserData, idPasien);
    if (kondisipasien != -1){
        strcpy(UserData->buffer[idPasien].riwayat_penyakit, kriteriapenyakit.items[kondisipasien].nama_penyakit);
        return true;
    }
    else{
        return false;
    }
}

boolean punyaRiwayat(char* riwayat_penyakit) {
    return (riwayat_penyakit != NULL &&  strlen(riwayat_penyakit) > 0 &&  strcmp(riwayat_penyakit, "") != 0);
}



int DIAGNOSIS(ListPenyakit krirteriapenyakit, Config rumahsakit, ListDinUser *UserData, int loginId){
    int idxKolom, idxBaris;
    for (int i = 0; i < rumahsakit.denah.rows; i++){
        for (int j = 0; j < rumahsakit.denah.cols; j++){
            if (rumahsakit.denah.contents[i][j].dokterID == loginId){
                idxKolom = j;
                idxBaris = i;
            }
        }
    }
    int idxDokter = cariIdxUser(UserData, loginId);
    if (idxDokter != -1){
        int idxPasien = cariIdxUser(UserData, rumahsakit.denah.contents[idxBaris][idxKolom].antrian->front->data);
        if (idxPasien != -1){
            int idPenyakitSekarang = cekpenyakit(krirteriapenyakit, UserData, idxPasien);
            if (punyaRiwayat(UserData->buffer[idxPasien].riwayat_penyakit)) {
                    
                if (idPenyakitSekarang == -1) {
                    printf("%s tidak terdiagnosa penyakit apapun!\n", UserData->buffer[idxPasien].username);
                    strcpy(UserData->buffer[idxPasien].riwayat_penyakit, "");
                    return 0; // Diagnosis selesai
                } 
                else {
                    printf("%s masih menderita %s\n", UserData->buffer[idxPasien].username, UserData->buffer[idxPasien].riwayat_penyakit);
                    return 0;
                }
            }   
            else {
                if (assignPenyakit(krirteriapenyakit, UserData, idxPasien)) {
                    printf("%s terdiagnosa penyakit %s!\n", UserData->buffer[idxPasien].username, UserData->buffer[idxPasien].riwayat_penyakit);
                    return 0; 
                } 
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



        


     

