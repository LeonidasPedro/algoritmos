#include <iostream>

using namespace std;

int main(){
    int *ptr_ex;
    ptr_ex = new int;//aloquei espaço de memória

    if(ptr_ex == NULL){// se não for possivel alocar a memória é porque faltou ram
      cout << "Memoria insuficiente" << endl;
    }
    cout << "endereço de ptr_ex: " << ptr_ex << endl;
    cout << "O valor de ptr_ex: " << *ptr_ex << endl;
    delete ptr_ex;
    return 0;
}
