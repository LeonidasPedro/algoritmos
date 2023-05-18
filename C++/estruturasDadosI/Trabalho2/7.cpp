#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Imovel {
    private:
        string endereco;
        float preco;
    public:
    void setEndereco(string endereco) {
        this->endereco = endereco;
    }

    void setPreco(float preco) {
        this->preco = preco;
    }

    string getEndereco() {
        return endereco;
    }

    float getPreco() {
        return preco;
    }
};

class Novo : public Imovel{
    private:
        float adicional;
    public:
        void setAdicional(float adicional) {
            this->adicional = adicional;
        }

        float getAdicional() {
            return adicional;
        }

        float getPrecoNovo() {
            return this->getPreco() + adicional;
        }
        void imprimir() {
            cout << "Endereço: " << this->getEndereco() << endl;
            cout << "Preço: R$" << this->getPrecoNovo() << endl;
        }
};

class Velho : public Imovel{
    private:
        float desconto;
    public:
        void setDesconto(float desconto) {
            this->desconto = desconto;
        }

        float getDesconto() {
            return desconto;
        }

        float getPrecoVelho() {
            return this->getPreco() - desconto;
        }
        void imprimir() {
            cout << "Endereço: " << setprecision(2) << fixed << this->getEndereco() << endl;
            cout << "Preço: R$" << setprecision(2) << fixed << this->getPrecoVelho() << endl;
        }
};

int main() {
    Novo novo;
    Velho velho;

    novo.setEndereco("Rua Forgetson");
    novo.setPreco(1000.00);
    novo.setAdicional(100.00);

    velho.setEndereco("Avenida Um");
    velho.setPreco(1000.00);
    velho.setDesconto(100.00);

    novo.imprimir();
    velho.imprimir();

    return 0;



}