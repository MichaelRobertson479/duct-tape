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

    int *arr1;
    int *arr2;

    printf("Generating random numbers:\n");

    int i;
    for (i = 0; i < 10; i++) {

        int random = randomfunc();
        printf("random %d: %d\n",i,random);
        arr1 = random;
        arr1++;
    }

    printf("\nWriting numbers to file...\n");

    int file = open("randomnumbers",O_RDWR,111);

    if (file == -1) {
        printf("File creation failed\n");
        printf("%s\n",strerror(errno));
        return 0;
    }

    int write = write(file, arr1, 10 * sizeof(int));

    if (write == -1) {
        printf("Writing failed\n");
        printf("%s\n",strerror(errno));
        return 0;
    }

    printf("\nReading numbers to file...\n");

    int read = read(file, arr2, 10 * sizeof(int));

    if (read == -1) {
        printf("Reading failed\n");
        printf("%s\n",strerror(errno));
        return 0;
    }

    printf("\nVerification that written values were the same:\n");

    for (i = 0; i < 10; i++) {

        int random = randomfunc();
        printf("random %d: %d\n",i,arr2);
        arr2++;
    }

    close(file);

    return 0;
}