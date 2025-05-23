#include "Boolean.h"
#include <stdio.h>
#include "../header/config.h"
#include "../header/config_queue.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueConfig, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void createQueueConfig(QueueConfig *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isQueueEmptyConfig(QueueConfig q){
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q)==IDX_UNDEF;
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isQueueFullConfig(QueueConfig q){
    return (IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY);
}

/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
int queueLengthConfig(QueueConfig q){
    if (isEmpty(q)) return 0;
    int i = IDX_HEAD(q);
    int count = 0;
    while (i != IDX_TAIL(q)){
        count += 1;
        i = (i + 1) % CAPACITY;
    }
    count++;
    return count;
}
/* Mengirimkan banyaknya elemen QueueConfig. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enQueueConfig(QueueConfig *q, int val){
    if (isEmpty(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
        q->buffer[0] = val;
    }
    else if (!isFull(*q)){
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }

}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh. Jangan lakukan apapun apabila penampung penuh. */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void deQueueConfig(QueueConfig *q, int *val){
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        *val = HEAD(*q);
        CreateQueueConfig(q);
    }
    else if (!isEmpty(*q)){
        *val = HEAD(*q);
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, jangan lakukan apa-apa bila kosong*/
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueueConfig *** */
void displayQueueConfig(QueueConfig q) {
    printf("[");
    if (!isEmpty(q)) {
        int len = length(q);  
        int i = IDX_HEAD(q);
        for (int j = 0; j < len; j++) {
            if(j == len - 1){
                printf("%d", q.buffer[i]);
            }
            else{
                printf("%d,",q.buffer[i]);
            }
            i = (i + 1) % CAPACITY;
        }
    }
    printf("]\n");
}
/* Proses : Menuliskan isi QueueConfig dengan traversal, QueueConfig ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueueConfig kosong : menulis [] */