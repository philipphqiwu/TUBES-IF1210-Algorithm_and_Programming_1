#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/user.h"
#include "../header/Boolean.h"



void printUser(User user){
    printf("%d,%s,%s,%s", user.id, user.username, user.password, user.role);
    if(strcmp(user.role,"pasien")==0){
        printf(",%s,%f,%d,%d,%d,%f,%d,%f,%d,%d,%d,%d", user.riwayat_penyakit, user.suhu_tubuh, user.tekanan_darah_sistolik, user.tekanan_darah_diastolik, user.detak_jantung,
        user.saturasi_oksigen, user.kadar_gula_darah, user.berat_badan, user.tinggi_badan, user.kadar_kolesterol, user.trombosit, user.nyawa);
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
        if(l.buffer[i].id == 0) continue;
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

void insertUserByID(ListDinUser *list, ElType item){
    list->buffer[item.id] = item;
    if(list->nEff <= item.id){
        list->nEff = item.id + 1;
    }
}

void sortUser(ListDinUser *list){
    for(int i = 0; i < list->nEff-1; i++){
        for(int j = 0; j < list->nEff-i-1; j++){
            if(list->buffer[j].id>list->buffer[j+1].id){
                User temp = list->buffer[j];
                list->buffer[j] = list->buffer[j+1];
                list->buffer[j+1] = temp;
            }
        }
    }
}

int cariIdxUser(ListDinUser * UserData, int id){
    int left = 0;
    int right = UserData->nEff - 1;
    int mid = (left + right)/2;

    while(left < right){
        if(UserData->buffer[mid].id > id){
            right = mid;
            mid = (left+right)/2;
        } else if (UserData->buffer[mid].id < id){
            left = mid+1;          
            mid = (left+right)/2;
        } else if(UserData->buffer[mid].id == id){
            break;
        }
    }
    if(UserData->buffer[mid].id == id){
        return mid;
    }
    return -1;
}

const char* cariUsername(ListDinUser UserData, int ID) {
    int idxUser = cariIdxUser(&UserData, ID);
    if (idxUser == -1) {
        return "-";
    }
    return UserData.buffer[idxUser].username;
}

User createEmptyUser(){
    User user;
    user.id = 0;
    strcpy(user.username, "");
    strcpy(user.password, "");
    strcpy(user.role, "");
    strcpy(user.riwayat_penyakit, "");
    user.suhu_tubuh = 0;
    user.tekanan_darah_sistolik = 0;
    user.tekanan_darah_diastolik = 0;
    user.detak_jantung = 0;
    user.saturasi_oksigen = 0;
    user.kadar_gula_darah = 0;
    user.berat_badan = 0;
    user.tinggi_badan = 0;
    user.kadar_kolesterol = 0;
    user.trombosit = 0;
    user.nyawa = 3;
    return user;
}

void resetUserData(User *user){
    strcpy(user->riwayat_penyakit, "");
    user->suhu_tubuh = 0;
    user->tekanan_darah_sistolik = 0;
    user->tekanan_darah_diastolik = 0;
    user->detak_jantung = 0;
    user->saturasi_oksigen = 0;
    user->kadar_gula_darah = 0;
    user->berat_badan = 0;
    user->tinggi_badan = 0;
    user->kadar_kolesterol = 0;
    user->trombosit = 0;
    user->nyawa = 3;
}

void deleteUser(ListDinUser *list, int idx){
    if(idx == list->nEff-1){
        list->buffer[idx].id = 0;
        strcpy(list->buffer[idx].username, "");
        strcpy(list->buffer[idx].password, "");
        strcpy(list->buffer[idx].role, "");
        strcpy(list->buffer[idx].riwayat_penyakit, "");
        list->buffer[idx].suhu_tubuh = 0;
        list->buffer[idx].tekanan_darah_sistolik = 0;
        list->buffer[idx].tekanan_darah_diastolik = 0;
        list->buffer[idx].detak_jantung = 0;
        list->buffer[idx].saturasi_oksigen = 0;
        list->buffer[idx].kadar_gula_darah = 0;
        list->buffer[idx].berat_badan = 0;
        list->buffer[idx].tinggi_badan = 0;
        list->buffer[idx].kadar_kolesterol = 0;
        list->buffer[idx].trombosit = 0;
        list->buffer[idx].nyawa = 3;
    }
    else{
        for(int i = idx; i < list->nEff-1; i++){
            list->buffer[i] = list->buffer[i+1];
        }
    }
    list->nEff--;
}

void writeListUser(char * folderPath, ListDinUser *list){
    char fullFilePath[300];
    snprintf(fullFilePath, sizeof(fullFilePath),"%s/user.csv", folderPath ); 
    FILE * file = fopen(fullFilePath, "w");
    fprintf(file, "id;username;password;role;riwayat_penyakit;suhu_tubuh;tekanan_darah_sistolik;tekanan_darah_diastolik;detak_jantung;saturasi_oksigen;kadar_gula_darah;berat_badan;tinggi_badan;kadar_kolesterol;trombosit;nyawa;aura\n");

    for(int i = 0; i<list->nEff; i++){
        fprintf(file, "%d;%s;%s;%s;%s", list->buffer[i].id, list->buffer[i].username, list->buffer[i].password, list->buffer[i].role, list->buffer[i].riwayat_penyakit);
        if(list->buffer[i].suhu_tubuh != 0){
            fprintf(file, ";%f;%d;%d;%d;%f;%d;%f;%d;%d;%d;%d;", list->buffer[i].suhu_tubuh, list->buffer[i].tekanan_darah_sistolik, list->buffer[i].tekanan_darah_diastolik, list->buffer[i].detak_jantung,
            list->buffer[i].saturasi_oksigen, list->buffer[i].kadar_gula_darah, list->buffer[i].berat_badan, list->buffer[i].tinggi_badan, list->buffer[i].kadar_kolesterol, list->buffer[i].trombosit, list->buffer[i].nyawa);
        } else{
            if(strcmp(list->buffer[i].role,"pasien") == 0){
                fprintf(file, ";;;;;;;;;;;%d;", list->buffer[i].nyawa);
            }
            else{
                fprintf(file, ";;;;;;;;;;;;");
            }
            if(strcmp(list->buffer[i].role,"dokter") == 0){
                fprintf(file, "%d", list->buffer[i].aura);
            }
        }
        fprintf(file,"\n");
    }

    fclose(file);
}