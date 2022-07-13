#include <stdlib.h>
#include <stdio.h>

static auto read(auto filen) {
    float n = 0;
    auto openedfile = fopen(filen, "r");

    if (openedfile != NULL) {
        auto filecont = fgetc(openedfile);
        return filecont;
        fclose(openedfile);
    }
    return 0;
}

static auto write(auto filen, auto newcont) {
    auto num = 0;
    auto openedfile = fopen(filen, "w");

    if (openedfile != NULL) {
        fputs(newcont, openedfile);
        fclose(openedfile);
    }
    fclose(openedfile);
}
