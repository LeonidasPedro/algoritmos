#include <stdio.h>
#define NUMEROPROCESSOS 5
#define NUMERORECURSOS 3
//esta função adiciona ou subtrai um vetor B no vetor A
void adicionavetor(int *A, int *B, int sgn){//se sgn 1 adiciona se -1 subtrai
	int i;
	for(i=0;i<NUMERORECURSOS;i++)
		A[i]=A[i]+(sgn*B[i]);
}
//esta funcao determina se A é menor que B
BOOL verificaAMenorB(int *A, int *B){
	int i, j;
	j=1;
	for(i=0;j&&(i<NUMERORECURSOS);i++)
		if(A[i]>B[i])
			j=0;
	return j;
}
//esta funcao imprime o NUMEROPROCESSOSxNUMERORECURSOS
void imprimeMatrix(int **A){
	int i, j;
	for(i=0;i<NUMEROPROCESSOS; i++){
		printf("P%d ",i);
		for(j=0;j<NUMERORECURSOS;j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}
//esta funcao determina se um empréstimo é seguro
BOOL verificaEmprestimo(int * Termina, int * Disponivel, int * Tarefa, int** Emprestimo, int** Necessidade){
	int i,j;
	//procura i que termina[i] =0 e Necessidade[i]<tarefa
	for(j=0;j<NUMERORECURSOS;j++)
		printf("processo %d ", Tarefa[j]);
		printf(" (Tarefa)\n");
		i=0;
		j=1;
		while((i<NUMEROPROCESSOS) && Termina[i] || (!verificaAMenorB(Necessidade[i],Tarefa))){
			j = j && Termina[i];
			i++;
		}
		if(i==NUMEROPROCESSOS)
			return j;
		//simula emprestimo e devolucao de recursos
		printf("Processo %d pode terminar\n\n<",i);
		Termina[i]=1;
		adicionavetor(Tarefa, Emprestimo[i],1);
		return verificaEmprestimo(Termina, Disponivel, Tarefa, Emprestimo, Necessidade);
}
//determina se um pedido pode ser verificado por verificaEmprestimo
BOOL grant(int pid, int * Pedido, int * Disponivel, int** Emprestimo, int** Necessidade){
	int i;
	int Termina[NUMEROPROCESSOS];
	int Tarefa[NUMERORECURSOS];
	for(i=0;i<NUMEROPROCESSOS;i++)
		Termina[i]=0;
	if(!verificaAMenorB(Pedido, Necessidade[pid])) return 0;
	if(!verificaAMenorB(Pedido, Disponivel)) return 0;
	//simula emprestimo
	adicionavetor(Disponivel, Pedido, -1);
	adicionavetor(Emprestimo[pid],Pedido,1);
	adicionavetor(Necessidade[pid],Pedido, -1);
	for(i=0;i<NUMERORECURSOS;i++)
		Tarefa[i]=Disponivel[i];
	printf("Emprestimo:\n");
	impremeMatrix(Emprestimo);
	printf("Necesside:\n");
	impremeMatrix(Necessidade);
	return verificaEmprestimo(Termina, Disponivel, Tarefa, Emprestimo, Necessidade);
}
int main(){
	int i,j;
	int Dispon[NUMERORECURSOS];//Disponivel
	int Pedid[NUMERORECURSOS];//Pedido
	int Tarefa[NUMERORECURSOS];
	int Termina[NUMERORECURSOS];
	int ** Empr;//matriz 2D
	int ** Necess;//matriz 2D
	Empr = (int **) malloc(sizeof(int *)*NUMEROPROCESSOS);
	for(i=0;i<NUMEROPROCESSOS;i++)
		Empr[i]=(int *) malloc(sizeof(int)*NUMERORECURSOS);
	Necess = (int **) malloc(sizeof(int *)*NUMEROPROCESSOS);
	for(i=0;i<NUMEROPROCESSOS;i++)
		Necess[i]=(int *) malloc(sizeof(int)*NUMERORECURSOS);
	Empr[0][0]=0; Empr[0][1]=1; Empr[0][2]=0;
	Empr[1][0]=2; Empr[1][1]=0; Empr[1][2]=0;
	Empr[2][0]=3; Empr[2][1]=0; Empr[2][2]=2;
	Empr[3][0]=2; Empr[3][1]=1; Empr[3][2]=1;
	Empr[4][0]=0; Empr[4][1]=0; Empr[4][2]=2;
	Necess[0][0]=7;Necess[0][1]=4;Necess[0][2]=3;
	Necess[1][0]=1;Necess[1][1]=2;Necess[1][2]=2;
	Necess[2][0]=6;Necess[2][1]=0;Necess[2][2]=0;
	Necess[3][0]=0;Necess[3][1]=1;Necess[3][2]=1;
	Necess[4][0]=4;Necess[4][1]=3;Necess[4][2]=1;
	Dispon[0]=3; Dispon[1]=3; Dispon[2]=2;
	for(i=0;i<NUMERORECURSOS;i++)
		Tarefa[i] = Dispon[i];
	for(i=0;i<NUMEROPROCESSOS;i++)
		Termina[i]=0;
	if(verificaEmprestimo(Termina, Dispon, Tarefa, Empr, Necess))
		printf("Pode-se emprestar\n");
	else
		printf("Nao eh seguro emprestar\n");
	//simula pedido de emprestimo de 1,0,2 pelo processo P1
	Pedid[0]=1; Pedid[1]=0; Pedid[2]=2;
	if(grant(1,Pedid, Dispon, Empr, Necess))
		printf("P1 Pode ");
	else
		printf("P1 nao pode ");
	printf("pedir emprestado 1,0,2\n");
	//simula pedido de emprestimo 0,2,0 pelo processo P0
	Pedid[0]=0; Pedid[1]=2; Pedid[2]=0;
	if(grant(0,Pedid, Dispon, Empr, Necess))
		printf("P0 Pode ");
	else
		printf("P0 nao pode ");
	printf("pedir emprestado 0,2,0\n");
	for(i=0;i<NUMEROPROCESSOS;i++){
		free(Empr[i];
		free(Necess[i]);
	}
	free(Empr);
	free(Necess);
	return 0;
}