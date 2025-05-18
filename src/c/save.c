#include "../header/save.h"

int isValidFolderName(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        return 0; // Invalid: empty name
    }
    if (strlen(name) > 255) {
        return 0; // Invalid: name too long
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '/') {
            return 0; // Invalid: may not contain '/'
        }
    }

    return 1; // Valid 
}

int folderExists(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISDIR(st.st_mode));
}

void save(ListDinUser * UserData, ListObat * listObat, ListPenyakit * listPenyakit, Config * rumahsakit){
    char folderName[256];
    int valid = 0;

    while(!valid){
        printf("Masukkan nama folder: ");
        fgets(folderName, sizeof(folderName), stdin);
        // Remove newline
        folderName[strcspn(folderName, "\n")] = '\0';
        
        if(isValidFolderName(folderName)){
            valid = 1;
        } else{
            printf("Maaf! Nama folder tidak valid di Linux!\n");
        }
    }
    char folderPath[300];
    snprintf(folderPath, sizeof(folderPath), "../data/%s", folderName);

    if (!folderExists(folderPath)) {
        mkdir(folderPath);
    }

    writeListUser(folderPath, UserData);
    writeListObat(folderPath, listObat);
    writeListPenyakit(folderPath, listPenyakit);
    //writeListObatPenyakit();
    //writeConfig();
    printf("Data berhasil disimpan di %s\n", folderPath);

    
}