#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Jogador{
private:
    string nome;
    string posicao;
    string dataNascimento;
    string nacionalidade;
    float altura;
    float peso;
    int idade;
public:
    string getNome(){
        return nome;
    }
    string getPosicao(){
        return posicao;
    }
    string getDataNascimento(){
        return dataNascimento;
    }
    string getNacionalidade(){
        return nacionalidade;
    }
    float getAltura(){
        return altura;
    }
    float getPeso(){
        return peso;
    }
    void setNome(){
        cout << "Digite o nome do jogador: " << endl;
        string novoNome;
        cin >> novoNome;
        this->nome = novoNome;
    }
    void setDataNacimiento(){
        cout << "Digite a data de nascimento do jogador: " << endl;
        string novaDataNascimento;
        cin >> novaDataNascimento;
        this->dataNascimento = novaDataNascimento;
    }
    void setNacionalidade(){
        cout << "Digite a nacionalidade do jogador: " << endl;
        string novaNacionalidade;
        cin >> novaNacionalidade;
        this->nacionalidade = novaNacionalidade;
    }
    void setAltura(){
        cout << "Digite a altura do jogador: " << endl;
        float novaAltura;
        cin >> novaAltura;
        this->altura = novaAltura;
    }
    void setPeso(){
        cout << "Digite o peso do jogador: " << endl;
        float novoPeso;
        cin >> novoPeso;
        this->peso = novoPeso;
    }
    void setPosicao(){
      int opcao;
      cout << "Qual a posição do jogador? " << endl;
      cout << "1 - Defesa" << endl;
      cout << "2 - Meio-Campo" << endl;
      cout << "3 - Ataque" << endl;
      cin >> opcao;
      switch(opcao){
        case 1:
          this->posicao = "Defesa";
          break;
        case 2:
          this->posicao = "Meio-Campo";
          break;
        case 3:
          this->posicao = "Ataque";
          break;
        default:
          cout << "Opção inválida" << endl;
          break;
      }
    }
    void imprimeDados(){
        cout << "Nome: " << this->nome << endl;
        cout << "Posição: " << this->posicao << endl;
        cout << "Data de Nascimento: " << this->dataNascimento << endl;
        cout << "Nacionalidade: " << this->nacionalidade << endl;
        cout << "Altura: " << this->altura << " cm" << endl;
        cout << "Peso: " << this->peso << " Kg" << endl;
    }
  void calculaIdade(){
    int idade;
    string dataAtual;
    cout << "Digite a data atual: " << endl;
    cin >> dataAtual;
    idade = stoi(dataAtual.substr(6,4)) - stoi(this->dataNascimento.substr(6,4)); //stoi converte string para inteiro e substr pega uma parte da string (inicio, tamanho)
    this->idade = idade;
  }
  void setAposentadoria(){
    int idadeAposentadoria;
    if(this->posicao == "Defesa"){
      idadeAposentadoria = 40;
    }else if(this->posicao == "Meio-Campo"){
      idadeAposentadoria = 38;
    }else if(this->posicao == "Ataque"){
      idadeAposentadoria = 35;
    }
    if(this->idade >= idadeAposentadoria){
      cout << "Jogador já pode se aposentar" << endl;
    }else{
      cout << "Jogador ainda não pode se aposentar" << endl;
    }
  }
};

int main(){
    Jogador x;
    x.setNome();
    x.setPosicao();
    x.setDataNacimiento();
    x.setNacionalidade();
    x.setAltura();
    x.setPeso();
    x.calculaIdade();
    x.setAposentadoria();
    x.imprimeDados();
    return 0;
}