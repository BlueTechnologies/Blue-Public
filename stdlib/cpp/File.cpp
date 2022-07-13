#include <stdlib.h>
#include <stdio.h>

static auto read(auto filen) {
    auto num;
    auto openedfile = fopen(filen, "r");

    if (openedfile != NULL) {
        auto filecont = fscanf(openedfile, num);
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

static auto write(auto filen, auto newcont) {
    auto num;
    auto openedfile = fopen(filen, "w");

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
