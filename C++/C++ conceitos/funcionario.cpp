#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Funcionario{
    string nome;
    double salarioFixo;
    double vendasEfetuadas;
    double salarioTotal;
};

double calculaSalarioTotal(double salario, double vendas);

int main(){
    Funcionario funcionario;
    cout << "O nome do funcionario é: ";
    cin >>  funcionario.nome;
    cout << "Salario: ";
    cin >> funcionario.salarioFixo;
    cout << "Vendas: ";
    cin >> funcionario.vendasEfetuadas;

    funcionario.salarioTotal = calculaSalarioTotal(funcionario.salarioFixo, funcionario.vendasEfetuadas);

    cout << "Salario total: " <<funcionario.salarioTotal;

}

double calculaSalarioTotal(double salario, double vendas){
    double total;
    total = salario + (vendas * 0.15);
    return total;
}
