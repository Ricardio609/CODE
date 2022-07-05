#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int val = 0;

void* Routine(void* avgs) {
    while (1) {
        printf("I'm %s .... val: %d\n", (char*)avgs, val);
        sleep(1);
    }
}

int main() {
    pthread_t tid1, tid2, tid3;
    int ret1 = pthread_create(&tid1, NULL, Routine, (void*)"pthread 1");
    if (ret1 != 0) {
        fprintf(stderr, "pthread_create: %s\n", strerror(ret1));
        exit(1);
    }
    int ret2 = pthread_create(&tid1, NULL, Routine, (void*)"pthread 1");
    if (ret2 != 0) {
        fprintf(stderr, "pthread_create: %s\n", strerror(ret2));
        exit(1);
    }int ret3 = pthread_create(&tid1, NULL, Routine, (void*)"pthread 1");
    if (ret3 != 0) {
        fprintf(stderr, "pthread_create: %s\n", strerror(ret3));
        exit(1);
    }
    while (1) {
        printf("I'm main pthread ... val: %d\n", val++);
        sleep(1);
    }
    return 0;
}