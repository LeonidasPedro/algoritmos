#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Imovel{
    private:
        string endereco;
        float preco;
    public:
        void setEndereco(string novoEndereco){
            this->endereco = novoEndereco;
        }
        void setPreco(float novoPreco){
            this->preco = novoPreco;
        }
        string getEndereco(){
            return this->endereco;
        }
        float getPreco(){

                return this->preco;
        }
};

class Novo : public Imovel{
    private:
        float adicional;
    public:
        void setAdicional(float novoAdicional){
            this->adicional = novoAdicional;
        }
        float getAdicional(){
            return this->adicional;
        }
        float getPreco(){
            return this->getPreco() + this->adicional;
        }
        void imprime(){
            cout << "Endereço: " << this->getEndereco() << endl;
            cout << "Preço: R$" << setprecision(2) << fixed << this->getPreco() << endl;
        }
};

class Velho : public Imovel{
    private:
        float desconto;
    public:
        void setDesconto(float novoDesconto){
            this->desconto = novoDesconto;
        }
        float getDesconto(){
            return this->desconto;
        }
        float getPreco(){
            return this->getPreco() - this->desconto;
        }
        void imprime(){
            cout << "Endereço: " << this->getEndereco() << endl;
            cout << "Preço: R$" << setprecision(2) << fixed << this->getPreco() << endl;
        }
};

int main(){
    Novo novo;
    novo.setEndereco("Rua Xurusbango");
    novo.setAdicional(50);
    novo.setPreco(100);
    novo.imprime();

    Velho velho;
    velho.setEndereco("Rua Xurusbago");
    velho.setDesconto(50);
    velho.setPreco(100);
    velho.imprime();

    return 0;
}