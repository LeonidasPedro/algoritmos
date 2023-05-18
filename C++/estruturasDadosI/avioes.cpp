/*
Escreva um programa que simule o controle de uma pista de decolagem de aviões em um
aeroporto. Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:
a. Listar o número de aviões aguardando na fila de decolagem;
b. Autorizar a decolagem do primeiro avião da fila;
c. Adicionar um avião à fila de espera;
d. Listar todos os aviões na fila de espera;
e. Listar as características do primeiro avião da fila*/
#include <iostream>
#include <string>

using namespace std;

struct aviao{
    string bandeira;
    int numero;
    aviao *proximo;
};

void remove_no_inicio(aviao *raiz);
void insere_no_final(aviao *raiz, string bandeira, int numero);
void numero_avioes(aviao *p);
void displayPrimeiro(aviao *primeiro);

int main(void){

    aviao *raiz = NULL;
    raiz = (aviao *)malloc(sizeof(aviao *));
    raiz->bandeira = "";
    raiz->numero = 0;
    raiz->proximo = NULL;

    int opcao;
    string bandeira;
    int numero;

    while (opcao != 0){
    
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Listar o número de aviões aguardando na fila de decolagem" << endl;
        cout << "2 - Autorizar a decolagem do primeiro avião da fila" << endl;
        cout << "3 - Adicionar um avião à fila de espera" << endl;
        cout << "4 - Listar todos os aviões na fila de espera" << endl;
        cout << "5 - Listar as características do primeiro avião da fila" << endl;
        cout << "0 - Sair;" << endl;
        cin >> opcao;
        switch(opcao){
            case 1:
                if (raiz)
                    numero_avioes(raiz);
                break;
            case 2:
                if (raiz)
                    remove_no_inicio(raiz);
                break;
            case 3:
                cout << "Digite a bandeira do avião:" << endl;
                cin >> bandeira;
                cout << "Digite o número do avião:" << endl;
                cin >> numero;
               
                insere_no_final(raiz, bandeira, numero);
                break;
            case 4:
                if (raiz)
                    numero_avioes(raiz);
                break;
            case 5:
                if (raiz)
                    displayPrimeiro(raiz);
                break;
            case 0:
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }

    free(raiz);//liberando a memória alocada para a raiz.

    return 0;
}

void remove_no_inicio(aviao *raiz){
    cout << "autorizando decolagem do primeiro avião da fila" << endl;
    aviao *p = raiz->proximo;
    raiz->proximo = p->proximo;
    free(p);
}

void insere_no_final(aviao *raiz, string bandeira, int numero){
    aviao *p = raiz;
    while(p->proximo){
        p = p->proximo;
    }
    p->proximo = (aviao *)malloc(sizeof(aviao *));
    p->proximo->bandeira = bandeira;
    p->proximo->numero = numero;
    p->proximo->proximo = NULL;
}

void numero_avioes(aviao *p){
    int contador = 0;
    while(p->proximo){
        p = p->proximo;
        contador++;
    }
    printf("Número de aviões na fila: %d\n", contador);
}

void displayPrimeiro(aviao *primeiro){
    cout << "Primeiro avião da fila: " << endl;
    cout << "Bandeira: " << primeiro->proximo->bandeira << endl;
    cout << "Número: " << primeiro->proximo->numero << endl;
}