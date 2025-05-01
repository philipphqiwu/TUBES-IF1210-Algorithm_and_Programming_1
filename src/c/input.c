#include "../header/input.h"
#include "../header/F01.h"
#include "../header/F02.h"
#include "../header/F03.h"
#include "../header/F04.h"

void input(int * loginState){
    char user_input[100];
    printf(">>> ");
    scanf("%s", user_input);
    if(*loginState == 0){
        if(strcmp(user_input,"LOGIN") == 0){
            login();
        } else if(strcmp(user_input,"REGISTER") == 0){
            registerPasien();
        } else if(strcmp(user_input,"LOGOUT") == 0){
            logout();
        } else if(strcmp(user_input,"LUPA_PASSWORD") == 0){
            lupaPassword();
        } 
    } else{
        printf("Tolong Login Dulu! \n");
    } 

}