#include <iostream>
#include <string>

using namespace std;

struct Fila{

    int numero;
    Fila *proximo;
};

typedef Fila fila;

void adicionarFila(fila *raiz, int numero);
void listarFila(fila *raiz);
void removerRepetidos(fila *raiz);

int main(void){

    fila *raiz = NULL;
    raiz = (fila *)malloc(sizeof(fila*));
    raiz->numero = 0;
    raiz->proximo = NULL;

    int opcao = 5;
    int numero = 0;
    
    while (opcao != 0){
        cout << " Escolha uma opcao" << endl; 
        cout << "1 - Adicionar um número a fila" << endl;
        cout << "2 - Listar todos os números da fila" << endl;
        cout << "3 - Remover números repetidos da fila" << endl;
        cout << "0 - Sair\n" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                cout << "Digite o número que deseja adicionar a fila:" << endl;
                cin >> numero;
                adicionarFila(raiz, numero);
                break;
            case 2:
                listarFila(raiz);
                break;
            case 3:
                removerRepetidos(raiz);
                break;
        }
    }
    free(raiz);
};

void adicionarFila(fila *raiz, int numero){
    fila *novo = NULL;
    novo = (fila *)malloc(sizeof(fila*));
    novo->numero = numero;
    novo->proximo = NULL;

    fila *p = raiz;
    while (p->proximo){
        p = p->proximo;
    }
    p->proximo = novo;
}

void listarFila(fila *raiz){
    fila *p = raiz;
    while (p->proximo){
        p = p->proximo;
        cout << "Numeros da fila: " << p->numero << endl;
    }
}


void removerRepetidos(fila *raiz){
   fila *x = raiz;//x é o primeiro elemento da fila
    fila *y = NULL;//y é o segundo elemento da fila
    fila *remocao = NULL;//remocao é o elemento que será removido da fila

    while (x && x->proximo){ //enquanto x e o próximo elemento de x existirem
        y = x;//y recebe o valor de x
        while (y->proximo){//enquanto o próximo elemento de y existir
            if (x->numero == y->proximo->numero){//se o número de x for igual ao número do próximo elemento de y
                remocao = y->proximo;//remocao recebe o próximo elemento de y
                y->proximo = y->proximo->proximo;//o próximo elemento de y recebe o próximo elemento do próximo elemento de y
                free(remocao);//aux é removido da fila
            }
            else{
                y = y->proximo;//y recebe o próximo elemento de y
            }
        }
        x = x->proximo;//x recebe o próximo elemento de x
    }
}

