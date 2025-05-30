#include "../header/input.h"
#include "../header/F01.h"
#include "../header/F02.h"
#include "../header/F03.h"
#include "../header/F04.h"
#include "../header/F05.h"
#include "../header/F06.h"
#include "../header/F07.h"
#include "../header/F08.h"
#include "../header/F09.h"
#include "../header/F10.h"
#include "../header/F11.h"
#include "../header/F12.h"
#include "../header/F13.h"
#include "../header/F14.h"
#include "../header/F15.h"
#include "../header/F16.h"
#include "../header/F17.h"
#include "../header/F18.h"
#include "../header/user.h"
#include "../header/config.h"
#include "../header/Boolean.h"
#include "../header/penyakit.h"

void input(int * loginState, int * loginId, ListDinUser * userData, ListObat * listObat, ListPenyakit * listPenyakit, MapObatPenyakit * mapObatPenyakit, int * run, Config * rumahsakit){
    char user_input[100];
    switch (*loginState){
        case 0:
            printf(COLOR_WHITE);
            break;
        case 1:
            printf(COLOR_MAGENTA);
            break;
        case 2:
            printf(COLOR_CYAN);
            break;
        case 3:
            printf(COLOR_YELLOW);
            break;
    }
    printf("\n>>> ");
    scanf("%99s", user_input);
    printf(COLOR_RESET);
    if(strcmp(user_input,"LOGOUT") == 0){
        logout(loginState, loginId);
        return;
    } else if(strcmp(user_input,"HELP") == 0){
        help(*loginState, *loginId, *userData);
        return;
    } else if(strcmp(user_input,"SAVE") == 0){
        while (getchar() != '\n');
        save(userData, listObat, listPenyakit, mapObatPenyakit, rumahsakit);
        return;
    } else if(strcmp(user_input,"EXIT") == 0){
        exitProgram(run, userData, listObat, listPenyakit, mapObatPenyakit, rumahsakit);
        return;
    }
    else if(*loginState != 0){
        if(strcmp(user_input,"LIHAT_DENAH") == 0){
            lihatDenah(*rumahsakit);
            return;
        }
        else if(strcmp(user_input,"LIHAT_RUANGAN") == 0){
            lihatRuangan(*rumahsakit, *userData);
            return;
        }
    }
    if(*loginState == 0){
        if(strcmp(user_input,"LOGIN") == 0){
            login(loginState, loginId, *userData);
        }
        else if(strcmp(user_input,"REGISTER") == 0){
            registerPasien(userData);
        }
        else if(strcmp(user_input,"LUPA_PASSWORD") == 0){
            lupaPassword(userData);
        }
        else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
        }
    }
    else if(*loginState == 1){
        if(strcmp(user_input,"TAMBAH_DOKTER") == 0){
            tambahDokter(userData);
        }
        else if(strcmp(user_input,"ASSIGN_DOKTER") == 0){
            assignDokter(userData,rumahsakit);
        }
        else if(strcmp(user_input,"LIHAT_USER") == 0){
            lihatUser(*userData);
        }
        else if(strcmp(user_input,"LIHAT_PASIEN") == 0){
            lihatPasien(*userData);
        }
        else if(strcmp(user_input,"LIHAT_DOKTER") == 0){
            lihatDokter(*userData);
        }
        else if(strcmp(user_input,"CARI_USER") == 0){
            cariUser(userData);
        }
        else if(strcmp(user_input,"CARI_PASIEN") == 0){
            cariPasien(userData);
        }
        else if(strcmp(user_input,"CARI_DOKTER") == 0){
            cariDokter(userData);
        }
        else if(strcmp(user_input,"LIHAT_SEMUA_ANTRIAN") == 0){
            lihatAntrian(*rumahsakit, *userData);
        }
        else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
        }
    
    }
    else if(*loginState == 2){
        if(strcmp(user_input,"DIAGNOSIS") == 0){
            diagnosis(*listPenyakit, *rumahsakit, userData, *loginId);
        }
        else if(strcmp(user_input,"NGOBATIN") == 0){
            ngobatin(*loginId, rumahsakit, *userData, *listObat, *listPenyakit, *mapObatPenyakit);
        } 
        else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
        }
    }
    else if(*loginState == 3){
        if(strcmp(user_input, "MINUM_OBAT") == 0){
            minumObat(loginId, loginState, rumahsakit, userData, *listObat, *listPenyakit, *mapObatPenyakit);
        }
        else if(strcmp(user_input, "MINUM_PENAWAR") == 0){
            minumPenawar(*loginId, rumahsakit, *userData, *listObat, *listPenyakit, *mapObatPenyakit);
        }
        else if(strcmp(user_input, "DAFTAR_CHECKUP") == 0){
            daftarCheckUp(userData, rumahsakit, *loginId);
        }
        else if(strcmp(user_input, "ANTRIAN") == 0){
            antrianSaya(userData, rumahsakit, *loginId);
        }
        else if(strcmp(user_input, "PULANGDOK") == 0){
            pulangDok(*loginId, rumahsakit, userData, *listObat, *listPenyakit, *mapObatPenyakit);
        }
        else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
        }
    }
    else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
    }


}