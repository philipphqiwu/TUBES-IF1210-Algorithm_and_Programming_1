#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/user.h"
#include "../header/Boolean.h"

void printUser(User user){
    printf("%d,%s,%s,%s", user.id, user.username, user.password, user.role);
    if(strcmp(user.role,"pasien")==0){
        printf(",%s,%f,%d,%d,%d,%f,%d,%f,%d,%d,%d,%d", user.riwayat_penyakit, user.suhu_tubuh, user.tekanan_darah_sistolik, user.tekanan_darah_diastolik, user.detak_jantung,
        user.saturasi_oksigen, user.kadar_gula_darah, user.berat_badan, user.tinggi_badan, user.kadar_kolesterol, user.kadar_kolesterol_ldl, user.trombosit);
    }
}

void CreateListDinUser(ListDinUser *l, int capacity){
    l->nEff = 0;
    l->capacity = capacity;
    l->buffer = (ElType*) malloc (capacity*sizeof(ElType));
}

void dealocateList(ListDinUser *l){
    free(l->buffer);
    l->nEff = 0;
    l->capacity = 0;
}

int listLength(ListDinUser l){
    return l.nEff;
}

IdxType getFirstIdx(ListDinUser l){
    return 0;
}

IdxType getLastIdx(ListDinUser l){
    return l.nEff-1;
}

boolean isIdxValid(ListDinUser l, IdxType i){
    if ( i <= (l.capacity-1) && i >= 0) return true;
    return false;
}

boolean isIdxEff(ListDinUser l, IdxType i){
    if ( i <= (l.nEff-1) && i >= 0) return true;
    return false;
}

boolean isEmpty(ListDinUser l){
    return l.nEff==0;
}

boolean isFull(ListDinUser l){
    return l.nEff == l.capacity;
}

void printList(ListDinUser l){
    for (int i=0;i<l.nEff;i++){
        printUser(l.buffer[i]);
        printf("\n");
    }
    
}

IdxType indexOfUsername(ListDinUser l, char* username){
    for (int i = 0; i < l.nEff; i++) {
        if (strcmp(l.buffer[i].username, username) == 0) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void copyList(ListDinUser lIn, ListDinUser *lOut){
    CreateListDinUser(lOut,lIn.capacity);
    lOut->nEff = lIn.nEff;
    for(int i = 0; i<lIn.nEff ; i++){
        lOut->buffer[i] = lIn.buffer[i];
    }
}

void insertLast(ListDinUser *l, ElType val){
    l->buffer[l->nEff]= val;
    l->nEff++;
}

void deleteLast(ListDinUser *l, ElType *val){
    *val = l->buffer[l->nEff-1];
    l->nEff--;
}

void expandList(ListDinUser *l, int num){
    l->capacity += num;
    l->buffer = (ElType*)realloc(l->buffer,l->capacity*sizeof(ElType));
}

void shrinkList(ListDinUser *l, int num){
    if (l->capacity > num && l->nEff <= (l->capacity - num)) {
        l->capacity -= num;
        l->buffer = (ElType*) realloc(l->buffer, l->capacity * sizeof(ElType));
    }
}

void compressList(ListDinUser *l){
    l->capacity = l->nEff;
    l->buffer = (ElType*)realloc(l->buffer,l->capacity*sizeof(ElType));

}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

void insertUserByID(ListDinUser *list, ElType item){
    list->buffer[item.id] = item;
    if(list->nEff <= item.id){
        list->nEff = item.id + 1;
    }
}

void writeListUser(char * folderPath, ListDinUser *list){
    char fullFilePath[300];
    snprintf(fullFilePath, sizeof(fullFilePath),"%s/user.csv", folderPath ); 
    FILE * file = fopen(fullFilePath, "w");
    fprintf(file, "id;username;password;role;riwayat_penyakit;suhu_tubuh;tekanan_darah_sistolik;tekanan_darah_diastolik;detak_jantung;saturasi_oksigen;kadar_gula_darah;berat_badan;tinggi_badan;kadar_kolesterol;kadar_kolesterol_ldl;trombosit\n");

    for(int i = 0; i<list->nEff; i++){
        fprintf(file, "%d;%s;%s;%s;%s", list->buffer[i].id, list->buffer[i].username, list->buffer[i].password, list->buffer[i].role, list->buffer[i].riwayat_penyakit);
        if(list->buffer[i].suhu_tubuh != 0){
            fprintf(file, ";%f;%d;%d;%d;%f;%d;%f;%d;%d;%d;%d", list->buffer[i].suhu_tubuh, list->buffer[i].tekanan_darah_sistolik, list->buffer[i].tekanan_darah_diastolik, list->buffer[i].detak_jantung,
            list->buffer[i].saturasi_oksigen, list->buffer[i].kadar_gula_darah, list->buffer[i].berat_badan, list->buffer[i].tinggi_badan, list->buffer[i].kadar_kolesterol, list->buffer[i].kadar_kolesterol_ldl, list->buffer[i].trombosit);
        } else{
            fprintf(file, ";;;;;;;;;;;");
        }
        fprintf(file,"\n");
    }

    fclose(file);
}