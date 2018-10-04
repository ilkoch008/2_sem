#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    ssize_t size;
    if(pipe(fd) < -0){
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    size =2;
    long int x = 0;
    while (size == 2){
        printf("1\n");
        size = write(fd[1], "pi", 2);
        printf("2\n");
        x+= 2 * sizeof(char);
        printf("3\n");
        printf("%ld\n", x);
        printf("4\n");
    }
    printf("%ld\n", x);
    return 0;
}