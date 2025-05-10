#include "../header/input.h"
#include "../header/F01.h"
#include "../header/F02.h"
#include "../header/F03.h"
#include "../header/F04.h"
#include "../header/F07.h"
#include "../header/F08.h"
#include "../header/F10.h"

void input(int * loginState, int * loginId, ListDinUser * UserData, int * run){
    char user_input[100];
    printf(">>> ");
    scanf("%99s", user_input);
    if(strcmp(user_input,"LOGOUT") == 0){
        logout(loginState, loginId);
    } else if(*loginState == 0){
        if(strcmp(user_input,"LOGIN") == 0){
            login(loginState, loginId, *UserData);
        } else if(strcmp(user_input,"REGISTER") == 0){
            registerPasien(UserData);
        } else if(strcmp(user_input,"LUPA_PASSWORD") == 0){
            lupaPassword(UserData);
        } else{
            printf("PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n");
        }
    } else if(*loginState == 1){
        if(strcmp(user_input,"TAMBAH_DOKTER") == 0){
            tambahDokter(UserData);
        } else if(strcmp(user_input,"LIHAT_USER") == 0){
            lihatUser(*UserData);
        } else{
            printf("PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n");
        }
    } else{
            printf("PLEASE ENTER A VALID COMMAND!\n");
            printf("TYPE \"HELP\" TO SHOW VALID COMMANDS!\n");
        }


}