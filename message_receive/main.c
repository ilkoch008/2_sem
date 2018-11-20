#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include "consts.h"


int main() {
    key_t key;
    if((key = ftok("/home/ilya/progi/message_key.txt", 0)) < 0){
        printf("Can't generate key\n");
        exit(-1);
    }

    int msqid;
    if((msqid = msgget(key, 0666 | IPC_CREAT)) < 0){
        printf("Can't get meqid\n");
        exit(-1);
    }
    ssize_t len;
    if((len = msgrcv(msqid, &mybuff, MAX_TEXT_LEN, 0, 0)) < 0){
        printf("Can't receive message");
        exit(-1);
    }

    printf("type = %ld\tdata: %s\n", mybuff.mtype, mybuff.mtext);

    return 0;
}