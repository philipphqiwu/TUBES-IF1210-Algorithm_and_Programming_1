#include "../header/B06.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void skipAntrian(int loginID, Config *config, ListDinUser listUser){
    int inAntrian = 0;
    int posisi[2] = {-1, -1};
    for(int i = 0; i < config->denah.rows && !inAntrian; i++){
        for(int j = 0; j < config->denah.cols && !inAntrian; j++){
            if(config->denah.contents[i][j].dokterID == 0) continue;
            Node *temp = config->denah.contents[i][j].antrian->front;
            // printf("looping\n");
            while(temp != NULL && !inAntrian){
                if(temp->data == loginID){
                    inAntrian = 1;
                    posisi[0] = i;
                    posisi[1] = j;
                }
                temp = temp->next;
            }
        }
    }
    if(!inAntrian){
        printf("Skip antrian gagal! Anda tidak sedang terdaftar dalam antrian manapun!\n");
        return;
    }
    else if(peekQueue(config->denah.contents[posisi[0]][posisi[1]].antrian) == loginID){
        printf("Anda sudah berada di posisi paling depan antrian! Tidak bisa skip lagi.\n");
        return;
    }
    // printf("out\n");
    Queue *tempQueue = createQueue();
    while(config->denah.contents[posisi[0]][posisi[1]].antrian->front != NULL){
        int tempId = dequeue(config->denah.contents[posisi[0]][posisi[1]].antrian);
        enqueue(tempQueue, tempId);
    }
    enqueue(config->denah.contents[posisi[0]][posisi[1]].antrian, loginID);
    while(tempQueue->front != NULL){
        int tempId = dequeue(tempQueue);
        if(tempId == loginID) continue;
        enqueue(config->denah.contents[posisi[0]][posisi[1]].antrian, tempId);
    }
    // printQueue(config->denah.contents[posisi[0]][posisi[1]].antrian);
    char namaDokter[MAX_NAME_LENGTH]; 
    strcpy(namaDokter, cariUsername(listUser, config->denah.contents[posisi[0]][posisi[1]].dokterID));
    printf("Anda berhasil maju ke depan antrian Dr. %s di ruangan %s!\n", namaDokter, config->denah.contents[posisi[0]][posisi[1]].kodeRuangan);
    printf("Posisi antrian Anda sekarang: 1\n");
}

void cancelAntrian(int loginID, Config *config, ListDinUser *listUser){
    int inAntrian = 0;
    int posisi[2] = {-1, -1};
    for(int i = 0; i < config->denah.rows && !inAntrian; i++){
        for(int j = 0; j < config->denah.cols && !inAntrian; j++){
            if(config->denah.contents[i][j].dokterID == 0) continue;
            Node *temp = config->denah.contents[i][j].antrian->front;
            // printf("looping\n");
            while(temp != NULL && !inAntrian){
                if(temp->data == loginID){
                    inAntrian = 1;
                    posisi[0] = i;
                    posisi[1] = j;
                }
                temp = temp->next;
            }
        }
    }
    if(!inAntrian){
        printf("Pembatalan antrian gagal! Anda tidak sedang terdaftar dalam antrian manapun!\n");
        return;
    }
    Queue *tempQueue = createQueue();
    while(config->denah.contents[posisi[0]][posisi[1]].antrian->front != NULL){
        int tempId = dequeue(config->denah.contents[posisi[0]][posisi[1]].antrian);
        enqueue(tempQueue, tempId);
    }
    while(tempQueue->front != NULL){
        int tempId = dequeue(tempQueue);
        if(tempId == loginID) continue;
        enqueue(config->denah.contents[posisi[0]][posisi[1]].antrian, tempId);
    }
    int userIdx = cariIdxUser(listUser, loginID);
    resetUserData(&(listUser->buffer[userIdx]));
    for(int i = 0; i < config->inventoryPasien.cols; i++){
        config->inventoryPasien.contents[loginID][i] = 0;
    }
    config->jumlahPemilikObat--;
    int banyakObat = config->perutPasien[loginID].length;
    for(int i = 0; i < banyakObat; i++){
        pop(&(config->perutPasien[loginID]));
    }
    config->jumlahPerutPasien--;
    // printQueue(config->denah.contents[posisi[0]][posisi[1]].antrian);
    char namaDokter[MAX_NAME_LENGTH]; 
    strcpy(namaDokter, cariUsername(*listUser, config->denah.contents[posisi[0]][posisi[1]].dokterID));
    printf("Anda berhasil keluar dari antrian Dr. %s di ruangan %s.\n", namaDokter, config->denah.contents[posisi[0]][posisi[1]].kodeRuangan);
}