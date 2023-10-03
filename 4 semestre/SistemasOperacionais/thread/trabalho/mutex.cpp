#include <bits/stdc++.h>
#include <pthread.h>

pthread_mutex_t trava;

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
    pthread_mutex_lock(&trava);
        x+=2;
    pthread_mutex_unlock(&trava);
        i++;
    }
    return NULL;
}
void * f_thread1(void * arg){
    int i =0;
    while(i<1000000){
    pthread_mutex_lock(&trava);
        x+=3;
    pthread_mutex_unlock(&trava);
        i++;
    
    }
    return NULL;
}
int main(){
    void * ret;
    
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