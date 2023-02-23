#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> cars;
    int placa;
    int placaForget;
    for (int i = 0; i < 7; i++){
        cin >> placa;
        cars.push(placa);
    }
    cout << "Sua placa" << endl;
    cin >> placaForget;
    for (int i = 0; i < 7; i++){
        if (placaForget == cars.top()) break;
        cout << cars.top() << endl;
        cars.pop();
    }

    return 0;
}