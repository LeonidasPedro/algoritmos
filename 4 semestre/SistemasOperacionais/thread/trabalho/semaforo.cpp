#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaforo;

using namespace std;
int x=0;
void funcaoprocedural(){
    int i =0;
    while(i<10){
        i++;
        
    }
}
void funcaoprocedural1(){
    int i =0;
    while(i<10){
        i++;
    }
}
void * f_thread(void * arg){
    int i =0;
    while(i<1000000){
    sem_wait(&semaforo);
        x+=2;
    sem_post(&semaforo);
        i++;
    }
    return NULL;
}
void * f_thread1(void * arg){
    int i =0;
    while(i<1000000){
    sem_wait(&semaforo);
        x+=3;
    sem_post(&semaforo);
        i++;
    }
    return NULL;
}
int main(){
    void * ret;
    sem_init(&semaforo, 0, 1);
    pthread_t thread, thread1;
    funcaoprocedural();
    funcaoprocedural1();
    pthread_create(&thread, NULL, f_thread, NULL);
    pthread_create(&thread1, NULL, f_thread, NULL);
    pthread_join(thread,&ret);
    pthread_join(thread1, &ret);
    printf("\n%d\n", x);
    return 0;
}