#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Boolean.h"

typedef struct{
    int id;
    char username[21];
    char password[21];
    char role[21];
    char riwayat_penyakit[50];
    float suhu_tubuh;
    int tekanan_darah_sistolik;
    int tekanan_darah_diastolik;
    int detak_jantung;
    float saturasi_oksigen;
    int kadar_gula_darah;
    float berat_badan;
    int tinggi_badan;
    int kadar_kolesterol;
    int trombosit;
    int nyawa;
    char ruang[10];
    char antrian[10];
    int aura;
} User;

void printUser(User user);

#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef User ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDinUser;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDinUser, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinUser */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

  /* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinUser(ListDinUser *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDinUser *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDinUser l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDinUser l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDinUser l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDinUser l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDinUser l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinEmpty(ListDinUser l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDinUser l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

// Mengembalikan indeks dengan username tertentu
IdxType indexOfUsername(ListDinUser l, char * username);



/* ********** OPERASI LAIN ********** */
void copyList(ListDinUser lIn, ListDinUser *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDinUser *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDinUser *l, ElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

// Menampilkan data user
void printUser(User user);
// I.S. user terdefinisi
// F.S. Ditampilkan data dari user

// Memasukan item pada elemen pada list sesuai ID user
void insertUserByID(ListDinUser *list, ElType item);
// I.S. list dan item terdefinisi. item.id bernilai dan dapat menjadi indeks yang valid
// F.S. list.buffer[item.id] terisi dengan data pada item
//      jika item.id >= list.nEff, maka list.nEff = item.id + 1

// Menampilkan list data user
void printList(ListDinUser l);
// I.S. list user terdefinisi
// F.S. Ditampilkan list data user

// Menyortir List user berdasarkan id
void sortUser(ListDinUser *list);
// I.S. list terdefinisi
// F.S. list tersortir ascending menurut id

// Mengembalikan indeks user dengan id tertentu
int cariIdxUser(ListDinUser * UserData, int id);

// Mengembalikan username user
const char* cariUsername(ListDinUser UserData, int idPasien); 

// Mengembalikan nilai bertipe User yang memiliki komponen-komponen default.
User createEmptyUser();

// Mereset data user, digunakan ketika ingin memulangkan pasien.
void resetUserData(User *user);
// I.S. user terdefinisi, user merupakan pasien.
// F.S. Semua data user kecuali ID, username, password, dan role direset.

// Menghilangkan user dengan indeks tertentu dari list.
void deleteUser(ListDinUser *list, int idx);
// I.S. list dan idx terdefinisi.
// F.S. Semua komponen yang ada pada elemen indeks idx direset menjadi default.

// Menuliskan List User ke dalam file
void writeListUser(char * folderPath, ListDinUser *list);
// I.S. list terdefinisi dan terisi
// F.S. File user.csv berada pada folder yang ditujukan

#endif