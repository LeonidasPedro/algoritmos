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

void inserirAluno(aluno *raiz, int matricula, string nome, int idade);
void retirarAlunos(aluno *raiz, int idade);
void ListarAlunos(aluno *raiz);

int main(void){

    aluno *raiz = NULL;
    raiz = (aluno *)malloc(sizeof(aluno*));
    raiz->matricula = 0;
    raiz->idade = 0;
    raiz->nome;
    raiz->proximo = NULL;

    int numeroEntradas = 0;
    int matricula = 0;
    string nome;
    int idade = 0;
    int idadeLimite = 0;

    cout << "Digite o número de entradas:" << endl;
    cin >> numeroEntradas;
    for (int i = 0; i < numeroEntradas; i++){
        cout << "Digite a matricula do aluno:" << endl;
        cin >> matricula;
        cout << "Digite o nome do aluno:" << endl;
        cin >> nome;
        cout << "Digite a idade do aluno:" << endl;
        cin >> idade;
        inserirAluno(raiz, matricula, nome, idade);
    }

    cout << "Lista de alunos:" << endl;
    ListarAlunos(raiz);

    cout << "Digite a idade limite:" << endl;
    cin >> idadeLimite;
    retirarAlunos(raiz, idadeLimite);

    cout << "Lista de alunos com idade maior que " << idadeLimite << ":" << endl;
    ListarAlunos(raiz);


    return 0;

}

void inserirAluno(aluno *raiz, int matricula, string nome, int idade){
    aluno *novo = NULL;
    novo = (aluno *)malloc(sizeof(aluno*));
    novo->matricula = matricula;
    novo->nome = nome;
    novo->idade = idade;
    novo->proximo = NULL;

    aluno *p = raiz;
   
    while (p->proximo)
    {
        p = p->proximo;
    }
    p->proximo = novo;
}


void retirarAlunos(aluno *raiz, int idade){
    aluno *p = raiz;
    aluno *q = NULL;
    while (p->proximo)
    {
        if (p->idade < idade)
        {
            q = p->proximo;
            p->proximo = q->proximo;
            free(q);
        }
        p = p->proximo;
    }
}

void listarAlunos(aluno *raiz){
    aluno *p = raiz->proximo;
    while (p)
    {
        cout << "Matricula: " << p->matricula << endl;
        cout << "Nome: " << p->nome << endl;
        cout << "Idade: " << p->idade << endl;
        cout << "---------------------------------" << endl;
        p = p->proximo;
    }
}