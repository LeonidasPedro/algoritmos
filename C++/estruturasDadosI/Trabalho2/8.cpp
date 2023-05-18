#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Livros{
  private:
    string titulo;
    bool emprestado;
  public:
    void setTitulo(string novoTitulo){
      this->titulo = novoTitulo;
    }
    void setEmprestado(bool novoEmprestado){
      this->emprestado = novoEmprestado;
    }

    string getTitulo(){
      return titulo;
    }

    string isEmprestado(){
      if(emprestado){
        return "Emprestado";
      }else{
        return "Disponivel";
      }
    }
};

class Periodicos{
  private:
    string titulo;
    int volume;

  public:
    void setTitulo(string novoTitulo){
      this->titulo = novoTitulo;
    }
    void setVolume(int novoVolume){
      this->volume = novoVolume;
    }

    string getTitulo(){
      return titulo;
    }

    int getVolume(){
      return volume;
    }
};

int main(){
  cout << "+---------------------+" << endl;
  Livros livro;
  livro.setTitulo("Como carnear um porco");
  livro.setEmprestado(true);
  cout << "Titulo: " << livro.getTitulo() << endl;
  cout << "Status: " << livro.isEmprestado() << endl;

  cout << "+---------------------+" << endl;

  Periodicos periodico;
  periodico.setTitulo("journal of medicine");
  periodico.setVolume(1);
  cout << "Titulo: " << periodico.getTitulo() << endl;
  cout << "Volume: " << periodico.getVolume() << endl;
  cout << "+---------------------+" << endl;
  return 0;
}