#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/user.h"
#include "header/obat.h"
#include "header/penyakit.h"
#include "header/obat_penyakit.h"
#include "header/input.h"
#include "header/F01.h"
#include "header/F02.h"
#include "header/F03.h"
#include "header/F04.h"

int main() {
    int loginState = 0;
    /*
    loginState
    0 : not logged in
    1 : logged in as manager
    2 : logged in as doctor
    3 : logged in as patient
    */
    while(1){
        input(&loginState);
    }
    
    return 0;
}