#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Fatura{
private:
    int numero;
    string descricao;
    int quantidade;
    float precoUnitario;
public:
    int getNumero(){
        return numero;
    }
    string getDescricao(){
        return descricao;
    }
    int getQuantidade(){
        return quantidade;
    }
    float getPrecoUnitario(){
        return precoUnitario;
    }
    void setNumero(int novoNumero){
        this->numero = novoNumero;
    }
    void setDescricao(string novaDescricao){
        this->descricao = novaDescricao;
    }
    void setQuantidade(int novaQuantidade){
        this->quantidade = novaQuantidade;
    }
    void setPrecoUnitario(float novoPrecoUnitario){
        this->precoUnitario = novoPrecoUnitario;
    }
    float getValorFatura(){
        if(quantidade < 0){
            quantidade = 0;
        }
        if(precoUnitario < 0){
            precoUnitario = 0;
        }
        return quantidade * precoUnitario;
    }
};

int main(){
    Fatura fatura;
    fatura.setNumero(1);
    fatura.setDescricao("Teclado");
    fatura.setQuantidade(3);
    fatura.setPrecoUnitario(290.90);
    cout << "Numero: " << fatura.getNumero() << endl;
    cout << "Descricao: " << fatura.getDescricao() << endl;
    cout << "Quantidade: " << fatura.getQuantidade() << endl;
    cout << "Preco Unitario: "  << setprecision(2) << fixed << fatura.getPrecoUnitario() << endl;
    cout << "Valor total: "  << setprecision(2) << fatura.getValorFatura() << endl;

    return 0;
}
