// PROGRAMA p02.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 50000

int number_characters;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; // mutex p/a sec.critica

void *thrfunc(void *arg)
{
    fprintf(stderr, "Starting thread %s\n", (char*)arg);
    while(number_characters > 0){
        pthread_mutex_lock(&mut);
        write(STDERR, (char*)arg, 1);
        number_characters--;
        pthread_mutex_unlock(&mut);
    }
    return NULL;
}

int main()
{
    number_characters = 50000;

    pthread_t ta, tb;

    pthread_create(&ta, NULL, thrfunc, "a");
    pthread_create(&tb, NULL, thrfunc, "b");
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    printf("\n");
    return 0;
}