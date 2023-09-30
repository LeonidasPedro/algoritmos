#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Node {
    int valor;
    struct Node *proximo;
};

typedef Node node;

void inserir(node *raiz, int valor);
void retirar(node *raiz, int valor);
void listar(node *raiz);


typedef struct Node node;


int main() {
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = 0;
    raiz->proximo = NULL;

    inserePadrao(raiz);
    imprimePilha(raiz);
    
    int i = 0, num = 0;
    cout << "Digite 5 números inteiros para adicionar na lista.\n";
    for(;i<5;i++){
        scanf("%d", &num);
        insereOrdenado(raiz, num);
    }
    
    imprimePilha(raiz);
    free(raiz);
    return 0;
}

void imprimePilha(node *raiz) {
    raiz = raiz->proximo;
    printf("Mostrando a lista:\n");
    if (raiz)
    {
        do {
            printf("%d ", raiz->valor);
            raiz = raiz->proximo;
        } while (raiz);
        printf("\n\n");
    }
    else
        printf("pilha vazia.\n\n");
}

void insereOrdenado(node *raiz, int info) {
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = info;
    novo->proximo = NULL;

    node *atual = raiz;
    if (!(atual->proximo)){
        cout << "Não tem\n";
        atual->proximo = novo;
    }else{
        while(atual->proximo){
            if (atual->valor == info){
                return;
            }
            if (atual->valor < info && atual->proximo->valor > info) {
                novo->proximo = atual->proximo;
                atual->proximo = novo;
                return;
            }
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void removeElemento(node *raiz) {
    node *primeiro = raiz->proximo;
    raiz->proximo = primeiro->proximo;
    free(primeiro);
}

void inserePadrao(node *raiz){
    insereOrdenado(raiz, 5);
    insereOrdenado(raiz, 8);
    insereOrdenado(raiz, 20);
    insereOrdenado(raiz, 30);
}