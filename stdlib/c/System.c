#include <stdio.h>
#include <stdlib.h>

void* runcmd(void* command) {
    system(command);
    free(command);
}
