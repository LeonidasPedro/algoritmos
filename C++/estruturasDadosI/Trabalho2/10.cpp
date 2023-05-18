#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Produto {
  private :
    string descricao;
    float valor;
    float imposto;
  public :
    void setDescricao(string novaDescricao){
      this->descricao = novaDescricao;
    }
    void setValor(float novoValor){
      this->valor = novoValor;
    }
    void setImposto(float novoImposto){
      this->imposto = novoImposto;
    }
    string getDescricao(){
      return this->descricao;
    }
    float getValor(){
      return this->valor;
    }
    float getImposto(){
      return this->imposto;
    }
};

class Estadual : public Produto {
  private: 
    float taxa = 0;
  public:
    void setTaxa(float novaTaxa){
      this->taxa = novaTaxa;
    }
    float getTaxa(){
      return this->taxa;
    }
    void impostoEstadual(){
      this->setImposto(this->getValor() * 0.1);
    }
    void mostrar(){
      cout << "+-------------------------+" << endl;
      cout << "Estadual" << endl;
      cout << "Descrição: " << this->getDescricao() << endl;
      cout << "Valor R$: " << this->getValor() << endl;
      cout << "Imposto R$: " << this->getImposto() << endl;
      cout << "Taxa R$: " << this->getTaxa() << endl;
      cout << "Valor Total R$: " << this->getValor() + this->getImposto() + this->getTaxa() << endl;
    }
};

class Nacional : public Produto {
  private: 
    float taxa;
  public:
    void setTaxa(){
      this->taxa =  this->getValor() * 0.05;
    }
    float getTaxa(){
      return this->taxa;
    }
    void impostoNacional(){
      this->setImposto(this->getValor() * 0.1);
    }
    void mostrar(){
      cout << "+-------------------------+" << endl;
      cout << "Nacional" << endl;
      cout << "Descrição: " << this->getDescricao() << endl;
      cout << "Valor R$: " << this->getValor() << endl;
      cout << "Imposto R$: " << this->getImposto() << endl;
      cout << "Taxa R$: " << this->getTaxa() << endl;
      cout << "Valor Total R$: " << this->getValor() + this->getImposto() + this->getTaxa() << endl;

    }

};

class Importado : public Produto {
  private: 
    float taxa;
    float taxaImportacao;
  public:
    void setTaxa(){
      this->taxa =  this->getValor() * 0.05;
    }
    float getTaxa(){
      return this->taxa;
    }
    void setTaxaImportacao(){
      this->taxaImportacao =  this->getValor() * 0.05;
    }
    void impostoImportado(){
      this->setImposto(this->getValor() * 0.1);
    }
    float getTaxaImportacao(){
      return this->taxaImportacao;
    }
  void mostrar(){
      cout << "+-------------------------+" << endl;
      cout << "Importado" << endl;
      cout << "Descrição: " << this->getDescricao() << endl;
      cout << "Valor R$: " << this->getValor() << endl;
      cout << "Imposto R$: " << this->getImposto() << endl;
      cout << "Taxa R$: " << this->getTaxa() << endl;
      cout << "Taxa de Importação R$: " << this->getTaxaImportacao() << endl;
      cout << "Valor Total R$: " << this->getValor() + this->getImposto() + this->getTaxa() + this->getTaxaImportacao() << endl;
    }
};

int main(){

  Estadual produtoEstadual;
  Nacional produtoNacional;
  Importado produtoImportado;

  cout << "Digite a descrição do produto: ";
  string descricao;
  cin >> descricao;
  produtoEstadual.setDescricao(descricao);
  produtoNacional.setDescricao(descricao);
  produtoImportado.setDescricao(descricao);

  cout << "Digite o valor do produto: ";
  float valor;
  cin >> valor;
  produtoEstadual.setValor(valor);
  produtoNacional.setValor(valor);
  produtoImportado.setValor(valor);

  produtoEstadual.impostoEstadual();
  produtoNacional.impostoNacional();
  produtoImportado.impostoImportado();

  produtoNacional.setTaxa();
  produtoImportado.setTaxa();

  produtoImportado.setTaxaImportacao();

  produtoEstadual.mostrar();
  produtoNacional.mostrar();
  produtoImportado.mostrar();


  return 0;

}