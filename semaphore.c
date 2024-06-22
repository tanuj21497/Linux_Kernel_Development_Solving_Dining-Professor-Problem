#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
sem_t fork1;
sem_t fork2;
sem_t fork3;
sem_t fork4;
sem_t fork5;
void *choose1(void *arg){
    while(1){
    sem_wait(&fork1);
    sem_wait(&fork2);
    printf("eating 1\n");
    sem_post(&fork1);
    sem_post(&fork2);
    printf("done eating 1\n");
    }


}

void *choose2(void *arg){

    while(1){

    sem_wait(&fork2);
    sem_wait(&fork3);
    printf("eating 2\n");
    sem_post(&fork2);
    sem_post(&fork3);
    printf("done eating 2\n");
    }

}
void *choose3(void *arg){
    while(1){
    sem_wait(&fork3);
    sem_wait(&fork4);
    printf("eating 3\n");
    sem_post(&fork3);
    sem_post(&fork4);
    printf("done eating 3\n");
    }

}
void *choose4(void *arg){
    while(1){
    sem_wait(&fork4);
    sem_wait(&fork5);
    printf("eating 4\n");
    sem_post(&fork4);
    sem_post(&fork5);
    printf("done eating 4\n");
    }

}
void *choose5(void *arg){
    while(1){
    sem_wait(&fork1);
    sem_wait(&fork5);
    printf("eating 5\n");
    sem_post(&fork5);
    sem_post(&fork1);
    printf("done eating 5\n");
    }

}

int main(){
    sem_init(&fork1, 0, 1);
    sem_init(&fork2, 0, 1);
    sem_init(&fork3, 0, 1);
    sem_init(&fork4, 0, 1);
    sem_init(&fork5, 0, 1);

    pthread_t p1, p2, p3, p4, p5;
    pthread_create(&p1, NULL, &choose1, NULL);
    pthread_create(&p2, NULL, &choose2, NULL);
    pthread_create(&p3, NULL, &choose3, NULL);
    pthread_create(&p4, NULL, &choose4, NULL);
    pthread_create(&p5, NULL, &choose5, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    pthread_join(p5, NULL);
    sem_destroy(&fork1);
    sem_destroy(&fork2);
    sem_destroy(&fork3);
    sem_destroy(&fork4);
    sem_destroy(&fork5);



    return 0;
}