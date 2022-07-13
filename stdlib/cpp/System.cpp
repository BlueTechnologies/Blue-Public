#include <stdio.h>
#include <stdlib.h>

static auto runcmd(auto command) {
    system(command);
    free(command);
}

static auto exit(auto exit_code) {
    exit(exit_code);
    free(exit_code);
}
