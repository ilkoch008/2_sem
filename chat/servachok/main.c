#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static const int ACCEPT_QUEUE_SIZE = 10;

void fillAddress(struct sockaddr_in *addr, uint16_t port);

int openServerSocket(uint16_t port);

void doBind(int sd, struct sockaddr_in addr);

int serverSocket();

void doListen(int sd);

int doRead(char *buf, int cliSd);

int doAccept(int sd);

void *handleClient(void *arg_read);
void *write_to_Client(void *arg_write);

void *readingMessages();

int startThread(int *cliSd, pthread_t *thid);

int fd[101][2];
int processes = 0;

int main() {
    uint16_t port = 13666;
    int sd = openServerSocket(port);

    for (int i = 0; i < 101; ++i) {
        if(pipe(fd[i]) < 0){
            printf("error in pipe()");
        }
    }

    pthread_t mess;
    int result = pthread_create(&mess, (pthread_attr_t *) NULL, readingMessages, NULL);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }

    while (1) {
        int cliSd_read = doAccept(sd);
        pthread_t thid;
        startThread(&cliSd_read, &thid);
        int cliSd_write = doAccept(sd);
        pthread_t thid_write;
        int resultt = pthread_create(&thid_write, (pthread_attr_t *) NULL, write_to_Client, &cliSd_write);
        if (resultt != 0) {
            printf("Error on thread create, return value = %d\n", result);
            exit(1);
        }
    }
    close(sd);
    return 0;
}

int startThread(int *cliSd, pthread_t *thid) {
    int result = pthread_create(thid, (pthread_attr_t *) NULL, handleClient, cliSd);
    if (result != 0) {
        printf("Error on thread create, return value = %d\n", result);
        exit(1);
    }
}

void *write_to_Client(void *arg_write){
    int cliSd = *(int *) arg_write;
    sleep(1);
    int my_proc_num = processes;
    processes++;
    char buf[512];
    while(1) {
        if(read(fd[my_proc_num][0], buf, 511 * sizeof(char)) <= 0){
            printf("error in readingMessages");
            exit(1);
        };
        write(cliSd, buf, strlen(buf) * sizeof(char));
        bzero(buf, sizeof(buf));
    }
}

void *readingMessages(){
    char buf[512];
    //sleep(1);
    sched_yield();
    while(1){
        //sleep(1);
        if(read(fd[100][0], buf, 500 * sizeof(char))<=0){
            printf("error in readingMessages");
            exit(1);
        }
        printf("%s", buf);
        bzero(buf, sizeof(buf));
    }
}

void *handleClient(void *arg_read) {
    int cliSd = *(int *) arg_read;
    //int my_proc_num = processes;
    //processes++;
    char buf[512];
    char fin_buf[1024];
    bzero(buf, sizeof(buf));
    bzero(fin_buf, sizeof(fin_buf));
    while (1) {
        if (doRead(buf, cliSd)) {
            break;
        }
        for (int i = 0; i < processes; ++i) {
                write(fd[i][1], buf, strlen(buf) * sizeof(char));
        }
        write(fd[100][1], buf, strlen(buf) * sizeof(char));
        //strcat(fin_buf, buf);
//        read(fd[my_proc_num][0], buf, strlen(buf) * sizeof(char));
//        write(cliSd, buf, strlen(buf) * sizeof(char));
//        bzero(buf, sizeof(buf));
    }
    //printf("%s\n", fin_buf);
    return arg_read;
}

int doAccept(int sd) {
    struct sockaddr *cliAddr = NULL;
    int cliSd = accept(sd, cliAddr, NULL);
    if (cliSd < 0) {
        perror("accept() fail");
        exit(1);
    }
    return cliSd;
}

int doRead(char *buf, int cliSd) {
    for(int i = 0; i < sizeof(buf); i++){
        buf[i] = '\0';
    }
    if (read(cliSd, buf, sizeof(buf)) <= 0) {
        perror("read() fail");
        return -1;
    }
    return 0;
}

int openServerSocket(uint16_t port) {
    struct sockaddr_in addr;
    fillAddress(&addr, port);
    int sd = serverSocket();
    doBind(sd, addr);
    doListen(sd);
    return sd;
}

void doListen(int sd) {
    if (listen(sd, ACCEPT_QUEUE_SIZE)) {
        perror("listen() fail");
        exit(1);
    }
}

int serverSocket() {
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket() fail");
        exit(1);
    }
    return sd;
}

void doBind(int sd, struct sockaddr_in addr) {
    if (bind(sd, (const struct sockaddr *) &addr, sizeof(addr))) {
        perror("bind() fail");
        close(sd);
        exit(1);
    }
}

void fillAddress(struct sockaddr_in *addr, uint16_t port) {
    bzero(addr, sizeof(*addr));
    (*addr).sin_family = AF_INET;
    (*addr).sin_addr.s_addr = INADDR_ANY;
    (*addr).sin_port = htons(port);
}

