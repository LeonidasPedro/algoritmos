
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Node {
    int valor;
    struct Node *proximo;
};

typedef Node node;

void inserirNumerosOrdenados(node *raiz, int valor);
void removerElemento(node *raiz, int valor);
void listarLista(node *raiz);

int main(void){

    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node*));
    raiz->valor = 0;
    raiz->proximo = NULL;

    int numero = 0;
    inserirNumerosOrdenados(raiz, 5);
    inserirNumerosOrdenados(raiz, 8);
    inserirNumerosOrdenados(raiz, 20);
    inserirNumerosOrdenados(raiz, 30);

    cout << "Digite 5 números inteiros para adicionar na lista.\n";
    for (int i = 0; i < 5; i++){
        cin >> numero;
        inserirNumerosOrdenados(raiz, numero);
    }
    listarLista
(raiz);
    free(raiz);

    return 0;
    
}

void inserirNumerosOrdenados(node *raiz, int valor){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = valor;
    novo->proximo = NULL;

    node *atual = raiz;

    while(atual->proximo){
        if (atual->valor < valor && atual->proximo->valor > valor) {
            novo->proximo = atual->proximo;
            atual->proximo = novo;
            return;
        }
        atual = atual->proximo;
    }
    atual->proximo = novo;
}


void removerElemento(node *raiz, int valor){
    node *p = raiz;
    while (p->proximo){
        if (p->proximo->valor == valor){
            node *aux = p->proximo;
            p->proximo = p->proximo->proximo;
            free(aux);
            return;
        }
        p = p->proximo;
    }
}

void listarLista(node *raiz){
   node *p = raiz->proximo;
    while (p){
         cout << p->valor << " ";
         p = p->proximo;
    }
    cout << endl;
}

