#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Calculadora {
  private:
    int numero1, numero2;

  public:
    int subtracao();
    int multiplicacao();
    float divisao();
    int getNumero1();
    int getNumero2();
    void setNumero1(int Numero1);
    void setNumero2(int Numero2);
    int soma();
};

int Calculadora::getNumero1(){
  return numero1;
}

int Calculadora::getNumero2(){
  return numero2;
}

void Calculadora::setNumero1(int Numero1){
  numero1 = Numero1;
}

void Calculadora::setNumero2(int Numero2){
  numero2 = Numero2;
}

int Calculadora::soma(){
    return numero1 + numero2;
}

float Calculadora::divisao(){
    return numero1 / numero2;
}

int Calculadora::subtracao() {
    return numero1 - numero2;
}

int Calculadora::multiplicacao() {
    return numero1 * numero2;
}

int main() {
    Calculadora calc;

    calc.setNumero1(1);
    calc.setNumero2(3);


    cout << "\nA soma dos números lidos é: " << calc.soma() << "\n\n";

    return 0;
}
