#include "../header/F13.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pulangDok(int loginID, Config *config, ListDinUser *listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    int userIdx = cariIdxUser(listUser, loginID);
    int penyakitId = searchPenyakitIDByName(listPenyakit, listUser->buffer[userIdx].riwayat_penyakit);
    if(listUser->buffer[userIdx].suhu_tubuh == 0){
        printf(COLOR_RED"Kamu belum checkup!\n"COLOR_RESET);
        return;
    }
    else if(!strcmp(listUser->buffer[userIdx].riwayat_penyakit, "")){
        printf(COLOR_RED"Kamu belum menerima diagnosis apapun dari dokter, jangan buru-buru pulang!\n"COLOR_RESET);
        return;
    }
    else if(isMatriksRowEmpty(config->inventoryPasien, loginID) && config->perutPasien[loginID].head == NULL){
        printf(COLOR_RED"Kamu belum menerima obat apapun dari dokter!\n"COLOR_RESET);
        return;
    }
    else if(!isMatriksRowEmpty(config->inventoryPasien, loginID)){
        printf(COLOR_RED"Masih ada obat yang belum kamu habiskan, minum semuanya dulu yukk!\n"COLOR_RESET);
        return;
    }
    printf("Dokter sedang memeriksa keadaanmu...\n\n");
    int urutanSalah = cekPerutDenganUrutan(config->perutPasien[loginID], penyakitId, mapObatPenyakit);
    // printf("urutanSalah: %d\n", urutanSalah);
    if(isMatriksRowEmpty(config->inventoryPasien, loginID) && urutanSalah){
        printf(COLOR_RED"Maaf, tapi kamu masih belum bisa pulang!\n\n"COLOR_RESET);
        int banyakObat = config->perutPasien[loginID].length;
        // printf("banyakObat %d\n", banyakObat);
        int isiPerut[banyakObat+1];
        Node* temp = config->perutPasien[loginID].head;
        // printf("obat di perut %d\n", temp->data);
        int i = banyakObat;
        // printf("hit\n");
        // printStack(config->perutPasien[loginID]);
        while(temp != NULL && i > 0){
            // printf("loop%d\n", i);
            // printf("obat di perut %d\n", temp->data);
            isiPerut[i] = temp->data;
            i--;
            temp = temp->next;
        }
        printf("Urutan peminuman obat yang diharapkan:\n");
        for(int i = 1; i < banyakObat+1; i++){
            int obatId = mapObatPenyakit.items[penyakitId].value[i].obat_id;
            int obatIdx = cariIdxObat(&listObat, obatId);
            char namaObat[MAX_NAMA_OBAT];
            strcpy(namaObat, listObat.items[obatIdx].nama_obat);
            if(i == 1) printf("%s", namaObat);
            else printf(" -> %s", namaObat);
        }
        printf("\n\n");
        printf("Urutan obat yang kamu minum:\n");
        for(int i = 1; i < banyakObat+1; i++){
            int obatId = isiPerut[i];
            int obatIdx = cariIdxObat(&listObat, obatId);
            char namaObat[MAX_NAMA_OBAT];
            strcpy(namaObat, listObat.items[obatIdx].nama_obat);
            if(i < urutanSalah){
                if(i == 1) printf("%s", namaObat);
                else printf(" -> %s", namaObat);
            }
            else{
                if(i == 1) printf(COLOR_RED"%s"COLOR_RESET, namaObat);
                else printf(COLOR_RED" -> %s"COLOR_RESET, namaObat);
            }
        }
        printf("\n\n");
        printf("Silahkan kunjungi dokter untuk meminta penawar yang sesuai!\n");
        return;
    }
    int posisiPasien[2] = {-1, -1};
    for(int i = 0; i < config->denah.rows; i++){
        for(int j = 0; j < config->denah.cols; j++){
            if(config->denah.contents[i][j].antrian->front->data == loginID){
                posisiPasien[0] = i;
                posisiPasien[1] = j;
                break;
            }
        }
        if(posisiPasien[0] == i) break;
    }
    dequeue(config->denah.contents[posisiPasien[0]][posisiPasien[1]].antrian);
    resetUserData(&(listUser->buffer[userIdx]));
    int banyakObat = config->perutPasien[loginID].length;
    for(int i = 0; i < banyakObat; i++){
        pop(&(config->perutPasien[loginID]));
    }
    printf("Selamat! Kamu sudah dinyatakan sembuh oleh dokter. Silahkan pulang dan semoga sehat selalu!\n");
    config->jumlahPerutPasien--;
}

int cekPerutDenganUrutan(Stack perut, int penyakitID, MapObatPenyakit mapObatPenyakit){
    int result = 0;
    Node* temp = perut.head;
    for(int i = MAX_OBAT_PER_PENYAKIT-1; i > 0; i--){
        int obatID = mapObatPenyakit.items[penyakitID].value[i].obat_id;
        if(obatID == 0) continue;
        int obatDalamPerut = temp->data;
        if(obatID != obatDalamPerut){
            result = i;
        }
        temp = temp->next;
    }
    return result;
}