//Valerii, [11.10.18 11:30]
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int a = 0;
void *mythread(void *dummy) {
    pthread_t mythid;
    mythid = pthread_self();
    for (int i = 0; i < 100000; ++i) {
        a = a+1;
        pthread_detach(pthread_self());
    }
    printf("Thread %ld, Calculation result = %d\n", mythid, a);
    return NULL;
}
int main()
{
    pthread_t thid, mythid;
    int result;
    result = pthread_create( &thid, (pthread_attr_t *)NULL, mythread, NULL);
    if(result != 0){
        printf ("Error on thread create, return value = %d\n", result);
        exit(-1);
    }
    printf("Thread created, thid = %ld\n", thid);
    mythid = pthread_self();
    for (int i = 0; i < 100000; ++i) {
        a = a+1;
        pthread_detach(pthread_self());
    }
    pthread_detach(pthread_self());
    printf("Thread %ld, Calculation result = %d\n", mythid, a);
    pthread_join(thid, (void **)NULL);
    return 0;
}