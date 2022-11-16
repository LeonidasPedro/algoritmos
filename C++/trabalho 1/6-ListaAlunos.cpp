#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Aluno{
    int matricula;
    int idade;
    string nome;
    Aluno *proximo;
};

typedef Aluno aluno;

void inserirAluno(aluno *raiz, int matricula, string nome);
void retirarAluno(aluno *raiz, int matricula);

int main(void){
    
        aluno *raiz = NULL;
        raiz = (aluno *)malloc(sizeof(aluno*));
        raiz->matricula = 0;
        raiz->nome;
        raiz->idade = 0;
        raiz->proximo = NULL;

        int matricula = 0;
        string nome;
        int idade = 0;

        for (int i = 0; i < 40; i++){
            cout << "Digite a matricula do aluno:" << endl;
            cin >> matricula;
            cout << "Digite o nome do aluno:" << endl;
            cin >> nome;
            cout << "Digite a idade do aluno:" << endl;
            cin >> idade;
            inserirAluno(raiz, matricula, nome);

           return 0;
}

}

void inserirAluno(aluno *raiz, int matricula, string nome){
    aluno *novo = NULL;
    novo = (aluno *)malloc(sizeof(aluno*));
    novo->matricula = matricula;
    novo->nome = nome;
    novo->proximo = NULL;

    aluno *p = raiz;
    while(p->proximo){
        if(p->matricula == matricula){
            retirarAluno(raiz, matricula);
        }
        p = p->proximo;
    }
    p->proximo = novo;
}

void retirarAluno(aluno *raiz, int matricula){
    aluno *p = raiz;
    aluno *proximo = NULL;
    while(p->proximo){
        if(p->matricula == matricula){
            cout << "Matricula: " << p->matricula << endl;
            cout << "Nome: " << p->nome << endl;
            cout << "Idade: " << p->idade << endl;
            proximo = p->proximo;
            p->proximo = proximo->proximo;
            free(proximo);
        }
        p = p->proximo;
    }
}

