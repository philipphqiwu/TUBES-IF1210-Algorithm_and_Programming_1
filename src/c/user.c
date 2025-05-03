#include "../header/user.h"
#include <string.h>

void printUser(User user){
    printf("%d,%s,%s,%s", user.id, user.username, user.password, user.role);
    if(strcmp(user.role,"pasien")==0){
        printf(",%s,%f,%d,%d,%d,%f,%d,%f,%d,%d,%d,%d", user.riwayat_penyakit, user.suhu_tubuh, user.tekanan_darah_sistolik, user.tekanan_darah_diastolik, user.detak_jantung,
        user.saturasi_oksigen, user.kadar_gula_darah, user.berat_badan, user.tinggi_badan, user.kadar_kolesterol, user.kadar_kolesterol_ldl, user.trombosit);
    }
}