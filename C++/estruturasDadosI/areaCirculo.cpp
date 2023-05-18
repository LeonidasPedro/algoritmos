#include <iostream>
#include <string>
using namespace std;

void calculaArea(float raio, float  *resultado){
    *resultado =   3.14 * (raio * raio);
}

int main(){
    float raio;
    float area;
    float *ponteiro;
    
    cin >> raio;
    ponteiro = &area;
    calculaArea( raio, ponteiro);
    cout << area; 
}