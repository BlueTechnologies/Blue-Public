#include <stdlib.h>
#include <stdio.h>

void* read(void* filen) {
    void* num;
    void* openedfile = fopen(filen, "r");

    if (openedfile != NULL) {
        void* filecont = fscanf(openedfile, num);
        return filecont;
        fclose(openedfile);
        free(filen);
        free(num);
        free(openedfile);
        free(filecont);
    }
    fclose(openedfile);
    free(filen);
    free(num);
    free(openedfile);
    return NULL;
}

void* write(void* filen, void* newcont) {
    void* num;
    void* openedfile = fopen(filen, "w");

    if (openedfile != NULL) {
        fprintf(openedfile, newcont, num);
        fclose(openedfile);
        free(filen);
        free(num);
        free(openedfile);
        free(newcont);
    }
    fclose(openedfile);
    free(filen);
    free(num);
    free(openedfile);
    free(newcont);
}
