#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
sem_t fork1;
sem_t fork2;
sem_t fork3;
sem_t fork4;
sem_t fork5;

int number =5;


int checkifright(int side){
    if(side==1){
       
        return 1;
    }
    return 0;
}
int giveforktoright(int p){
    number--;
    return 1;
}
int giveforktoleft(int p){
    number--;
    return 1;
}

void wait(){
    while(1){
        if(number>1){
            number--;
            break;
        }

    }

}
void wait_zero(){
    while(1){
        if(number>0){
            number--;
            break;
        }
    }
}



void request(int p, int side){
    if(number>1){
        int w = checkifright(side);
        if(w==1){
            giveforktoright(p);

        }
        else{
            giveforktoleft(p);

        }

    }
    else if(number==1){
        int j = checkifright(side);
        if(j!=1){
            wait();
        }
        else{
            giveforktoright(p);
        }

    }
    else if(number==0){
        wait_zero();

    }

}


void *choose1(void *arg){
    // while(1){
    // sem_wait(&fork1);
    // sem_wait(&fork2);
    request(0, 1);
    request(1, 1);
    printf("eating 1\n");
    // sem_post(&fork1);
    // sem_post(&fork2);
    number++;
    number++;
    printf("done eating 1\n");
    // }
    pthread_exit(NULL);


}


void *choose2(void *arg){

    // while(1){

    // sem_wait(&fork2);
    // sem_wait(&fork3);
    request(0, 2);
    request(1, 2);
    printf("eating 2\n");
    // sem_post(&fork2);
    // sem_post(&fork3);
    number++;
    number++;
    printf("done eating 2\n");
    // }
pthread_exit(NULL);
}
void *choose3(void *arg){
    // while(1){
    // sem_wait(&fork3);
    // sem_wait(&fork4);
    request(0, 3);
    request(1, 3);
    printf("eating 3\n");
    // sem_post(&fork3);
    // sem_post(&fork4);
    number++;
    number++;
    printf("done eating 3\n");
    // }
pthread_exit(NULL);
}
void *choose4(void *arg){
    // while(1){
    // sem_wait(&fork4);
    // sem_wait(&fork5);
    request(0, 4);
    request(1, 4);
    printf("eating 4\n");
    // sem_post(&fork4);
    // sem_post(&fork5);
    number++;
    number++;
    printf("done eating 4\n");
    // }
pthread_exit(NULL);
}
void *choose5(void *arg){
    // while(1){
    // sem_wait(&fork1);
    // sem_wait(&fork5);
    request(0, 5);
    request(1, 5);
    printf("eating 5\n");
    // sem_post(&fork5);
    // sem_post(&fork1);
    number++;
    number++;
    printf("done eating 5\n");
    // }
    pthread_exit(NULL);

}

int main(){
    // sem_init(&fork1, 0, 1);
    // sem_init(&fork2, 0, 1);
    // sem_init(&fork3, 0, 1);
    // sem_init(&fork4, 0, 1);
    // sem_init(&fork5, 0, 1);

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

    
    // sem_destroy(&fork1);
    // sem_destroy(&fork2);
    // sem_destroy(&fork3);
    // sem_destroy(&fork4);
    // sem_destroy(&fork5);



    return 0;
}