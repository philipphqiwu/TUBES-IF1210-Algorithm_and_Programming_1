#include "../header/user.h"
#include "../header/queue.h"
#include "../header/F06.h"
#include "../header/F14.h"
#include "../header/config.h"
#include <stdio.h>

void daftarCheckUp(ListDinUser *UserData, Config *rumahsakit, int loginId){
    //mengecek apakah pasien sudah dalam antrian atau belum
    for (int i = 0; i < rumahsakit->denah.rows; i++) {
        for (int j = 0; j < rumahsakit->denah.cols; j++) {
            Node *current = rumahsakit->denah.contents[i][j].antrian->front;
            while (current != NULL) {
                if (current->data == loginId) {
                    printf(COLOR_RED"Anda sudah terdaftar dalam antrian check-up!\nSilakan selesaikan check-up yang sudah terdaftar terlebih dahulu.\n"COLOR_RESET);
                    return;
                }
                current = current->next;
            }
        }
    }

    //input data
    float suhu, berat, saturasi;
    int sistolik, diastolik, detak, gula, tinggi, kolestrol, trombosit;
    int valid;
    printf(COLOR_YELLOW"Silakan masukkan data check-up Anda:\n");

    int idxUser = cariIdxUser(UserData, loginId);

    do {
        printf(COLOR_YELLOW"Suhu Tubuh (Celcius): ");
        valid = scanf("%f", &suhu);
        while(getchar() != '\n'); //valid dan getchar disini untuk validasi input agar user tidak input string
        if (valid != 1 || suhu <= 0) {
            printf(COLOR_RED"Suhu tubuh harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].suhu_tubuh = suhu;

    do {
        printf(COLOR_YELLOW"Tekanan Darah (sistol diastol, contoh: 120 80): ");
        valid = scanf("%d %d", &sistolik, &diastolik);
        while(getchar() != '\n');
        if (valid != 2 || sistolik <= 0 || diastolik <= 0) {
            printf(COLOR_RED"Tekanan darah harus berupa dua angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].tekanan_darah_sistolik = sistolik;
    UserData->buffer[idxUser].tekanan_darah_diastolik = diastolik;

    do {
        printf(COLOR_YELLOW"Detak Jantung (bpm): ");
        valid = scanf("%d", &detak);
        while(getchar() != '\n');
        if (valid != 1 || detak <= 0) {
            printf(COLOR_RED"Detak jantung harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].detak_jantung = detak;

    do {
        printf(COLOR_YELLOW"Saturasi Oksigen (%%): ");
        valid = scanf("%f", &saturasi);
        while(getchar() != '\n');
        if (valid != 1 || saturasi <= 0) {
            printf(COLOR_RED"Saturasi oksigen harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].saturasi_oksigen = saturasi;

    do {
        printf(COLOR_YELLOW"Kadar Gula Darah (mg/dL): ");
        valid = scanf("%d", &gula);
        while(getchar() != '\n');
        if (valid != 1 || gula <= 0) {
            printf(COLOR_RED"Kadar gula darah harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].kadar_gula_darah = gula;

    do {
        printf(COLOR_YELLOW"Berat Badan (kg): ");
        valid = scanf("%f", &berat);
        while(getchar() != '\n');
        if (valid != 1 || berat <= 0) {
            printf(COLOR_RED"Berat badan harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].berat_badan = berat;

    do {
        printf(COLOR_YELLOW"Tinggi Badan (cm): ");
        valid = scanf("%d", &tinggi);
        while(getchar() != '\n');
        if (valid != 1 || tinggi <= 0) {
            printf(COLOR_RED"Tinggi badan harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].tinggi_badan = tinggi;

    do {
        printf(COLOR_YELLOW"Kadar Kolestrol (mg/dL): ");
        valid = scanf("%d", &kolestrol);
        while(getchar() != '\n');
        if (valid != 1 || kolestrol <= 0) {
            printf(COLOR_RED"Kadar kolestrol harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].kadar_kolesterol = kolestrol;

    do {
        printf(COLOR_YELLOW"Trombosit (ribu/µL): ");
        valid = scanf("%d", &trombosit);
        while(getchar() != '\n');
        if (valid != 1 || trombosit <= 0) {
            printf(COLOR_RED"Trombosit harus berupa angka positif!\n");
            valid = 0;
        }
    } while (!valid);
    UserData->buffer[idxUser].trombosit = trombosit;

    int choice_holder[50][2];
    int nomor = 1;
    printf("Berikut adalah daftar dokter yang tersedia:\n");
    for(int baris = 0; baris < rumahsakit->denah.rows; baris++){
        for(int kolom = 0; kolom < rumahsakit->denah.cols; kolom++){
            if(rumahsakit->denah.contents[baris][kolom].dokterID == 0) continue;
            int antrian_total = rumahsakit->denah.contents[baris][kolom].antrian->counter;
            int current_antrian_luar = antrian_total - rumahsakit->kapasitasRuangan;
            if(current_antrian_luar >= rumahsakit->kapasitasAntrian) continue;
            char nama[21];
            strncpy(nama, cariUsername(*UserData, rumahsakit->denah.contents[baris][kolom].dokterID), 20);
            nama[20] = '\0';  // pastikan null-terminated

            const char* kodeRuang = rumahsakit->denah.contents[baris][kolom].kodeRuangan;
            int idxDokter = cariIdxUser(UserData, rumahsakit->denah.contents[baris][kolom].dokterID);
            if(current_antrian_luar > 0){
                printf(COLOR_YELLOW"%d. Dr. %s - Spesialisasi Umum - Ruangan %s (Antrian: %d)"COLOR_BLUE"- Aura %d\n"COLOR_RESET, nomor, nama, kodeRuang, current_antrian_luar, UserData->buffer[idxDokter].aura);
            }else{ //kalau current antrian luar minus, berdasarkan rumus current antrian artinya tidak ada ada antrian di luar 
                printf(COLOR_YELLOW"%d. Dr. %s - Spesialisasi Umum - Ruangan %s (Antrian: %d)"COLOR_BLUE"- Aura %d\n"COLOR_RESET, nomor, nama, kodeRuang, 0, UserData->buffer[idxDokter].aura);
            }
            choice_holder[nomor][0] = baris;
            choice_holder[nomor][1] = kolom;
            nomor++;
        }
    }

    int choice;
    int valid_choice = 0;
    do {
        printf(COLOR_YELLOW"Pilih dokter (contoh input: 1) : ");
        valid = scanf("%d", &choice);
        while(getchar() != '\n'); 
        if (valid != 1 || choice < 1 || choice >= nomor) {
            printf(COLOR_RED"Pilihan tidak valid! Silakan masukkan angka antara 1 sampai %d.\n"COLOR_RESET, nomor-1);
            valid_choice = 0;
        } else {
            valid_choice = 1;
        }
    } while (!valid_choice);

    enqueue(rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].antrian, loginId);
    printf("Pendaftaran check-up berhasil!\n");
    printf("Anda terdaftar pada antrian %s di ruangan %s.\n", cariUsername(*UserData, rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].dokterID), rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].kodeRuangan);
    if((rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].antrian->counter - rumahsakit->kapasitasRuangan) > 0){
        printf("\nPosisi antrian anda: %d\n", (rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].antrian->counter - rumahsakit->kapasitasRuangan));
    }else{ //kalau gada antrian di luar ruangan
        printf("\nKarena tidak ada antrian di luar ruangan, silahkan langsung masuk saja.\n");
        if(rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].antrian->counter == 1){
            printf("Dokter akan memeriksamu sekarang.\n"); //kalau gada orang lain yang harus dilayani dokter terlebih dahulu
        }else{
            printf("Masih ada pasien dalam ruangan yang harus dilayani dulu oleh dokter. Anda giliran ke-%d.\n", rumahsakit->denah.contents[choice_holder[choice][0]][choice_holder[choice][1]].antrian->counter);
        }
    }
}