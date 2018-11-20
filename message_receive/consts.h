//
// Created by ilya on 30.10.18.
//

#ifndef MESSAGE_SEND_CONSTS_H
#define MESSAGE_SEND_CONSTS_H

#define LAST_MESSAGE 255
#define  MAX_TEXT_LEN 255
#define FILE_NAME "consts.h"

struct mymgbuf {
    long mtype;
    char mtext[MAX_TEXT_LEN];
} mybuff;

#endif //MESSAGE_SEND_CONSTS_H
