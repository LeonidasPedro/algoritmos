#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
   float n1 = 0.0;
   float n2 = 0.0;
   float medias[5];

   for(int i = 1; i < 6; i++){
       cout << "Digite a primeira nota do aluno " << i << endl;
       cin >> n1;
       cout << "Digite a segunda nota do aluno " << i << endl;
       cin >> n2;
       medias[i - 1] = ( n1 + n2 ) / 2;
   }

   for(float media : medias){
       if (media <= 6){
           cout << " " << media;
       }
   }
    return 0;
}

