#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int randomfunc() {

    int file = open("/dev/random",O_RDONLY);

    int rand = 0;
    int *pointer = &rand;
    read(file,pointer,sizeof(int));

    close(file);

    return rand;
}


int main() {

    printf("random integer: %d",randomfunc());

    return 0;
}