#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matriz[10][10];
    int numNos;
} Grafo;

void inicializarGrafo(Grafo *grafo, int numNos){
    int i, j;
    grafo->numNos = numNos;

    for (i = 0; i< numNos; i++){
        for(j = 0; j < numNos; j++){
            grafo->matriz[i][j] = rand() % 100;
        }
    }
}

void adicionarAresta(Grafo *grafo, int i, int j){
    if(i >= 0 && i < grafo->numNos && j >= 0 && j < grafo->numNos){
        grafo->matriz[i][j] = 1;
    }
}

void imprimirGrafo(Grafo *grafo){
    int i, j;
    for (i = 0; i < grafo->numNos; i++){
        printf("Ad. do nó %d: ", i);
        for(j = 0; j < grafo->numNos; j++){
            printf("%d -> ", j);
        }
        printf("Nulo\n");
    }
}

int main()
{
    int numNos = 5;
    Grafo grafo;

    inicializarGrafo(&grafo, numNos);

    adicionarAresta(&grafo, 0, 1);
    adicionarAresta(&grafo, 0, 4);
    adicionarAresta(&grafo, 1, 2);
    adicionarAresta(&grafo, 1, 3);
    adicionarAresta(&grafo, 1, 4);
    adicionarAresta(&grafo, 2, 3);
    adicionarAresta(&grafo, 3, 4);

    imprimirGrafo(&grafo);


    return 0;
}
