#include "../header/F07.h"

void sortBased(int * base, int * order){ 
    printf("Urutkan berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf(">>> Pilihan : ");
    scanf("%d",base);

    printf("\nUrutan sort?\n");
    printf("1. ASC (A-Z)\n");
    printf("2. DES (Z-A)\n");
    printf(">>> Pilihan : ");
    scanf("%d",order);
    printf("\n");
}

void lihatUser(ListDinUser UserData){
    int base;
    int order;
    sortBased(&base, &order);

    switch (base){
        case 1:
            switch(order){
                case 1:
                    printf("Menampilkan semua pengguna dengan ID terurut ascending...\n");
                    printf("ID | Nama     | Role     | Penyakit\n");
                    printf("-------------------------------------\n");
                    for(int i = 0; i <= getLastIdx(UserData); i++){
                        printf("%d  | %s  | %s  | %s\n",UserData.buffer[i].id,UserData.buffer[i].username, UserData.buffer[i].role,UserData.buffer[i].riwayat_penyakit);
                    }
                    break;
                case 2:
                    printf("Menampilkan semua pengguna dengan ID terurut descending...\n");
                    printf("ID | Nama     | Role     | Penyakit\n");
                    printf("-------------------------------------\n");
                    for(int i = getLastIdx(UserData); i >= 0; i--){
                        printf("%d  | %s  | %s  | %s\n",UserData.buffer[i].id,UserData.buffer[i].username, UserData.buffer[i].role,UserData.buffer[i].riwayat_penyakit);
                    }

                    break;
            }
            break;
        case 2:
            int length = listLength(UserData);
            User *ptrs[100];
            for (int i = 0; i < length; i++){
                ptrs[i] = &UserData.buffer[i];
            }
            switch(order){
                case 1:
                    for (int i = 0; i < length - 1; i++) {
                        for (int j = 0; j < length - i - 1; j++) {
                            if (strcmp(ptrs[j]->username,ptrs[j + 1]->username) > 0){
                                User* temp =  ptrs[j];
                                ptrs[j] = ptrs[j+1];
                                ptrs[j+1] = temp;
                            }
                        }
                    }

                    printf("Menampilkan semua pengguna dengan Username terurut ascending...\n");
                    printf("ID | Nama     | Role     | Penyakit\n");
                    printf("-------------------------------------\n");
                    for(int i = 0; i <= getLastIdx(UserData); i++){
                        printf("%d  | %s  | %s  | %s\n",ptrs[i]->id,ptrs[i]->username, ptrs[i]->role,ptrs[i]->riwayat_penyakit);
                    }
                    break;
                case 2:
                    for (int i = 0; i < length - 1; i++) {
                        for (int j = 0; j < length - i - 1; j++) {
                            if (strcmp(ptrs[j]->username,ptrs[j + 1]->username) < 0){
                                User* temp =  ptrs[j];
                                ptrs[j] = ptrs[j+1];
                                ptrs[j+1] = temp;
                            }
                        }
                    }
                    
                    printf("Menampilkan semua pengguna dengan Username terurut descending...\n");
                    printf("ID | Nama     | Role     | Penyakit\n");
                    printf("-------------------------------------\n");
                    for(int i = 0; i <= getLastIdx(UserData); i++){
                        printf("%d  | %s  | %s  | %s\n",ptrs[i]->id,ptrs[i]->username, ptrs[i]->role,ptrs[i]->riwayat_penyakit);
                    }

                    break;
            }
            break;
    }

}