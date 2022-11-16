#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Calculadora {
   public:
    int numero1, numero2;
    int subtracao();
    int multiplicacao();
    int soma();
    float divisao();

};

int Calculadora::soma() {
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

    calc.numero1 = 4;
    calc.numero2 = 5;

    cout << "\nA soma dos números lidos é: " << calc.soma() << "\n\n";

    return 0;
}