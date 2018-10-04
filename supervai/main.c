#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int n_proc, result;
    scanf("%d", &n_proc);
    for(int i = 0; i < n_proc; i++){
        result = fork();
        if (result < 0){
            printf("fork ERROR\n");
            exit(-1);
        }
        if(result == 0) {
            srand((unsigned int)time(NULL));
            printf("I have appeared!!!; my id: %d\n", getpid());
            sleep((unsigned int)rand()%5);
            srand((unsigned int)time(NULL));
            int x = rand();
            exit(x/1000%10);
        }
    }
    int kak_tam;
    while (1) {
        wait(&kak_tam);
        //printf("%d\n", WEXITSTATUS(kak_tam));
        result = fork();
        if (result < 0) {
            printf("fork ERROR\n");
            exit(-1);
        }
        if (result == 0) {
            printf("I have appeared; my id: %d\n", getpid());
            int x;
            srand((unsigned int)time(NULL));
            x = rand();
            //printf("%d\n", x);
            sleep((unsigned int)x%5);
            srand((unsigned int)time(NULL));
            x = rand();
            exit(x%2);
        }
    }
    return 0;
}