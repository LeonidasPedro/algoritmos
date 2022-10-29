#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node;

void imprimeFila(node *raiz);
void insereNoInicio(node *raiz, int info);
void insereNoMeio(node *raiz, int info, int posicao);
void insereNoFinal(node *raiz, int info);
void removeNoInicio(node *raiz);
void removeNoMeio(node *raiz, int posicao);
void removeNoFinal(node *raiz);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;


    printf("Mostrando a lista\n");
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 1 no início\n");
    insereNoInicio(raiz, 1);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 0 no início\n");
    insereNoInicio(raiz, 0);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 2 no final\n");
    insereNoFinal(raiz, 2);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 5 no final\n");
    insereNoFinal(raiz, 5);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 3 na posicao 3\n");
    insereNoMeio(raiz, 3, 3);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 4 na posicao 4\n");
    insereNoMeio(raiz, 4, 4);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove primeiro node\n");
    removeNoInicio(raiz);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove primeiro node\n");
    removeNoInicio(raiz);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove ultimo node\n");
    removeNoFinal(raiz);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove segundo node da lista\n");
    removeNoMeio(raiz, 1);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

  free(raiz);


  return 0;
}

void insereNoInicio(node *raiz, int info){
  Node *insercao = NULL;
  insercao = (node *)malloc(sizeof(node *));
  insercao->valor = info;
  insercao->proximo = raiz->proximo;
  raiz->proximo = insercao;

}