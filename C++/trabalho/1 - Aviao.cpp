#include <iostream>
#include <string>

using namespace std;

struct Aviao{
    string bandeira;
    int contPassageiros;
    int numero;
    Aviao *proximo;
};

typedef Aviao aviao;

void numeroAvioes(aviao *raiz);
void decolagem(aviao *raiz);
void adicionarFila(aviao *raiz, string bandeira, int numero, int contPassageiros);
void listarFila(aviao *raiz);
void primeiroAviao(aviao *raiz);

int main(void){

    aviao *raiz = NULL;
    raiz = (aviao *)malloc(sizeof(aviao*));
    raiz->bandeira = "";
    raiz->contPassageiros = 0;
    raiz->numero = 0;
    raiz->proximo = NULL;

    int opcao = 99999999999999999;
    int numeroAviao = 0;
    string bandeira = "";
    int contPassageiros = 0;
    
    while (opcao != 0){
        cout << " Escolha uma opcao" << endl; 
        cout << "1 - Listar o número de aviões aguardando na fila de decolagem" << endl;
        cout << "2 - Autorizar a decolagem do primeiro avião da fila" << endl;
        cout << "3 - Adicionar avião a fila de espera" << endl;
        cout << "4 - Listar todos os Aviões na fila de espera" << endl;
        cout << "5 - Listar as características do primeiro avião da fila" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                if (raiz){
                    numeroAvioes(raiz);
                }
                break;
            case 2:
                if(raiz){
                    decolagem(raiz);
                }
                break;
            case 3:
                cout << "Digite a bandeira do avião:" << endl;
                cin >> bandeira;
                cout << "Digite a quantidade de passageiros do avião" << endl;
                cin >> contPassageiros;
                cout << "Digite o número do avião" << endl;
                cin >> numeroAviao;
                adicionarFila(raiz, bandeira, numeroAviao, contPassageiros);
                break;
             case 4:
                if (raiz){
                    numeroAvioes(raiz);
                }
                break;
            case 5:
                if (raiz){
                    primeiroAviao(raiz);
                }
                break;
            case 0:
                opcao = 0;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

    }

    return 0;

}

// void displayLL(node *p)//Mostra a lista
// {
//     p = p->proximo;
//     printf("Mostrando a fila:\n");
//     if (p)
//     {
//         do
//         {//insere sermpre no final da lista.
//             printf(" %d", p->valor);
//             p = p->proximo;
//         } while (p);
//         printf("\n\n");
//     }
//     else
//         printf("Fila vazia.\n\n");
// }

void numeroAvioes(aviao *raiz){
    aviao *temp = raiz->proximo;
    int contador = 0;

    while (temp)
    {
    temp = temp->proximo;
        contador++;
    }
    cout << contador << " aviões na fila." << endl;
}

// void remove_no_inicio(node *raiz){
//     node *remocao = raiz->proximo;
//     raiz->proximo = remocao->proximo;
//     free(remocao);
// }

void decolagem(aviao *raiz){


}