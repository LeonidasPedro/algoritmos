//EXEMPLO ESTRUTURADO - structs e funções

//Como representar OS DADOS DE UM CLIMATIZADOR?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cls system("clear")
#define DOLAR 5.52

typedef struct Climatizador {
    char marca[20];
    int btu;
    float preco;
} Climatizador;

void boasVindas(); //retorno nome ( parametros )
int quantidadeCadastrada(); //declaracao
void cadastrarClimatizador();
void listarClimatizadores();
void popularVetor();


struct Climatizador c[10]; //com o dado que eu criei, eu defino um vetor de climatizadores
int qtde = 1; //para controlar quantos climatizadores eu tenho


int main(){
    //printf("Um climatizador tem %d bytes ", sizeof(struct Climatizador) );
    popularVetor();
    int op;
    while(1 == 1){
        boasVindas();
        scanf("%d", &op);
        if(op == 1){
            cadastrarClimatizador();
        }

        if (op == 2){
            listarClimatizadores();
        }

        if(op == 3) break; //irá forçar o encerramento do laço infinito

    }


    /*
    do {
        boasVindas();
        scanf("%d", &op);


    } while(op != 3);
    */

}

void boasVindas(){
    cls;
    printf("Bem vindo ao cadastro de Climatizadores \n");
    printf("1 - Cadastrar \n 2 - Listar \n 3 - Sair \n Sua opcao: ");
}


void cadastrarClimatizador(){
    printf("\nDigite os dados: marca, potencia e preco: ");
    fflush(stdin); //File Flush stdin = Esvazia o arquivo, no caso, standard input
    fgets(c[qtde].marca, sizeof(c[qtde].marca), stdin);
    scanf("%d", &c[qtde].btu);
    scanf("%f", &c[qtde].preco);

    printf("Cadastrou o climatizador %s com sucesso", c[qtde].marca);
    qtde++; //incrementa o total de cadastros
    printf("\nTOTAL DE REGISTROS: %d", qtde);
    getc(stdin); //forçar o programa a parar e esperar apertar uma tecla

}

void listarClimatizadores(){
    
    cls;
    int i = 0;
    printf("LISTA: ");
    printf("\n MARCA \t POTENCIA  PRECO");
    while(i < qtde){
        printf("\n%s \t", c[i].marca);
        printf("%d ", c[i].btu);
        printf("%.2f", c[i].preco);
        i++;
    }
    printf("\n\nTotal de registros: %d", qtde);
    getc(stdin);
}

void popularVetor(){
    strcpy(c[0].marca, "Consul");
    c[0].btu = 12000;
    c[0].preco = 900;
}


int quantidadeCadastrada(){
    return 1;
}