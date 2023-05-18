#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class bhaskara
{
private:
    int a;
    int b;
    int c;
    float r1;
    float r2;
    float delta;

public:
    void setA(int A);
    void setB(int B);
    void setC(int C);
    void setDelta();
    float getDelta();
    void setRaizes();
    float getR1();
    float getR2();
};

float bhaskara::getR1() {
    return r1;
}

float bhaskara::getR2() {
    return r2;
}

void bhaskara::setRaizes(){
    r1 = (-b + sqrt(delta))/(2*a);
    r2 = (-b - sqrt(delta))/(2*a);
}

void bhaskara::setA(int A){
    a = A;
};

float bhaskara::getDelta(){
    return delta;
};

void bhaskara::setB(int B){
    b = B;
};

void bhaskara::setC(int C){
    c = C;
};

void bhaskara::setDelta(){
    delta = b * b - 4 * a * c;
}

int main(){

    bhaskara objeto;
    float delta;

    objeto.setA(1);
    objeto.setB(5);
    objeto.setC(5);
    objeto.setDelta();
    objeto.setRaizes();

    delta = objeto.getDelta();

    cout << "Delta: " << delta << endl;
    cout << fixed << setprecision(2);
    cout << "r1: " << objeto.getR1() << fixed << setprecision(1) << endl;
    cout << "r2: " << objeto.getR2() << endl;

    return 0;
}