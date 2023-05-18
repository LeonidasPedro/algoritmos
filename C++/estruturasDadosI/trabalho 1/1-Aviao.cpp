#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Aviao{
    string bandeira;
    int contPassageiros;
    int numero;
    Aviao *proximo;
};

typedef Aviao aviao;

void numeroAvioes(aviao *raiz);
void decolagem(aviao *raiz);
void adicionarFila(aviao *raiz, string bandeira, int numero, int contPassageiros);
void listarFila(aviao *raiz);
void primeiroAviao(aviao *raiz);

int main(void){

    aviao *raiz = NULL;
    raiz = (aviao *)malloc(sizeof(aviao*));
    raiz->contPassageiros = 0;
    raiz->numero = 0;
    raiz->bandeira = "                                                      ";
    raiz->proximo = NULL;

    int opcao = 9;
    int numeroAviao = 0;
    string bandeira = "                                                   ";
    int contPassageiros = 0;
    
    while (opcao != 0){
        cout << " Escolha uma opcao" << endl; 
        cout << "1 - Listar o número de aviões aguardando na fila de decolagem" << endl;
        cout << "2 - Autorizar a decolagem do primeiro avião da fila" << endl;
        cout << "3 - Adicionar avião a fila de espera" << endl;
        cout << "4 - Listar todos os Aviões na fila de espera" << endl;
        cout << "5 - Listar as características do primeiro avião da fila" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                if (raiz){
                    numeroAvioes(raiz);
                }
                break;
            case 2:
                if(raiz){
                    decolagem(raiz);
                }
                break;
            case 3:
                cout << "Digite a bandeira do avião:" << endl;
                cin >> bandeira;
                cout << "Digite a quantidade de passageiros do avião" << endl;
                cin >> contPassageiros;
                cout << "Digite o número do avião" << endl;
                cin >> numeroAviao;
                adicionarFila(raiz, bandeira, numeroAviao, contPassageiros);
                break;
             case 4:
                if (raiz){
                    numeroAvioes(raiz);
                }
                break;
            case 5:
                if (raiz){
                    primeiroAviao(raiz);
                }
                break;
            case 0:
                opcao = 0;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

    }
    free(raiz);

    return 0;

}

void numeroAvioes(aviao *raiz){
    aviao *x = raiz->proximo;
    int contador = 0;
    while (x)
    {
    x = x->proximo;
        contador++;
    }
    cout << contador << " aviões na fila." << endl;
}

void decolagem(aviao *raiz){
    aviao *remocao = raiz->proximo;
    raiz->proximo = remocao->proximo;
    free(remocao);
}

void adicionarFila(aviao *raiz, string bandeira, int numero, int contPassageiros){
    aviao *novo = (aviao *)malloc(sizeof(aviao*));
    novo->bandeira = bandeira;
    novo->contPassageiros = contPassageiros;
    novo->numero = numero;
    novo->proximo = NULL;

    aviao *temp = raiz;
    while (temp->proximo)
    {
        temp = temp->proximo;
    }
    temp->proximo = novo;
}

void listarFila(aviao *raiz){
    aviao *temp = raiz->proximo;
    int contador = 0;

    while (temp)
    {   cout << "Avião " << contador << endl;
        cout << "Bandeira: " << temp->bandeira << endl;
        cout << "Número: " << temp->numero << endl;
        cout << "Passageiros: " << temp->contPassageiros << endl;
        temp = temp->proximo;
        contador++;
    }
}

void primeiroAviao(aviao *raiz){
    aviao *temp = raiz->proximo;
    cout << "Bandeira: " << temp->bandeira << endl;
    cout << "Número: " << temp->numero << endl;
    cout << "Passageiros: " << temp->contPassageiros << endl;
}

