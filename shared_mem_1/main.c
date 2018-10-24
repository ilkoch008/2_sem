#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *array; /* Óêàçàòåëü íà ðàçäåëÿåìóþ ïàìÿòü */
    int shmid; /* IPC äåñêðèïòîð äëÿ îáëàñòè ðàçäåëÿåìîé ïàìÿòè */
    //int new = 1; /* Ôëàã íåîáõîäèìîñòè èíèöèàëèçàöèè ýëåìåíòîâ ìàññèâà */
    char pathname[] = "myfile_1"; /* Èìÿ ôàéëà, èñïîëüçóþùååñÿ äëÿ ãåíåðàöèè êëþ÷à. Ôàéë ñ òàêèì èìåíåì äîëæåí ñóùåñòâîâàòü â òåêóùåé äèðåêòîðèè */
    key_t key; /* IPC êëþ÷ */
    if ((key = ftok(pathname, 0)) < 0) {
        printf("Can\'t generate key\n");
        exit(-1);
    }
    if ((shmid = shmget(key, 10 * sizeof(char), 0666 | IPC_CREAT | IPC_EXCL)) < 0) {
        if (errno != EEXIST) {
            printf("Can\'t create shared memory\n");
            exit(-1);
        } else {
            if ((shmid = shmget(key, 10 * sizeof(char), 0)) < 0) {
                printf("Can\'t find shared memory\n");
                exit(-1);
            }
            //new = 0;
        }
    }
    if ((array = (char *) shmat(shmid, NULL, 0)) == (char *) (-1)) {
        printf("Can't attach shared memory\n");
        exit(-1);
    }
    array[0] = 'a';
    array[1] = 'b';
    array[2] = 'c';
    array[3] = '\0';
    int kak_tam=0;
    int idd = 999, i = 0;
    while(i < 30) {
        printf("%s, MY ID: %d, IDD: %d, i: %d\n", array, getpid(), idd, i);
        i++;
        wait(&kak_tam);
        idd = fork();
        if (idd < 0) {
            printf("Can't fork\n");
            exit(1);
        } else if(idd == 0) {
            array[0]++;
            array[1]++;
            array[2]++;
            array[3] = '\0';
           // fprintf(stderr, "stderr, YA DOCHHH, %s\n", array);
            if (shmdt(array) < 0) {
                printf("Can't detach shared memory\n");
                exit(-1);
            }
            exit(0);
        }
    }
    return 0;
}
