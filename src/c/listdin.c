/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
memori list dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "../header/Boolean.h"
#include "../header/listdin.h"
/*  Kamus Umum */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    l->nEff = 0;
    l->capacity = capacity;
    l->buffer = (ElType*) malloc (capacity*sizeof(ElType));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
    free(l->buffer);
    l->nEff = 0;
    l->capacity = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
    return l.nEff;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
    return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l){
    return l.nEff-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    if ( i <= (l.capacity-1) && i >= 0) return true;
    return false;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
    if ( i <= (l.nEff-1) && i >= 0) return true;
    return false;
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return l.nEff==0;
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
    return l.nEff == l.capacity;
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
    int n;
    do {
        scanf("%d",&n);
    } while ( n<0 || n> l->capacity);
    l->nEff =n;
    for (int i=0;i<n;i++){
        scanf("%d",&(l->buffer[i]));
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l){
    printf("[");
    for (int i=0;i<l.nEff;i++){
        printf("%d",l.buffer[i]);
        if (i!=l.nEff-1) printf(",");
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin l3;
    CreateListDin(&l3,l1.capacity);
    l3.nEff = l1.nEff;
    if (plus == true){
        for (int i=0;i<l1.nEff;i++){
            l3.buffer[i] = l1.buffer[i]+l2.buffer[i];
        }
    }
    else {
        for (int i=0;i<l1.nEff;i++){
            l3.buffer[i] = l1.buffer[i]-l2.buffer[i];
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
    if (l1.nEff == l2.nEff){
        for (int i=0;i<l1.nEff;i++){
            if(l1.buffer[i]!=l2.buffer[i]) return false;
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
    for (int i=0; i<l.nEff ; i++){
        if (l.buffer[i] == val) return i;
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
    *max = l.buffer[0];
    *min = l.buffer[0];
    for(int i=0; i<l.nEff ; i++){
        if(l.buffer[i] > *max) *max = l.buffer[i];
        if(l.buffer[i]<*min) *min = l.buffer[i];
    }

}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut,lIn.capacity);
    lOut->nEff = lIn.nEff;
    for(int i = 0; i<lIn.nEff ; i++){
        lOut->buffer[i] = lIn.buffer[i];
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l){
    int sum=0;
    for(int i = 0;i<l.nEff;i++){
        sum += l.buffer[i];
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
    int sum=0;
    for(int i = 0;i<l.nEff;i++){
        if(l.buffer[i] == val) sum++;
    }
    return sum;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
    for(int i = 0; i<l->nEff-1;i++){
        for(int j = 0 ; j < l->nEff-i-1; j++){
            if ( asc == true && l->buffer[j]>l->buffer[j+1]){
                l->buffer[j] = l->buffer[j+1]+l->buffer[j] - (l->buffer[j+1] = l->buffer[j]);
            }
            else if( asc == false && l->buffer[j]<l->buffer[j+1]){
                l->buffer[j] = l->buffer[j+1]+l->buffer[j] - (l->buffer[j+1] = l->buffer[j]);
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
    algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
    l->buffer[l->nEff]= val;
    l->nEff++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
    *val = l->buffer[l->nEff-1];
    l->nEff--;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
    l->capacity += num;
    l->buffer = (ElType*)realloc(l->buffer,l->capacity*sizeof(ElType));
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    if (l->capacity > num && l->nEff <= (l->capacity - num)) {
        l->capacity -= num;
        l->buffer = (ElType*) realloc(l->buffer, l->capacity * sizeof(ElType));
    }
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    l->capacity = l->nEff;
    l->buffer = (ElType*)realloc(l->buffer,l->capacity*sizeof(ElType));

}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
