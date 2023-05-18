#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class ContaBancaria{
private:	
  int numero;
  int agencia;
  float saldo;
  int codigoTipoConta;
  string nomeTipoConta;
public:
  int getNumero(){
    return numero;
  }
  int getAgencia(){
    return agencia;
  }
  float getSaldo(){
    return saldo;
  }
  int getCodigoTipoConta(){
    return codigoTipoConta;
  }
  string getNomeTipoConta(){
    return nomeTipoConta;
  }
  void setNumero(int numero){
    this->numero = numero;
  }
  void setAgencia(int agencia){
    this->agencia = agencia;
  }
  void setSaldo(float saldo){
    this->saldo = saldo;
  }
  void setCodigoTipoConta(int codigoTipoConta){
    this->codigoTipoConta = codigoTipoConta;
  }
  void setNomeTipoConta(string nomeTipoConta){
    this->nomeTipoConta = nomeTipoConta;
  }
  void depositar(float valor){
    this->saldo += valor;
  }
  void sacar(float valor){
    this->saldo -= valor;
  }

};

class contaImposto : public ContaBancaria{
private:
  float percentualImposto;
public:
  float getPercentualImposto(){
    return percentualImposto;
  }
  void setPercentualImposto(float percentualImposto){
    this->percentualImposto = percentualImposto;
  }
  void calcularImposto(){
    float imposto = this->getSaldo() * this->percentualImposto;
    this->setSaldo(this->getSaldo() - imposto);
  }
};
  
int main(){
  contaImposto conta;
  conta.setNumero(123);
  conta.setAgencia(456);
  conta.setSaldo(777);
  conta.setCodigoTipoConta(1);
  conta.setNomeTipoConta("Conta Corrente");
  conta.setPercentualImposto(0.1);
  conta.calcularImposto();
  cout << setprecision(2) << fixed << "Saldo: R$" << conta.getSaldo() << endl;
  return 0;
}