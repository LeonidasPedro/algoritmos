#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Empregado{

private:
    string nome;
    string sobrenome;
    float salarioMensal;

public:
    string getNome(){
        return nome;
    }
    string getSobrenome(){
        return sobrenome;
    }
    float getSalarioMensal(){
        return salarioMensal;
    }
    void setNome(string novoNome){
        this->nome = novoNome;
    }
    void setSobrenome(string novoSobrenome){
        this->sobrenome = novoSobrenome;
    }
    void setSalarioMensal(float novoSalarioMensal){
        if(novoSalarioMensal < 0){
            novoSalarioMensal = 0;
        }
        this->salarioMensal = novoSalarioMensal;
    }
    float getSalarioAnual(){
        return salarioMensal * 12;
    }
    float getAumentoSalario(){
        return salarioMensal * 0.1;
    }
};

int main(){
    Empregado empregado1;
    empregado1.setNome("Claudio");
    empregado1.setSobrenome("Fernando");
    empregado1.setSalarioMensal(2000);
    Empregado empregado2;
    empregado2.setNome("Ferdinando");
    empregado2.setSobrenome("CLaudio");
    empregado2.setSalarioMensal(2000);
    
     cout << "+---------------------------------+" << endl;
    cout << "Nome: " << empregado1.getNome() << " " << empregado1.getSobrenome() << endl;
    cout << "Salario Mensal: " << fixed << setprecision(2) << empregado1.getSalarioMensal() << endl; 
    cout << "Salario Anual: " << empregado1.getSalarioAnual() << endl;
    cout << "Aumento de Salario: " << empregado1.getAumentoSalario() << endl;
    cout << "+---------------------------------+" << endl;
    cout << "Nome: " << empregado2.getNome() << " " << empregado2.getSobrenome() << endl;
    cout << "Salario Mensal: " << empregado2.getSalarioMensal() << endl;
    cout << "Salario Anual: " << empregado2.getSalarioAnual() << endl;
    cout << "Aumento de Salario: " << empregado2.getAumentoSalario() << endl;
    
    return 0;
}