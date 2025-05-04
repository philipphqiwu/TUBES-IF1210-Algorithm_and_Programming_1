#include "../header/input.h"
#include "../header/listdinuser.h"
#include "../header/F01.h"
#include "../header/F02.h"
#include "../header/F03.h"
#include "../header/F04.h"

void input(int * loginState, int * loginId, ListDinUser * UserData){
    char user_input[100];
    printf(">>> ");
    scanf("%s", user_input);
    if(*loginState == 0){
        if(strcmp(user_input,"LOGIN") == 0){
            login(loginState, loginId, *UserData);
        } else if(strcmp(user_input,"REGISTER") == 0){
            registerPasien(UserData);
        } else if(strcmp(user_input,"LUPA_PASSWORD") == 0){
            lupaPassword(UserData);
        }
    }
    if(strcmp(user_input,"LOGOUT") == 0){
        logout(loginState, loginId);
    }

}