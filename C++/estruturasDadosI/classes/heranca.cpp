/*encapsulamento é o conceito de privar atribudos e criar métodos
 This (objeto que está em memória)
herança: herdar metodos E atibutos de uma classe existente
 polimorfismo: uma herança que modifica métodos

 Implementar um método pra fazer a leitura de 3 notas e retornar a média*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Pessoa{
private:
    int id{};
    string nome;

public:

    int getId(){
        return this->id;
    }

    void setId(int novoId){
        this->id = novoId;
    }

    string getNome(){
        return this->nome;
    }

    void setNome(string novoNome){
        this->nome = novoNome;
    }

};

class Aluno: public Pessoa{
private:
    string curso;
    float nota1, nota2, nota3;

public:
    float calculomedia(){
        return (this->nota1 + this->nota2 + this->nota3)/3;
    }
    string getCurso(){
        return this->curso;
    }
    void setCurso(string novoCurso){
        this->curso = novoCurso;
    }
    void setNota1(float novaNota){
        this->nota1 = novaNota;
    }
    void setNota2(float novaNota){
        this->nota2 = novaNota;
    }
    void setNota3(float novaNota){
        this->nota3 = novaNota;
    }
};

int main(){

    Pessoa pessoa;
    pessoa.setId(1);
    pessoa.setNome("Teste de Pessoa");

    Aluno aluno;
    aluno.setId(2);
    aluno.setNome("Teste do Aluno");
    aluno.setCurso("CComp.");
    aluno.setNota1(7.0);
    aluno.setNota2(5.0);
    aluno.setNota3(4.0);

    cout << "Pessoa: " << pessoa.getId() << " - " << pessoa.getNome() << "\n";
    cout << "Aluno: " << aluno.getId() << " - " << aluno.getNome() << " - " << aluno.getCurso() << "\n";
    cout << setprecision(2) << aluno.calculomedia() << endl;


    return EXIT_SUCCESS;
}