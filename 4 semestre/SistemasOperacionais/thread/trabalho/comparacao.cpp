#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h> 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>

#define KEY 1235
#define THREADS 40 

long compartilhada = 0;
sem_t semaforo; 
pthread_mutex_t mutex;
int trava;

void P(int semid){
	struct sembuf sempar[1];
	sempar[0].sem_num=0;
	sempar[0].sem_op=-1;
	sempar[0].sem_flg=SEM_UNDO;
	if(semop(semid, sempar, 1)==-1) printf("Erro P()\n");
}
void V(int semid){
	struct sembuf sempar[1];
	sempar[0].sem_num=0;
	sempar[0].sem_op=1;
	sempar[0].sem_flg=SEM_UNDO;
	if(semop(semid, sempar, 1)==-1) printf("Erro V()\n");
}

int sem_create(key_t key, int initval){
	int semid;
	union semun{
		int val;
		struct semid_ds *buf;
		ushort array[1];
	}arg_ctl;
	semid = semget(ftok("dijkastra.h", key),1,IPC_CREAT|IPC_EXCL|0666);
	if(semid==-1){
		semid=semget(ftok("dijkastra.h", key),1,0666);
		if(semid==-1){
			printf("Erro semget()\n");
			exit(1);
		}
	}
	arg_ctl.val = initval;
	if(semctl(semid,0,SETVAL,arg_ctl)==-1){
		printf("Erro semctl()\n");
		exit(1);
	}
	return(semid);
}
void sem_delete(int semid){
	if(semctl(semid,0,IPC_RMID,0)==-1) printf("Erro IPC_RMID\n");
}

void *threadSemaforo(void *arg)
{
	int a, b;
    for (long j = 0; j < 100000; j++) {	
        sem_wait(&semaforo);
		
		a = compartilhada;
		b = 1; 
        compartilhada = a + b;

		sem_post(&semaforo); 
    }

    return NULL;
}


void *threadMutex(void *arg)
{
    int a, b;
    for (long j = 0; j < 100000; j++) {	
        pthread_mutex_lock(&mutex);
        
        a = compartilhada;
        b = 1; 
        compartilhada = a + b;

        pthread_mutex_unlock(&mutex); 
    }


    return NULL;
}

void *treadDijkastra(void *arg)
{
    int a, b;
    for (long j = 0; j < 100000; j++) {	
        P(trava);
        
        a = compartilhada;
        b = 1; 
        compartilhada = a + b;

        V(trava); 
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t[THREADS];
    int s;

	sem_init(&semaforo, 0, 1);
    pthread_mutex_init(&mutex, NULL);
    trava = sem_create(KEY, 1); 
    clock_t t1, t2;


    printf("Valor inicial: %ld\n", compartilhada);
    printf("Iniciando a função semaforo... \n");
    t1 = clock();
    for (int i = 0; i < THREADS; ++i) {
        s = pthread_create(&t[i], NULL, threadSemaforo, NULL);//criando
    }
        for (int i = 0; i < THREADS; ++i) {
        s = pthread_join(t[i], NULL);//esperando elas terminares
    }
    t2 = clock();
    printf("Valor final: %ld\n", compartilhada);
    compartilhada = 0;

    printf("Tempo de execução da Semaforo: %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    printf("Iniciando a função mutex... \n");
    t1 = clock();
    for (int i = 0; i < THREADS; ++i) {
        s = pthread_create(&t[i], NULL, threadMutex, NULL);//criando
    }
        for (int i = 0; i < THREADS; ++i) {
        s = pthread_join(t[i], NULL);//esperando elas terminares
    }
    t2 = clock();
    printf("Valor final: %ld\n", compartilhada);
    compartilhada = 0;
    printf("Tempo de execução da Mutex: %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    
    printf("Iniciando a função Dijkastra... \n");
    t1 = clock();
    for (int i = 0; i < THREADS; ++i) {
        s = pthread_create(&t[i], NULL, treadDijkastra, NULL);//criando
    }
        for (int i = 0; i < THREADS; ++i) {
        s = pthread_join(t[i], NULL);//esperando elas terminares
    }
    t2 = clock();
    printf("Valor final: %ld\n", compartilhada);
    printf("Tempo de execução da Dijkastra: %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    
    sem_delete(0);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaforo);
    
    return 0;
}
