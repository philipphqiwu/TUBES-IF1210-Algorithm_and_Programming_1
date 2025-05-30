#include "../header/F16.h"
#include "../header/F03.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minumObat(int *loginID, int *loginState, Config *config, ListDinUser *listUser, ListObat listObat, ListPenyakit listPenyakit, MapObatPenyakit mapObatPenyakit){
    int userIdx = cariIdxUser(listUser, *loginID);
    if(isMatriksRowEmpty(config->inventoryPasien, *loginID)){
        printf(COLOR_RED"Kamu tidak memiliki obat!\n"COLOR_RESET);
        return;
    }
    printf(COLOR_YELLOW"============ DAFTAR OBAT ============\n");
    int nomorObat = 1;
    int obatAvailable[MAX_OBAT_PER_PENYAKIT];
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        int obatID = config->inventoryPasien.contents[*loginID][i];
        int obatIdx = cariIdxObat(&listObat, obatID);
        if(obatID == 0) continue;
        printf("%d. %s\n", nomorObat, listObat.items[obatIdx].nama_obat);
        obatAvailable[nomorObat] = obatID;
        nomorObat++;
    }
    printf("Pilih obat untuk diminum: ");
    int obatPilihan;
    
    while(scanf("%d", &obatPilihan) !=  1 || obatPilihan <= 0 || obatPilihan >= nomorObat){
        printf(COLOR_RED"Pilihan nomor tidak tersedia!\n"COLOR_RESET);
        printf(COLOR_YELLOW"Pilih obat untuk diminum: ");
        while (getchar() != '\n');
    }
    int obatIdx = cariIdxObat(&listObat, obatAvailable[obatPilihan]);
    if(config->perutPasien[*loginID].head == NULL){
        config->jumlahPerutPasien++;
    }
    printf("GLEKGLEKGLEK... %s berhasil diminum!!!\n"COLOR_RESET, listObat.items[obatIdx].nama_obat);
    push(&(config->perutPasien[*loginID]), obatAvailable[obatPilihan]);
    for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
        if(config->inventoryPasien.contents[*loginID][i] == obatAvailable[obatPilihan]){
            for(int j = i; j < MAX_OBAT_PER_PENYAKIT-1; j++){
                if(config->inventoryPasien.contents[*loginID][j] == 0){
                    config->inventoryPasien.contents[*loginID][j+1] = 0;
                    break;
                }
                config->inventoryPasien.contents[*loginID][j] = config->inventoryPasien.contents[*loginID][j+1];
            }
            break;
        }
    }
    int penyakitId = searchPenyakitIDByName(listPenyakit, listUser->buffer[userIdx].riwayat_penyakit);
    int urutanObat = config->perutPasien[*loginID].length;
    // printf("urutanObat: %d; obatTerminum: %d; seharusnya: %d\n", urutanObat, peekStack(&config->perutPasien[*loginID]), mapObatPenyakit.items[penyakitId].value[urutanObat].obat_id);
    if(peekStack(&config->perutPasien[*loginID]) != mapObatPenyakit.items[penyakitId].value[urutanObat].obat_id){
        listUser->buffer[userIdx].nyawa--;
        printf(COLOR_RED"Kamu salah minum obat! Nyawamu berkurang menjadi %d!", listUser->buffer[userIdx].nyawa);
        for(int i = 0; i < listUser->buffer[userIdx].nyawa; i++){
            printf("\u2764\uFE0F ");
        }
        for(int i = 0; i < 3 - listUser->buffer[userIdx].nyawa; i++){
            printf("\U0001F90D");
        }
        printf("\n");
        printf(COLOR_RED"Segera kontak dokter untuk minum penawar!\n"COLOR_RESET);
    }
    if(!listUser->buffer[userIdx].nyawa){
        int posisiPasien[2] = {-1, -1};
        for(int i = 0; i < config->denah.rows; i++){
            for(int j = 0; j < config->denah.cols; j++){
                if(config->denah.contents[i][j].antrian->front->data == *loginID){
                    posisiPasien[0] = i;
                    posisiPasien[1] = j;
                    break;
                }
            }
            if(posisiPasien[0] == i) break;
        }
        dequeue(config->denah.contents[posisiPasien[0]][posisiPasien[1]].antrian);
        deleteUser(listUser, userIdx);
        for(int i = 0; i < MAX_OBAT_PER_PENYAKIT; i++){
            insertMatrixByIndex(&config->inventoryPasien, *loginID, i, 0);
        }
        config->jumlahPemilikObat--;
        int banyakObat = config->perutPasien[*loginID].length;
        for(int i = 0; i < banyakObat; i++){
            pop(&(config->perutPasien[*loginID]));
        }
        config->jumlahPerutPasien--;
        printf(COLOR_MAGENTA"Mohon maaf, karena kamu telah meminum obat yang salah sebanyak tiga kali, rumah sakit enggan untuk memberimu penawar.\n");
        printf(COLOR_MAGENTA"Kamu dinyatakan ded. \U0001F480\n");
        printf(COLOR_RESET);
        // printList(*listUser);
        logout(loginState, loginID);
        return;
    }
    if(config->inventoryPasien.contents[*loginID][0] == 0){
        config->jumlahPemilikObat--;
    }
}