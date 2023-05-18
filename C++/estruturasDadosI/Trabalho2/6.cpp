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

class VIP : public Ingresso{
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


class Normal : public Ingresso{
    public:
        void imprimeValor(){
        cout << "Ingresso Normal: R$" << setprecision(2) << fixed << this->getValor() << endl;
        }
};

class CamaroteInferior : public VIP{
    private:
        string localizacao;
    public:
        string getLocalizacao(){
        return localizacao;
        }
        void setLocalizacao(string localizacao){
        this->localizacao = localizacao;
        }
        void imprimeValor(){
        cout << "Valor do ingresso VIP: R$" << setprecision(2) << fixed << this->getValor() + this->getValorAdicional() << endl;
        cout << "Localizacao: " << this->getLocalizacao() << endl;
        }
};

class CamaroteSuperior : public VIP{
    private:
        float valorCamarote;

    public:
        float getValorCamarote(){
        return valorCamarote;
        }
        void setValorCamarote(float valorCamarote){
        this->valorCamarote = valorCamarote;
        }
        void imprimeValor(){
        cout << "Valor do ingresso VIP: R$" << setprecision(2) << fixed << this->getValor() + this->getValorAdicional() + this->valorCamarote << endl;
        }
};



int main(){
    Normal ingresso;
    ingresso.setValor(100);
    ingresso.imprimeValor();

    CamaroteInferior ingressoVip;
    ingressoVip.setValor(100);
    ingressoVip.setValorAdicional(50);
    ingressoVip.setLocalizacao("Camarote Inferior");
    ingressoVip.imprimeValor();

    CamaroteSuperior ingressoVip2;
    ingressoVip2.setValor(100);
    ingressoVip2.setValorAdicional(50);
    ingressoVip2.setValorCamarote(100);
    ingressoVip2.imprimeValor();

  return 0;
}