//inclusão de bibliotecas
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "biblioteca_dijkastra.h"
#define KEY 1235
//fim inclusão
int sem;
pthread_t tid1, tid2;//declaração dos threads
long conta=0;//declaração da variável conta compartilhada entre os threads
void * t1(){//declaração de uma função que pode retornar um ponteiro nulo, que recebe qualquer tipo de dados
	long i;//declaração variável i
	P(sem);
	for(i=0; i< 1000000; i++){
		conta +=5;
	}
	V(sem);
	printf("Fim t1\n");
}
void * t2(){
	long i;
	P(sem);
	for(i=0; i<1000000; i++){
		conta+=2;
	}
	V(sem);
	printf("Fim t2\n");
}
int main(){//função principal, inicia todas as chamadas do algoritmo
	sem = sem_create(KEY, 1);
	pthread_create(&tid1, NULL, t1, NULL);//cria e executa a thread
	pthread_create(&tid2, NULL, t2, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid1, NULL);//força o processo pai esperar o término do processo filho
	sem_delete(sem);
	printf("\n\nO Valor de conta e: %li\n",conta);
}






