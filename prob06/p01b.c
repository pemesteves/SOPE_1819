// PROGRAMA p01b.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

void *thrfunc(void *arg)
{
    int i;
    int* arg1 = (int*)arg;
    
    fprintf(stderr, "Starting thread %d\n", *arg1);
    for (i = 1; i <= NUMITER; i++)
        printf("%d", *arg1);
    return NULL;
}

int main()
{
    pthread_t ta, tb;
    int i = 1, j = 2;

    pthread_create(&ta, NULL, thrfunc, &i);
    pthread_create(&tb, NULL, thrfunc, &j);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}