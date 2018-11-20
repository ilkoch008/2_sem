#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

static const uint16_t SRV_PORT = 80;
static const int BUF_SIZE = 10000;

void fillServAddr(const struct in_addr *ip, struct sockaddr_in *servAddr);

struct hostent* getHost();

int main() {
    struct sockaddr_in servAddr;
    struct hostent* hp = getHost();
    fillServAddr((const struct in_addr *) hp->h_addr, &servAddr);

    char buf[BUF_SIZE];
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket() fail");
        exit(1);
    }

    if (connect(sd, (const struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        perror("connect() fail");
        close(sd);
        exit(1);
    }

    bzero(buf, BUF_SIZE);
    printf("Enter HTTP query\n");
    fgets(buf, 255, stdin);

    if (write(sd, buf, strlen(buf)) < 0) {
        perror("write() fail");
        close(sd);
        exit(1);
    }

    bzero(buf, BUF_SIZE);
    if (read(sd, buf, sizeof(buf)) < 0) {
        perror("read() fail");
    }
    printf("%s\n", buf);

    close(sd);
    return 0;
}

struct hostent* getHost() {
    printf("Enter host to connect to:\n");
    char hostname[256];
    fgets(hostname, 256, stdin);
    strtok(hostname, "\n");
    struct hostent* hp = gethostbyname(hostname);
    if (hp == NULL) {
        perror("getHostByName failed");
        exit(1);
    }
    return hp;
}

void fillServAddr(const struct in_addr *ip, struct sockaddr_in *servAddr) {
    bzero(servAddr, sizeof(*servAddr));
    (*servAddr).sin_family = AF_INET;
    (*servAddr).sin_addr = *ip;
    (*servAddr).sin_port = htons(SRV_PORT);
}

/*
GET / HTTP/1.1\r\nHost: yahoo.com\r\n\r\n
 */