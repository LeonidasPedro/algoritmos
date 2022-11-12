/*Faça um programa que leia uma pilha S1 transfira os elementos da pilha S1 para a pilha S2
de modo que os elementos de S2 estejam na mesma ordem que em S1. Dica: Use uma pilha
adicional para auxiliar.*/

#include <iostream>
#include <string>

using namespace std;

struct Pilha{
    int numero;
    Pilha *proximo;
};

typedef Pilha pilha;

void inserirPilha(pilha *raiz, int numero);
void listarPilhas(pilha *raiz, pilha *raiz2);
void transferirElementos(pilha *raiz, pilha *raiz2);

int main(void){
        pilha *raiz = NULL;
        raiz = (pilha *)malloc(sizeof(pilha*));
        raiz->numero = 9999999;
        raiz->proximo = NULL;
    
        pilha *raiz2 = NULL;
        raiz2 = (pilha *)malloc(sizeof(pilha*));
        raiz2->numero = 9999999;
        raiz2->proximo = NULL;

        pilha *raiz3 = NULL;
        raiz3 = (pilha *)malloc(sizeof(pilha*));
        raiz3->numero = 9999999;
        raiz3->proximo = NULL;
    
        cout << "Digite 5 números" << endl;
        int numero = 0;
        for (int i = 0; i < 5; i++){
            cin >> numero;
            inserirPilha(raiz, numero);
        }
        transferirElementos(raiz, raiz2);
        transferirElementos(raiz2, raiz3);
        listarPilhas(raiz, raiz2);
        free(raiz);
}
void inserirPilha(pilha *raiz, int numero){
    pilha *insercao = NULL;
    insercao = (pilha *)malloc(sizeof(pilha*));
    insercao->numero = numero;
    insercao->proximo = raiz->proximo;
    raiz->proximo = insercao;
}

void listarPilhas(pilha *raiz, pilha *raiz3){
    pilha *p = raiz->proximo;
    int contador = 0;
    while (p->proximo){
        cout << "Pilha 1 posição " << contador << ": " << p->numero << endl;
        p = p->proximo;
        contador++;
    }
    pilha *p2 = raiz3->proximo;
    int contador2 = 0;
    while (p2->proximo){
        cout << "Pilha 2 posição " << contador2 << ": " << p2->numero << endl;
        p2 = p2->proximo;
        contador2++;
    }

}
void transferirElementos(pilha *raiz, pilha *raiz2){

    
}
