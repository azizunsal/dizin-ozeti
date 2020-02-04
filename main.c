#include <stdio.h>
#include <dirent.h>

#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void) {
    struct dirent *de;
    int txtDosyaSayisi = 0;

    DIR *dr = opendir("./deneme");

    if (dr == NULL) {
        printf("dosya dizini bulunamadi...\n");
        return 0;
    }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[(strlen(de->d_name) - 3)] == 't' && de->d_name[(strlen(de->d_name) - 2)] == 'x' &&
            de->d_name[(strlen(de->d_name) - 1)] == 't')
            txtDosyaSayisi++;
        printf("%s\n", de->d_name);
    }
    printf("Toplam %d tane 'txt' dosyasi bulunmaktadir.\n", txtDosyaSayisi);
    closedir(dr);
    return 0;
}