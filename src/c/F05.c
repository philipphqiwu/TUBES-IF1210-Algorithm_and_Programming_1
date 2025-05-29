#include "../header/F05.h"
/*

PULANGDOK -Berkonsultasi kembalik ke dokter untuk menanyakan apakah kondisi sudah baik dan boleh pulang - Pasien
MINUM_OBAT -Melihat daftar obat dan melakukan pilihan obat yang akan diminum - Pasien
PENAWAR - Meminum penawar jika salah minum obat dan mengeluarkan obat terakhir yang diminum - Pasien
EXIT - Keluar dari program*/
void help(int loginState, int loginId, ListDinUser UserData){

    printf(COLOR_WHITE"\n=========== HELP ===========\n");
    switch (loginState){
        // untuk sebelum LOGIN
        case 0:
            printf(COLOR_BLUE"Kamu belum login sebagai role apapun. Silahkan login terlebih dahulu.\n\n");
            puts("1. LOGIN    : Masuk ke dalam akun yang sudah terdaftar");
            puts("2. REGISTER : Membuat akun baru");
            break;
        // untuk Manager
        case 1:
            printf(COLOR_MAGENTA"Halo Manager %s. Berikut adalah hal-hal yang dapat kamu lakukan sekarang:\n\n", UserData.buffer[loginId-1].username);
            puts("1. LOGOUT                 : Keluar dari akun yang sedang digunakan");
            puts("2. TAMBAH_DOKTER          : Mendaftarkan dokter baru ke sistem");
            puts("3. LIHAT_DENAH            : Membuka denah rumah sakit");
            puts("4.  LIHAT_USER            : Melihat data seluruh pengguna");
            puts("5.  LIHAT_PASIEN          : Melihat data seluruh pasien");
            puts("6.  LIHAT_DOKTER          : Melihat data seluruh dokter");
            puts("7.  CARI_USER             : Mencari pengguna tertentu berdasarkan ID atau Nama");
            puts("8.  CARI_PASIEN           : Mencari pasien tertentu berdasarkan ID, Nama, atau Penyakit");
            puts("9.  CARI_DOKTER           : Mencari dokter tertentu berdasarkan ID atau Nama");
            puts("10. LIHAT_SEMUA_ANTRIAN   : Melihat rincian seluruh ruangan saat ini");
            puts("11. TAMBAH_DOKTER         : Menambah dokter baru dengan username dan password yang ditentukan");
            puts("12. ASSIGN_DOKTER         : Melakukan assign ruangan ke dokter tertentu yang belum memiliki ruangan");
            break;
        // untuk manager
        case 2:
            printf(COLOR_CYAN"Halo Dokter %s. Kamu memanggil HELP. Berikut command yang tersedia:\n\n", UserData.buffer[loginId-1].username);
            puts("1. LOGOUT         : Keluar dari akun");
            puts("2. DIAGNOSIS      : Melakukan diagnosis pasien");
            puts("3. NGOBATIN       : Meresepkan obat");
            puts("4. LIHAT_DENAH    : Membuka denah rumah sakit");
        break;
        // untuk pasien
        case 3:
            printf(COLOR_YELLOW"Selamat datang, %s. Berikut command yang tersedia:\n\n", UserData.buffer[loginId-1].username);
            puts("1. LOGOUT             : Keluar dari akun");
            puts("2. DAFTAR_CHECKUP     : Mendaftarkan diri untuk pemeriksaan");
            puts("3. ANTRIAN            : Melihat status antrian");
            puts("4. LIHAT_DENAH        : Membuka denah rumah sakit");
            puts("5.  PULANGDOK         : Berkonsultasi kembali ke dokter untuk menanyakan apakah kondisi sudah baik dan boleh pulang");
            puts("6.  MINUM_OBAT        : Melihat daftar obat dan memilih obat yang akan diminum");
            puts("7.  PENAWAR           : Meminum penawar jika salah minum obat dan mengeluarkan obat terakhir yang diminum");
        break;
    }

    puts("Footnote:");
    puts("1. Untuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar");
    puts("2. Jangan lupa untuk memasukkan input yang valid\n");
    printf(COLOR_RESET);
}


