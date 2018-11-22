#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

static const uint16_t SRV_PORT = 13666;

pthread_mutex_t mutex;

void fillServAddr(const char *ip, struct sockaddr_in *servAddr);

void readIpAddress(char *ip);
void readName(char *myName);
void *reader(void *arg);

int main() {
    char ip[16];
    char myName[30];
    readIpAddress(ip);
    readName(myName);
    strcpy(&myName[strlen(myName)-1], ": ");

    struct sockaddr_in servAddr;
    fillServAddr(ip, &servAddr);

    char buf[512];
    int sd_write = socket(AF_INET, SOCK_STREAM, 0);
    if (sd_write < 0) {
        perror("socket() fail");
        exit(1);
    }

    int sd_read = socket(AF_INET, SOCK_STREAM, 0);
    if (sd_read < 0) {
        perror("socket() fail");
        exit(1);
    }

    if (connect(sd_write, (const struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        perror("connect() fail");
        close(sd_write);
        exit(1);
    }

    if (connect(sd_read, (const struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        perror("connect() fail");
        close(sd_write);
        exit(1);
    }


    pthread_t thid;
    int result = pthread_create(&thid, (pthread_attr_t *) NULL, reader, &sd_read);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }

    char del = 127;

    while (1) {
        bzero(buf, sizeof(buf));
        strcpy(buf, myName);
        fgets(&buf[strlen(buf)], 450, stdin);
        //printf("%s\n", buf);
        //pthread_mutex_lock(&mutex);
        if (write(sd_write, buf, (strlen(buf)+1)*sizeof(char)) < 0) {
            perror("write() fail");
            close(sd_write);
            exit(1);
        }
    }
    close(sd_write);
    return 0;
}

void readIpAddress(char *ip) {
    bzero(ip, 16);
    printf("Enter ip address:\n");
    fgets(ip, 15, stdin);
}

void fillServAddr(const char *ip, struct sockaddr_in *servAddr) {
    bzero(servAddr, sizeof(*servAddr));
    (*servAddr).sin_family = AF_INET;
    (*servAddr).sin_addr.s_addr = inet_addr(ip);
    (*servAddr).sin_port = htons(SRV_PORT);
}

void readName(char *myName){
    bzero(myName, sizeof(&myName));
    printf("Enter your name: \n");
    fgets(myName, 29, stdin);
}

void *reader(void *arg){
    int sd = *(int *) arg;
    char buf[512];
    ssize_t test;
    while (1) {
        bzero(buf, sizeof(buf));
        test = read(sd, buf, sizeof(buf) - 1);
        if (test < 0)
            exit(1);
        printf("%s", buf);
    }

    }
