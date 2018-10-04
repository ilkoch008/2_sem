#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(){

    int fd1[2], fd2[2], result;
    ssize_t size;
    char resstring[6];

    if(pipe(fd1) < 0){
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    if(pipe(fd2) < 0){
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    result = fork();
    if(result <0){
        printf("Can\'t fork child\n");
        exit(-1);
    } else if (result > 0) {
        //close(fd[0]);
        size = write(fd1[1], "Ping\n", 6);
        if(size != 6){
            printf("Can\'t write all string\n");
            exit(-1);
        }
        printf("Ping\n");
        //wait(result);
        size = read(fd2[0], resstring, 6);
        if(size < 0){
            printf("Can\'t read string\n");
            exit(-1);
        }
        printf("Pong\n");
        if (strcmp(resstring, "Ping\n") == 0){
            size = write(fd1[1], "Pong\n", 6);
            //printf("%s\n",resstring);
        }
        if(size < 0){
            printf("Can\'t read string\n");
            exit(-1);
        }
        close(fd1[0]);
        close(fd1[1]);
        sleep(1);
        printf("Parent exit\n");
    } else {
        //close(fd[1]);
        size = read(fd1[0], resstring, 6);
        if(size < 0){
            printf("Can\'t read string\n");
            exit(-1);
        }
        if (strcmp(resstring, "Ping\n") == 0){
            size = write(fd2[1], "Ping\n", 6);
            printf("%s",resstring);
        }
        if(size != 6){
            printf("Can\'t write all string\n");
            exit(-1);
        }
        size = read(fd1[0], resstring, 6);
        if(size < 0){
            printf("Can\'t read string\n");
            exit(-1);
        }
        if (strcmp(resstring, "Pong\n") == 0){
            size = write(fd2[1], "Pong\n", 6);
            printf("%s",resstring);
        }
        if(size != 6){
            printf("Can\'t write all string\n");
            exit(-1);
        }
        //printf("%s\n",resstring);
        close(fd2[0]);
        close(fd2[1]);
    }
    close(fd2[0]);
    close(fd2[1]);
    return 0;
}