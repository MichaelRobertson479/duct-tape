#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int random() {

    int file = open("/dev/random",O_RDONLY);

    int random;
    read("/dev/random",random,sizeof(int));

    close("/dev/random");

    return random;
}


int main() {

    printf("random integer: %d",random());

    return 0;
}