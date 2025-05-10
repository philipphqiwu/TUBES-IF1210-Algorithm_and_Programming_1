#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/user.h"
#include "header/obat.h"
#include "header/penyakit.h"
#include "header/obat-penyakit.h"
#include "header/input.h"
#include "header/listdinuser.h"
#include "header/parse-user.h"
#include "header/F01.h"
#include "header/F02.h"
#include "header/F03.h"
#include "header/F04.h"
#include "header/initialize-program.h"

int main() {
    int loginState = 0;
    /*
    loginState
    0 : not logged in
    1 : logged in as manager
    2 : logged in as doctor
    3 : logged in as patient
    */
    int loginId = -1; // logged in dengan id berapa
    ListDinUser listUser;
    CreateListDinUser(&listUser, 100);
    ListObat listObat;
    createListObat(&listObat, 100);
    ListPenyakit listPenyakit;
    createListPenyakit(&listPenyakit, 100);

    initializeProgram(&listUser, &listObat, &listPenyakit);

    // parseUserData(&listUser); // Membaca Data Awal dari ../data/user.csv
    printf("Jumlah user: %d\n", listUser.nEff);
    printList(listUser);

    while(1){
        input(&loginState, &loginId, &listUser);
        printf("id: %d login: %d\n",loginId,loginState);
        printList(listUser);
    }
    
    return 0;
}