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
#include "../header/F18.h"

void input(int * loginState, int * loginId, ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit, MapObatPenyakit * mapObatPenyakit, int * run, Config * rumahsakit){
    char user_input[100];
    printf(COLOR_GREEN">>> ");
    scanf("%99s", user_input);
    printf(COLOR_RESET);
    if(strcmp(user_input,"LOGOUT") == 0){
        logout(loginState, loginId);
        return;
    } else if(strcmp(user_input,"HELP") == 0){
        help(*loginState, *loginId, *UserData);
        return;
    } else if(strcmp(user_input,"SAVE") == 0){
        while (getchar() != '\n');
        save(UserData, listObat, listPenyakit, mapObatPenyakit, rumahsakit);
        return;
    } else if(strcmp(user_input,"EXIT") == 0){
        exitProgram(run, UserData, listObat, listPenyakit, mapObatPenyakit, rumahsakit);
        return;
    } else if(*loginState != 0){
        if(strcmp(user_input,"LIHAT_DENAH") == 0){
            lihatDenah(*rumahsakit);
            return;
        } else if(strcmp(user_input,"LIHAT_RUANGAN") == 0){
            lihatRuangan(*rumahsakit, *UserData);
            return;
        }
    } 
    if(*loginState == 0){
        if(strcmp(user_input,"LOGIN") == 0){
            login(loginState, loginId, *UserData);
        } else if(strcmp(user_input,"REGISTER") == 0){
            registerPasien(UserData);
        } else if(strcmp(user_input,"LUPA_PASSWORD") == 0){
            lupaPassword(UserData);
        } else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
        }
    } else if(*loginState == 1){
        if(strcmp(user_input,"TAMBAH_DOKTER") == 0){
            tambahDokter(UserData);
        } else if(strcmp(user_input,"ASSIGN_DOKTER") == 0){
            assignDokter(UserData,rumahsakit);
        } else if(strcmp(user_input,"LIHAT_USER") == 0){
            lihatUser(*UserData);
        } else if(strcmp(user_input,"LIHAT_PASIEN") == 0){
            lihatPasien(*UserData);
        } else if(strcmp(user_input,"LIHAT_DOKTER") == 0){
            lihatDokter(*UserData);
        } else if(strcmp(user_input,"CARI_USER") == 0){
            cariUser(UserData);
        } else if(strcmp(user_input,"CARI_PASIEN") == 0){
            cariPasien(UserData);
        } else if(strcmp(user_input,"CARI_DOKTER") == 0){
            cariDokter(UserData);
        } else if(strcmp(user_input,"LIHAT_SEMUA_ANTRIAN") == 0){
            lihatAntrian(*rumahsakit, *UserData);
        } else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
        }
    } else{
            printf(COLOR_RED"PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n"COLOR_RESET);
    }


}