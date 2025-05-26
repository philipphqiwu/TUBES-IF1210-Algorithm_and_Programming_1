#include "../header/to-lower.h"
// Fungsi untuk mengimitasi fungsi tolower dari header <ctype.h>
char * to_lower(const char * s){
    char *copy = malloc(strlen(s) + 1);
    if (!copy) return NULL;

    for (int i = 0; i <= strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            copy[i] = s[i] + 32;
        else
            copy[i] = s[i];
    }

    return copy;
}