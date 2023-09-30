#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Aluno{
  private:
    int id;
    string nome;
    int idade;
    float peso;
    float altura;
    float imc;

  public:
    void setId(int novoId){
      this->id = novoId;
    }
    void setNome(string novoNome){
      this->nome = novoNome;
    }
    void setIdade(int novaIdade){
      this->idade = novaIdade;
    }
    void setPeso(float novoPeso){
      this->peso = novoPeso;
    }
    void setAltura(float novaAltura){
      this->altura = novaAltura;
    }
    int getId(){
      return id;
    }
    string getNome(){
      return nome;
    }
    int getIdade(){
      return idade;
    }
    float getPeso(){
      return peso;
    }
    float getAltura(){
      return altura;
    }
    float getImc(){
      return imc;
    }
    void calcularImc(){
      imc = peso / (altura * altura);
    }
    void exibir(){
      cout << "+---------------------------------+" << endl;
      cout << "Id: " << id << endl;
      cout << "Nome: " << nome << endl;
      cout << "Idade: " << idade << endl;
      cout << "Peso: " << peso << "Kg" << endl;
      cout << "Altura: " << altura << "m" << endl;
      cout << "IMC: " << imc << endl;
      cout << "+---------------------------------+" << endl;
    }
};

int main(){
  Aluno aluno1;
  aluno1.setId(1);
  aluno1.setNome("Claudio");
  aluno1.setIdade(20);
  aluno1.setPeso(80);
  aluno1.setAltura(1.80);
  aluno1.calcularImc();
  aluno1.exibir();


  return 0;
}