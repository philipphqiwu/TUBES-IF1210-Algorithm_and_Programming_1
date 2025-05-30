#include "../header/F05.h"

void help(int loginState, int loginId, ListDinUser UserData){
    int idxUser = cariIdxUser(&UserData, loginId);

    printf(COLOR_WHITE"\n=========== HELP ===========\n");
    switch (loginState){
        // untuk sebelum LOGIN
        case 0:
            printf(COLOR_BLUE"Kamu belum login sebagai role apapun. Silahkan login terlebih dahulu.\n\n");
            puts("1. LOGIN    : Masuk ke dalam akun yang sudah terdaftar");
            puts("2. REGISTER : Membuat akun baru");
            puts("3. SAVE     : Menyimpan kondisi rumah sakit");
            puts("4. EXIT     : Keluar dari program");
            break;
        // untuk Manager
        case 1:
            printf(COLOR_MAGENTA"Halo Manager %s. Berikut adalah hal-hal yang dapat kamu lakukan sekarang:\n\n", UserData.buffer[idxUser].username);
            puts(" 1. LOGOUT                : Keluar dari akun yang sedang digunakan");
            puts(" 2. TAMBAH_DOKTER         : Mendaftarkan dokter baru ke sistem");
            puts(" 3. LIHAT_DENAH           : Melihat denah rumah sakit");
            puts(" 4. LIHAT_RUANGAN         : Melihat isi dari ruangan pada rumah sakit");
            puts(" 5. LIHAT_USER            : Melihat data seluruh pengguna");
            puts(" 6. LIHAT_PASIEN          : Melihat data seluruh pasien");
            puts(" 7. LIHAT_DOKTER          : Melihat data seluruh dokter");
            puts(" 8. CARI_USER             : Mencari pengguna tertentu berdasarkan ID atau Nama");
            puts(" 9. CARI_PASIEN           : Mencari pasien tertentu berdasarkan ID, Nama, atau Penyakit");
            puts("10. CARI_DOKTER           : Mencari dokter tertentu berdasarkan ID atau Nama");
            puts("11. LIHAT_SEMUA_ANTRIAN   : Melihat rincian seluruh ruangan saat ini");
            puts("12. TAMBAH_DOKTER         : Menambah dokter baru dengan username dan password yang ditentukan");
            puts("13. ASSIGN_DOKTER         : Melakukan assign ruangan ke dokter tertentu yang belum memiliki ruangan");
            puts("14. SAVE                  : Menyimpan kondisi rumah sakit");
            puts("15. EXIT                  : Keluar dari program");
            break;
        // untuk manager
        case 2:
            printf(COLOR_CYAN"Halo Dokter %s. Kamu memanggil HELP. Berikut command yang tersedia:\n\n", UserData.buffer[idxUser].username);
            puts("1. LOGOUT         : Keluar dari akun");
            puts("2. DIAGNOSIS      : Melakukan diagnosis pasien");
            puts("3. NGOBATIN       : Meresepkan obat");
            puts("4. LIHAT_DENAH    : Membuka denah rumah sakit");
            puts("5. LIHAT_RUANGAN  : Melihat isi dari ruangan pada rumah sakit");
            puts("6. SAVE           : Menyimpan kondisi rumah sakit");
            puts("7. EXIT           : Keluar dari program");
        break;
        // untuk pasien
        case 3:
            printf(COLOR_YELLOW"Selamat datang, %s. Berikut command yang tersedia:\n\n", UserData.buffer[idxUser].username);
            puts(" 1. LOGOUT            : Keluar dari akun");
            puts(" 2. DAFTAR_CHECKUP    : Mendaftarkan diri untuk pemeriksaan");
            puts(" 3. ANTRIAN           : Melihat status antrian");
            puts(" 4. LIHAT_DENAH       : Membuka denah rumah sakit");
            puts(" 5. LIHAT_RUANGAN     : Melihat isi dari ruangan pada rumah sakit");
            puts(" 6. PULANGDOK         : Berkonsultasi kembali ke dokter untuk menanyakan apakah kondisi sudah baik dan boleh pulang");
            puts(" 7. MINUM_OBAT        : Melihat daftar obat dan memilih obat yang akan diminum");
            puts(" 8. MINUM_PENAWAR     : Meminum penawar jika salah minum obat dan mengeluarkan obat terakhir yang diminum");
            puts(" 9. SAVE              : Menyimpan kondisi rumah sakit");
            puts("10. EXIT              : Keluar dari program");
        break;
    }

    puts("Footnote:");
    puts("1. Untuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar");
    puts("2. Jangan lupa untuk memasukkan input yang valid\n");
    printf(COLOR_RESET);
}


