#include <stdio.h>
#include <stdlib.h>

// Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node; //renomeando a estrutura para node.

void remove_no_inicio(node *raiz);//remove o primeiro nó da lista.
void insere_no_final(node *raiz, int info);//insere no final da lista.
void displayLL(node *p); //mostra a lista.

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));//alocando memória para a raiz.
    raiz->valor = NULL; 
    raiz->proximo = NULL;

    
    if (raiz)//se a raiz não for nula.
        displayLL(raiz);

    int zero = 0;
    printf("Inser indo novo item: %d\n", zero);
    insere_no_final(raiz, zero);
    if (raiz)
        displayLL(raiz);

    int um = 1;
    printf("Inserindo novo item: %d\n", um);
    insere_no_final(raiz, um);
    if (raiz)
        displayLL(raiz);

    int dois = 2;
    printf("Inserindo novo item: %d\n", dois);
    insere_no_final(raiz, dois);
    if (raiz)
        displayLL(raiz);

    printf("Removendo item: %d\n", zero);
    remove_no_inicio(raiz);
    if (raiz)
        displayLL(raiz);

    printf("Removendo item: %d\n", um);
    remove_no_inicio(raiz);
    if (raiz)
        displayLL(raiz);

    printf("Removendo item: %d\n", dois);
    remove_no_inicio(raiz);
    if (raiz)
        displayLL(raiz);

    free(raiz);//liberando a memória alocada para a raiz.

    return 0;
}

void displayLL(node *p)//Mostra a lista
{
    p = p->proximo;
    printf("Mostrando a fila:\n");
    if (p)
    {
        do
        {//insere sermpre no final da lista.
            printf(" %d", p->valor);
            p = p->proximo;
        } while (p);
        printf("\n\n");
    }
    else
        printf("Fila vazia.\n\n");
}


void insere_no_final(node *raiz, int info)
{
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));//alocando memória para o novo nó.
    novo->valor = info;
    novo->proximo = NULL;

    node *p = raiz;
     
    while (p->proximo)
    {
        p = p->proximo;
    }
    p->proximo = novo;
}

void remove_no_inicio(node *raiz){
    node *remocao = raiz->proximo;
    raiz->proximo = remocao->proximo;
    free(remocao);
}
