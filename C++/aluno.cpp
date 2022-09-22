#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Aluno {

    int matricula;
    string nome;
    float nota1, nota2, nota3;
    float media;
    bool passou;
};

int main (){ 
    int quantidadeAlunos;
    int i;
    cout << "Digite a quantidade de alunos: ";
    cin >> quantidadeAlunos;
    Aluno aluno[quantidadeAlunos];
    for (i = 0; i < quantidadeAlunos; i++){
        cout << "O nome do aluno " << i + 1 << " é: ";
        cin >> aluno[i].nome;
        cout << "A matrícula do aluno é: ";
        cin >> aluno[i].matricula;
        cout << "A primeira nota é: ";
        cin >> aluno[i].nota1;
        cout << "A segunda nota é: ";
        cin >> aluno[i].nota2;
        cout << "A terceita nota é: ";
        cin >> aluno[i].nota3;
        
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3 ) / 3;
        cout << "A media do aluno "<<aluno[i].matricula<<" " << aluno[i].nome << " é " << aluno[i].media << "\n\n";
    };
     
    cout << "Situação dos alunos:\n\n" ;
     for (i = 0; i < quantidadeAlunos; i++){
        aluno[i].passou = aluno[i].media > 7 ? true : false;
        cout << "Aluno: " << aluno[i].nome << endl;
        if(aluno[i].passou){
            cout << "Aprovado \n";
        }else{
            cout << "Reprovado \n";
        }
     }
};
