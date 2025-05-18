#include "../header/F07.h"

void sortBased(int * base, int * order){ 
// Validation for sorting base
    while (1) {
        printf("Urutkan berdasarkan?\n");
        printf("1. ID\n");
        printf("2. Nama\n");
        printf(">>> Pilihan : ");
        if (scanf("%d", base) != 1 || (*base != 1 && *base != 2)) {
            printf("Input tidak valid! Pilih 1 atau 2.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;  
        }
    }

    // Validation for sorting order
    while (1) {
        printf("\nUrutan sort?\n");
        printf("1. ASC (A-Z)\n");
        printf("2. DES (Z-A)\n");
        printf(">>> Pilihan : ");
        if (scanf("%d", order) != 1 || (*order != 1 && *order != 2)) {
            printf("Input tidak valid! Pilih 1 atau 2.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;  
        }
    }
}

// Sort array secara alphabetical
void alphabetSort(User *ptrs[], int length){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (strcmp(ptrs[j]->username,ptrs[j + 1]->username) > 0){
                User* temp =  ptrs[j];
                ptrs[j] = ptrs[j+1];
                ptrs[j+1] = temp;
            }
        }
    }
}

void tampilList(User *ptrs[], int type, int base, int order, int length){
    printf("Menampilkan semua ");
    switch(type){
        case 1:
            printf("pengguna ");
            break;
        case 2:
            printf("pasien ");
            break;
        case 3:
            printf("dokter ");
                break;
    }
    printf("dengan ");
    switch(base){
        case 1:
            printf("ID ");
            break;
        case 2:
            alphabetSort(ptrs, length);
            printf("nama ");
            break;
    }                
    printf("terurut ");
    switch(order){
        case 1:
            printf("ascending...\n");
            switch (type){
                case 1:
                    printf("ID | Nama                | Role    | Penyakit\n");
                    printf("----------------------------------------------------------\n");
                    for(int i = 0; i < length; i++){
                        printf("%-3d| %-20s| %-8s| %-20s\n", ptrs[i]->id, ptrs[i]->username, ptrs[i]->role, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
                    }
                    break;
                case 2:
                    printf("ID | Nama                | Penyakit\n");
                    printf("----------------------------------------------------------\n");
                    for(int i = 0; i < length; i++){
                        if(strcmp(ptrs[i]->role,"pasien") == 0){
                            printf("%-3d| %-20s| %-20s\n", ptrs[i]->id, ptrs[i]->username, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
                        }
                    }
                    break;
                case 3:
                    printf("ID | Nama\n");
                    printf("----------------------------------------------------------\n");
                    for(int i = 0; i < length; i++){
                        if(strcmp(ptrs[i]->role,"dokter") == 0){
                            printf("%-3d| %-20s\n", ptrs[i]->id, ptrs[i]->username);
                        }
                    }
                    break;
            }
            break;
            
        case 2:
            printf("descending...\n");
            switch (type){
                case 1:
                    printf("ID | Nama                | Role    | Penyakit\n");
                    printf("----------------------------------------------------------\n");
                    for(int i = length-1; i >= 0; i--){
                        printf("%-3d| %-20s| %-8s| %-20s\n", ptrs[i]->id, ptrs[i]->username, ptrs[i]->role, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
                    }
                    break;
                case 2:
                    printf("ID | Nama                | Penyakit\n");
                    printf("----------------------------------------------------------\n");
                    for(int i = length-1; i >= 0; i--){
                        if(strcmp(ptrs[i]->role,"pasien") == 0){
                            printf("%-3d| %-20s| %-20s\n", ptrs[i]->id, ptrs[i]->username, strlen(ptrs[i]->riwayat_penyakit) == 0 ? "-" : ptrs[i]->riwayat_penyakit);
                        }
                    }
                    break;
                case 3:
                    printf("ID | Nama\n");
                    printf("----------------------------------------------------------\n");
                    for(int i = length-1; i >= 0; i--){
                        if(strcmp(ptrs[i]->role,"dokter") == 0){
                            printf("%-3d| %-20s\n", ptrs[i]->id, ptrs[i]->username);
                        }
                    }
                    break;
            }
            break;
    }

       
}

void lihatUser(ListDinUser UserData){
    int base;
    int order;
    sortBased(&base, &order);
    int length = listLength(UserData);    
    User *ptrs[100];
    for (int i = 0; i < length; i++){
        ptrs[i] = &UserData.buffer[i];
    }
    tampilList(ptrs, 1, base, order, length);
}

void lihatPasien(ListDinUser UserData){
    int base;
    int order;
    sortBased(&base, &order);
    int length = listLength(UserData);    
    User *ptrs[100];
    for (int i = 0; i < length; i++){
        ptrs[i] = &UserData.buffer[i];
    }
    tampilList(ptrs, 2, base, order, length);
}

void lihatDokter(ListDinUser UserData){
    int base;
    int order;
    sortBased(&base, &order);
    int length = listLength(UserData);    
    User *ptrs[100];
    for (int i = 0; i < length; i++){
        ptrs[i] = &UserData.buffer[i];
    }
    tampilList(ptrs, 3, base, order, length);
}