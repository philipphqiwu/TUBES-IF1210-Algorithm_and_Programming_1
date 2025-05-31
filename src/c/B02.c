#include "../header/general-parsing.h"
#include "../header/config.h"
#include "../header/user.h"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"


int checkRuanganKosong(Config rumahSakit, int barisNew, int kolomNew){

    for (int i = barisNew; i < rumahSakit.denah.rows; i++){
        for (int j = 0; j < rumahSakit.denah.cols; j++){
            if (rumahSakit.denah.contents[i][j].dokterID != 0){
                return false;
            }
        }
    }

    for (int i = 0; i < barisNew; i++){
        for (int j = kolomNew; j < rumahSakit.denah.cols; j++){
            if (rumahSakit.denah.contents[i][j].dokterID != 0){
                return false;
            }
        }
    }

    return true;
}


void ubahDenah(Config *rumahSakit){
    int barisNew, kolomNew;
    scanf("%d %d", &barisNew, &kolomNew);
    if (barisNew < rumahSakit->denah.rows || kolomNew < rumahSakit->denah.cols){
        if(checkRuanganKosong(*rumahSakit, barisNew, kolomNew)){
            printf("Denah rumah sakit berhasil diubah menjadi %d baris dan %d kolom\n", barisNew, kolomNew);
            rumahSakit->denah.rows = barisNew;
            rumahSakit->denah.cols = kolomNew;
            return;
        }else{
            printf("Ruangan tidak kosong, pindahkan dokter terlebih dahulu");
            return;
        }
    }else{
        printf("Denah rumash sakit berhasil diubah menjadi %d baris dan %d kolom\n", barisNew, kolomNew);
        rumahSakit->denah.rows = barisNew;
        rumahSakit->denah.cols = kolomNew;
    }

}


void pindahDokter(ListDinUser userData, Config *rumahSakit){
    char kodeRuanganNow[10];
    char kodeRuanganNew[10];
    // Validasi input ruangan
    while (1) {
        scanf("%s %s",kodeRuanganNow, kodeRuanganNew);

        // Validasi: panjang harus 2, huruf kapital + digit angka
        if (strlen(kodeRuanganNow) == 2 &&
            kodeRuanganNow[0] >= 'A' && kodeRuanganNow[0] <= 'Z' &&
            kodeRuanganNow[1] >= '1' && kodeRuanganNow[1] <= '9'&&
            strlen(kodeRuanganNew) == 2 &&
            kodeRuanganNew[0] >= 'A' && kodeRuanganNew[0] <= 'Z' &&
            kodeRuanganNew[1] >= '1' && kodeRuanganNew[1] <= '9'){
            break;
        } else {
            printf(COLOR_RED"Input tidak valid! Format harus 1 huruf kapital dan 1 angka (contoh: A1).\n\n"COLOR_RESET);
        }
    }
    int barisNow = kodeRuanganNow[0] - 'A';
    int kolomNow = atoi(kodeRuanganNow + 1) - 1;
    int barisNew = kodeRuanganNew[0] - 'A';
    int kolomNew = atoi(kodeRuanganNew + 1) - 1;

    if (barisNow < 0 || kolomNow < 0 || kolomNow >= rumahSakit->denah.cols || barisNow >= rumahSakit->denah.rows) {
        printf(COLOR_RED"Ruangan awal tidak ditemukan!\n"COLOR_RESET);
        return;
    }
    if (barisNew < 0 || kolomNew < 0 || kolomNew >= rumahSakit->denah.cols || barisNew >= rumahSakit->denah.rows) {
        printf(COLOR_RED"Ruangan akhir tidak ditemukan!\n"COLOR_RESET);
        return;
    }

    if(rumahSakit->denah.contents[barisNow][kolomNow].dokterID != 0){
        rumahSakit->denah.contents[barisNew][kolomNew] = rumahSakit->denah.contents[barisNow][kolomNow];
        rumahSakit->denah.contents[barisNow][kolomNow].dokterID = 0;
        printf("Berhasil memindahkan dokter %s", cariUsername(userData, rumahSakit->denah.contents[barisNew][kolomNew].dokterID));
    }
    else{
        printf("Ruangan tidak kosong");
    }
}
