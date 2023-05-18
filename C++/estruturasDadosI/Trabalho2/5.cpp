#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Ingresso{
  private:
    float valor;
  public:
    float getValor(){
      return valor;
    }
    void setValor(float valor){
      this->valor = valor;
    }
    void imprimeValor(){
      cout << "Valor do ingresso: R$" << setprecision(2) << fixed << this->valor << endl;
    }

};

class IngressoVip : public Ingresso{
  private:
    float valorAdicional;
  public:
    float getValorAdicional(){
      return valorAdicional;
    }
    void setValorAdicional(float valorAdicional){
      this->valorAdicional = valorAdicional;
    }
    void imprimeValor(){
      cout << "Valor do ingresso VIP: R$" << setprecision(2) << fixed << this->getValor() + this->valorAdicional << endl;
    }
};

int main(){
  Ingresso ingresso;
  ingresso.setValor(100);
  ingresso.imprimeValor();

  IngressoVip ingressoVip;
  ingressoVip.setValor(100);
  ingressoVip.setValorAdicional(50);
  ingressoVip.imprimeValor();

  return 0;
}