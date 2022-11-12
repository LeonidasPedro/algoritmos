#include <iostream>
#include <string>

using namespace std;

struct Pilha{
    int numero;
    Pilha *proximo;
};

typedef Pilha pilha;

void adicionarPilha(pilha *raiz, int numero);
void listarPilha(pilha *raiz);
void removerDoMeio(pilha *raiz, int numero);

int main(void){

    pilha *raiz = NULL;
    raiz = (pilha *)malloc(sizeof(pilha*));
    raiz->numero = 0;
    raiz->proximo = NULL;

    int opcao = 5;
    int numero = 0;
    
    while (opcao != 0){
        cout << "\n\n Escolha uma opcao" << endl; 
        cout << "1 - Adicionar um número a pilha" << endl;
        cout << "2 - Listar todos os números da pilha" << endl;
        cout << "3 - Remover um número da pilha" << endl;
        cout << "0 - Sair\n" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                cout << "Digite o número que deseja adicionar a pilha:" << endl;
                cin >> numero;
                adicionarPilha(raiz, numero);
                break;
            case 2:
                listarPilha(raiz);
                break;
            case 3:
                cout << "Digite o número que deseja remover da pilha:" << endl;
                cin >> numero;
                removerDoMeio(raiz, numero);
                break;
        }
    }
    free(raiz);
};

void adicionarPilha(pilha *raiz, int numero){
    pilha *novo = NULL;
    novo = (pilha *)malloc(sizeof(pilha*));
    novo->numero = numero;
    novo->proximo = NULL;

    pilha *p = raiz;
    
    while(p->proximo != NULL){
        p = p->proximo;
    }
    p->proximo = novo;
};

void listarPilha(pilha *raiz){
    if(raiz->proximo){
        pilha *p = raiz->proximo;
        int contador = 0;
        while (p->proximo){
            cout << "Pilha posição " << contador + 1 << ": " << p->numero << endl;
            p = p->proximo;
            contador++;
        }
    } else {
        cout << "A pilha está vazia" << endl;
    }
};

void removerDoMeio(pilha *raiz, int numero){
    pilha *p = raiz;
    pilha *aux = NULL;
    aux = (pilha *)malloc(sizeof(pilha*));
    aux->numero = 0;
    aux->proximo = NULL;

    while(p->proximo != NULL){
        if(p->proximo->numero == numero){
            aux->proximo = p->proximo->proximo;
            p->proximo = aux->proximo;
        }
        p = p->proximo;
    }
};

