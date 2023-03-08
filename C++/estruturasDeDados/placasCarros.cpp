#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> cars;
    int placa;
    int placaForget;
    for (int i = 0; i < 7; i++){
        cout << "Digite a placa do carro: nº " << i+1 << endl;
        cin >> placa;
        cars.push(placa);
    }
    cout << "Sua placa" << endl;
    cin >> placaForget;
    for (int i = 0; i < 7; i++){
        if (placaForget == cars.top()) break;
        cout << "Saindo carro placa " <<  cars.top() << endl;
        cars.pop();
    }
    cout << "Randandandandan" << endl;

    return 0;
}