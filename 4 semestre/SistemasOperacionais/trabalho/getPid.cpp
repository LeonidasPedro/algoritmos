#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Numero do processo %d. Processo Pai: %d Grupo (%d) \n", getpid(), getppid(), getpgrp());
	return 0;
}
