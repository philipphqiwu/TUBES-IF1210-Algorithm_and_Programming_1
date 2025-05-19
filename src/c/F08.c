#include "../header/F08.h"

void findBased(int * base, int type){ 
    // Validation for finding base
    while (1) {
        printf("Cari berdasarkan?\n");
        printf("1. ID\n");
        printf("2. Nama\n");
        if(type == 2){
            printf("3. Penyakit\n");
        }
        printf(">>> Pilihan : ");
        if (scanf("%d", base) != 1 || (*base != 1 && *base != 2)) {
            if(type == 2 && *base == 3){
                break;
            }
            printf("Input tidak valid! Pilih opsi yang valid.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;  
        }
    }
}

int binSearchId(ListDinUser * UserData, int id){
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

int seqSearchName(ListDinUser * UserData, char * name){
    for(int i = 0; i < UserData->nEff; i++){
        if(strcmp(UserData->buffer[i].username,name)==0){
            return i;
        }
    }
    return -1;

}

void findId(ListDinUser * UserData, int type){
    int id;
    char ch;
    while(1){
        printf(">>> Masukkan nomor ID ");
        switch (type){
            case 1:
                printf("user: ");
                break;
            case 2:
                printf("pasien: ");
                break;
            case 3:
                printf("dokter: ");
                break;
        }
        if (scanf("%d%c", &id, &ch) != 2 || ch != '\n'){
            printf("Masukkan input yang valid!\n");
        } else if(id <= 0 || id > 100){
            printf("ID HARUS ANTARA 1 DAN 100 !");
        } else {
            break;  
        }
    }
    int idx = binSearchId(UserData, id);
    if(idx == -1){
        printf("Tidak ditemukan ");
        switch (type){
            case 1:
                printf("user: ");
                break;
            case 2:
                printf("pasien: ");
                break;
            case 3:
                printf("dokter: ");
                break;
        }
        printf("dengan id %d!\n", id);
    } else{
        switch (type){
            case 1:
                printf("ID | Nama                | Role    | Penyakit\n");
                printf("----------------------------------------------------------\n");
                printf("%-3d| %-20s| %-8s| %-20s\n", UserData->buffer[idx].id, UserData->buffer[idx].username, UserData->buffer[idx].role, strlen(UserData->buffer[idx].riwayat_penyakit) == 0 ? "-" : UserData->buffer[idx].riwayat_penyakit);
                break;
            case 2:
                if(strcmp(UserData->buffer[idx].role,"pasien") == 0){
                    printf("ID | Nama                | Penyakit\n");
                    printf("----------------------------------------------------------\n");
                    printf("%-3d| %-20s| %-20s\n", UserData->buffer[idx].id, UserData->buffer[idx].username, strlen(UserData->buffer[idx].riwayat_penyakit) == 0 ? "-" : UserData->buffer[idx].riwayat_penyakit);            
                } else{
                    printf("Pasien dengan id %d tidak ditemukan!\n", id);
                }
                break;
            case 3:
                if(strcmp(UserData->buffer[idx].role,"dokter") == 0){
                    printf("ID | Nama\n");
                    printf("----------------------------------------------------------\n");
                    printf("%-3d| %-20s\n", UserData->buffer[idx].id, UserData->buffer[idx].username);  
                } else{
                    printf("Dokter dengan id %d tidak ditemukan!\n", id);
                }  
                break;
            }
    }
}

void findName(ListDinUser * UserData, int type){
    char name[21];
    while(1){
        printf(">>> Masukkan nama ");
        switch (type){
            case 1:
                printf("user: ");
                break;
            case 2:
                printf("pasien: ");
                break;
            case 3:
                printf("dokter: ");
                break;
        }
        scanf("%s", name);

        if (strlen(name) > 20) {
            printf("Error: Username melebihi 20 characters.\n");
        } else {
            break;  
        }
    }
    int idx = seqSearchName(UserData, name);
    if(idx == -1){
        printf("Tidak ditemukan ");
        switch (type){
            case 1:
                printf("user: ");
                break;
            case 2:
                printf("pasien: ");
                break;
            case 3:
                printf("dokter: ");
                break;
        }
        printf("dengan nama %s!\n", name);
    } else{
        switch (type){
            case 1:
                printf("ID | Nama                | Role    | Penyakit\n");
                printf("----------------------------------------------------------\n");
                printf("%-3d| %-20s| %-8s| %-20s\n", UserData->buffer[idx].id, UserData->buffer[idx].username, UserData->buffer[idx].role, strlen(UserData->buffer[idx].riwayat_penyakit) == 0 ? "-" : UserData->buffer[idx].riwayat_penyakit);
                break;
            case 2:
                if(strcmp(UserData->buffer[idx].role,"pasien") == 0){
                    printf("ID | Nama                | Penyakit\n");
                    printf("----------------------------------------------------------\n");
                    printf("%-3d| %-20s| %-20s\n", UserData->buffer[idx].id, UserData->buffer[idx].username, strlen(UserData->buffer[idx].riwayat_penyakit) == 0 ? "-" : UserData->buffer[idx].riwayat_penyakit);            
                } else{
                    printf("Pasien dengan username %s tidak ditemukan!\n", name);
                }
                break;
            case 3:
                if(strcmp(UserData->buffer[idx].role,"dokter") == 0){
                    printf("ID | Nama\n");
                    printf("----------------------------------------------------------\n");
                    printf("%-3d| %-20s\n", UserData->buffer[idx].id, UserData->buffer[idx].username);    
                } else{
                    printf("Dokter dengan username %s tidak ditemukan!\n", name);
                }
                break;
            }
    }
}

void tampilPenyakit(User *ptrs[], int base, int order, int length, char * penyakit){
    if(base == 3 && order == 3){
        printf("ID | Nama                | Penyakit\n");
        printf("----------------------------------------------------------\n");
        for(int i = 0; i < length; i++){
            if(strcmp(ptrs[i]->role,"pasien") == 0 && strcmp(ptrs[i]->riwayat_penyakit,penyakit)==0){
                printf("%-3d| %-20s| %-20s\n", ptrs[i]->id, ptrs[i]->username, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
            }
        }
        return;
    } 
    printf("Menampilkan semua pasien dengan penyakit %s ",penyakit);    
    printf("terurut berdasarkan ");
    switch(base){
        case 1:
            printf("ID ");
            break;
    case 2:
            alphabetSort(ptrs, length);
            printf("nama ");
            break;
    }    
    switch(order){
        case 1:
            printf("ascending...\n");
            printf("ID | Nama                | Penyakit\n");
            printf("----------------------------------------------------------\n");
            for(int i = 0; i < length; i++){
                if(strcmp(ptrs[i]->role,"pasien") == 0 && strcmp(ptrs[i]->riwayat_penyakit,penyakit)==0){
                    printf("%-3d| %-20s| %-20s\n", ptrs[i]->id, ptrs[i]->username, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
                }
            }
            break;
        case 2:
            printf("descending...\n");
            printf("ID | Nama                | Penyakit\n");
            printf("----------------------------------------------------------\n");
                for(int i = length-1; i >= 0; i--){
                    if(strcmp(ptrs[i]->role,"pasien") == 0 && strcmp(ptrs[i]->riwayat_penyakit,penyakit)==0){
                        printf("%-3d| %-20s| %-20s\n", ptrs[i]->id, ptrs[i]->username, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
                    }
                }
            break;
    }

}
void findPenyakit(ListDinUser * UserData){
    char penyakit[51];
    while(1){
        while (getchar() != '\n');
        printf(">>> Masukkan nama penyakit: ");
        fgets(penyakit, sizeof(penyakit), stdin);

        // Remove trailing newline
        penyakit[strcspn(penyakit, "\n")] = '\0';

        if (strlen(penyakit) > 50) {
            printf("Error: Penyakit melebihi 50 characters.\n");
        } else {
            break;  
        }
    }
    int count = 0;  

    for(int i = 0; i < UserData->nEff; i++){
        if(strcmp(UserData->buffer[i].riwayat_penyakit,penyakit)==0){
            count++;
        }
    }  

    int length = listLength(*UserData);    
    User *ptrs[100];
    for (int i = 0; i < length; i++){
        ptrs[i] = &UserData->buffer[i];
    }

    if(count == 0){
        printf("Tidak ada pasien dengan penyakit %s di rumah sakit!\n",penyakit);
    } else if(count == 1){
        tampilPenyakit(ptrs,3,3,length, penyakit);
    } else{
        int base = 0;
        int order = 0;
        sortBased(&base, &order);
        tampilPenyakit(ptrs,base,order,length, penyakit);
    }
}

void cariUser(ListDinUser * UserData){
    int base = 0;
    findBased(&base, 1);
    switch (base){
        case 1:
            findId(UserData, 1);
            break;
        case 2:
            findName(UserData,1);
            break;
    }
}

void cariPasien(ListDinUser * UserData){
    int base = 0;
    findBased(&base, 2);
    switch (base){
        case 1:
            findId(UserData, 2);
            break;
        case 2:
            findName(UserData,2);
            break;
        case 3:
            findPenyakit(UserData);
            break;
    }
}
void cariDokter(ListDinUser * UserData){
    int base = 0;
    findBased(&base, 3);
    switch (base){
        case 1:
            findId(UserData, 3);
            break;
        case 2:
            findName(UserData,3);
            break;

    }
}