#include <bits/stdc++.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define KEY 1235

using namespace std;

int trava;
int x=0;

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
    P(trava);
        x+=2;
    V(trava);
        i++;
    }
    return NULL;
}
void * f_thread1(void * arg){
    int i =0;
    P(trava);
    while(i<1000000){
        x+=3;
    V(trava);
        i++;    
    }
    return NULL;
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

int main(){
    void * ret;
    trava = sem_create(KEY, 1);
    pthread_t thread, thread1;
    funcaoprocedural();
    funcaoprocedural1();
    pthread_create(&thread, NULL, f_thread, NULL);
    pthread_create(&thread1, NULL, f_thread, NULL);
    pthread_join(thread,&ret);
    pthread_join(thread1, &ret);
    printf("\n%d\n", x);
    sem_delete(trava);
    return 0;
}