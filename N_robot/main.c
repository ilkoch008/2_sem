#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a = 0;
int N; // legs
int napr;
int Ns; // steps
pthread_mutex_t mutex;

void * mythread(void *my_i) {
    pthread_t mythid;
    mythid = pthread_self();

    int i = 0;

    while(1){

        if(a == *((int*)my_i)) {
            pthread_mutex_lock(&mutex);
            if(*(int*)my_i == 0)
                napr = 1;
            if(Ns == 0)
                break;
            if(*(int*)my_i == N) {
                napr = -1;
                Ns--;
            }
            for (i = 0; i < *(int *) my_i; i+=1) {
                printf(" ");
            }
            printf("O\n");
            a+=1;
            pthread_mutex_unlock(&mutex);
            sleep(10 * (*(unsigned *)my_i));
        }
    }
    printf("Thread %ld, Calculation result = %d\n", mythid, a);
    return NULL;
}


int main()
{


    scanf("%d%d", &N, &Ns);
    pthread_t thid[N];
    pthread_mutex_init(&mutex, NULL);
    int result;
    int * iii = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        iii[i] = i;
        result = pthread_create(&thid[i], (pthread_attr_t *) NULL, mythread, &iii[i]);
        if(result != 0){
            fprintf (stderr, "Error on thread create, return value = %d\n", result);
            exit(-1);
        }
    }

    //printf("Thread created, thid = %ld\n", thid);
//    mythid = pthread_self();
//    for (int i = 0; i < 100000; ++i) {
//        a = a+1;
//        pthread_detach(pthread_self());
//    }
    pthread_detach(pthread_self());
    //printf("Thread %ld, Calculation result = %d\n", mythid, a);
    for(int i = 0; i < N; i++) {
        pthread_join(thid[i], (void **) NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}