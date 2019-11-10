#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int randomfunc() {

    int file = open("/dev/random",O_RDONLY);

    int random;
    read(file,&random,sizeof(int));

    close(file);

    return random;
}


int main() {

    int arr1[10];
    int arr2[10];

    printf("Generating random numbers:\n");

    int i;
    for (i = 0; i < 10; i++) {

        int random = randomfunc();
        printf("random %d: %d\n",i,random);
        arr1[i] = random;
    }

    printf("\nWriting numbers to file...\n");

    int file = open("randomnumbers.txt",O_CREAT|O_EXCL|O_RDWR,777);

    write(file, arr1, 10 * sizeof(int));

    printf("\nReading numbers to file...\n");

    read(file, arr2, 10 * sizeof(int));

    printf("\nVerification that written values were the same:\n");

    for (i = 0; i < 10; i++) {

        printf("random %d: %d\n",i,arr2[i]);
    }

    close(file);

    return 0;
}