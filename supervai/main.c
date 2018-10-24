#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int message = 0;
    int n_proc, result;
    scanf("%d", &n_proc);
    int i;
    int fd[n_proc][2];
    int fd_iden[n_proc][1]; // number of fd for every pid
    for (i = 0; i < n_proc; i++) {
        pipe(fd[i]);
        result = fork();
        if (result < 0) {
            printf("fork ERROR\n");
            exit(-1);
        }
        if (result == 0) {
            srand((unsigned int) time(NULL));
            printf("I have appeared!!!; my id: %d, my message: %d\n", getpid(), i);
            sleep((unsigned int) rand() % 5);
            write(fd[i][1], &i, sizeof(int));
            close(fd[i][1]);
            srand((unsigned int) time(NULL));
            int x = rand() % 2;
            exit(x);
        }
        fd_iden[i][0] = result;
    }
    int kak_tam;
    int pid_end;
    int mess;
    int j;
    while (1) {
        kak_tam = 99999;
        pid_end = wait(&kak_tam); // pid of ended process
        if (kak_tam == 99999)
            break;
        for (j = 0; j < n_proc; j++) {
            if (fd_iden[j][0] == pid_end) // find needed fd
                break;
        }
        read(fd[j][0], &mess, sizeof(int));
        close(fd[j][0]);
        //printf("WEXITSTATUS: %d\n", WEXITSTATUS(kak_tam));
        if (WEXITSTATUS(kak_tam) != 0) {
            pipe(fd[j]);
            result = fork();
            if (result < 0) {
                printf("fork ERROR\n");
                exit(-1);
            }
            if (result == 0) {
                printf("I have appeared; my id: %d, my message: %d\n", getpid(), mess);
                int x;
                srand((unsigned int) time(NULL));
                x = rand();
                //printf("%d\n", x);
                sleep((unsigned int) x % 5);
                write(fd[j][1], &mess, sizeof(int));
                close(fd[j][1]);
                srand((unsigned int) time(NULL));
                x = rand();
                exit(x % 2);
            }
            fd_iden[j][0] = result;
        } else {
            pipe(fd[j]);
            i++;
            result = fork();
            if (result < 0) {
                printf("fork ERROR\n");
                exit(-1);
            }
            if (result == 0) {
                printf("I have appeared; my id: %d, my message: %d\n", getpid(), i);
                int x;
                srand((unsigned int) time(NULL));
                x = rand();
                //printf("%d\n", x);
                sleep((unsigned int) x % 5);
                write(fd[j][1], &i, sizeof(int));
                close(fd[j][1]);
                srand((unsigned int) time(NULL));
                x = rand();
                exit(x % 2);
            }
            fd_iden[j][0] = result;
        }
    }
    return 0;
}