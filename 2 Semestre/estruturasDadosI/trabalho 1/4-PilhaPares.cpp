#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Pilha{
    int numero;
    Pilha *proximo;
};

typedef Pilha pilha;

void inserirPilha(pilha *raiz, int numero);
void listarPilha(pilha *raiz);
void removerElemento(pilha *raiz);

int main(void){

    pilha *raiz = NULL;
    raiz = (pilha *)malloc(sizeof(pilha*));
    raiz->numero = 9999999;
    raiz->proximo = NULL;

    cout << "Digite 15 números" << endl;
    int numero = 0;
    for (int i = 0; i < 15; i++){
        cin >> numero;
        if (numero % 2 == 0){
            inserirPilha(raiz, numero);
        } else {
            removerElemento(raiz);
        }
    }
    listarPilha(raiz);
    free(raiz);
}

void inserirPilha(pilha *raiz, int numero){
    pilha *insercao = NULL;
    insercao = (pilha *)malloc(sizeof(pilha*));
    insercao->numero = numero;
    insercao->proximo = raiz->proximo;
    raiz->proximo = insercao;
}

void listarPilha(pilha *raiz){
    pilha *p = raiz->proximo;
    int contador = 0;
    while (p->proximo){
        cout << "Pilha posição " << contador + 1 << ": " << p->numero << endl;
        p = p->proximo;
        contador++;
    }
}

void removerElemento(pilha *raiz){
    pilha *remocao = NULL;
    if (raiz->proximo){
        remocao = raiz->proximo;
        raiz->proximo = remocao->proximo;
        free(remocao);    
    }
}
