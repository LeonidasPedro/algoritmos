#include <iostream>
#include <string>
using namespace std;

void swap(int *x, int *y){
    int jonas;
    jonas = *x;
    *x = *y;
    *y = jonas;
}

int main(){

    int x = 1;
    int y = 9;

    swap(&x, &y);

    cout << x << endl;
    cout << y << endl;

    return 0;
}