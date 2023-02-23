#include <iostream>

using namespace std;

int main(){
    int a;
    int *ptr;
    a = 10;
    ptr = &a;
    cout << "O valor da variavel a é " << *ptr << endl;
}
