#include "../header/to-lower.h"
// Fungsi untuk mengimitasi fungsi tolower dari header <ctype.h>
char * to_lower(char * s){
    for(int i = 0; i < strlen(s); i++){
        if((int)s[i] >= 65 && (int)s[i] <= 90){
            s[i] += 32;
        }
    }
    return s;
}