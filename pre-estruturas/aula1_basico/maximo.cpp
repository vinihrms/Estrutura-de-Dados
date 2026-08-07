#include <iostream>
using namespace std;

int max(int a, int b){
    if(a-b > 0){
        return a;
    } else if (b-a > 0)
    {
        return b;
    } else { //iguais
        return a;
    }
}

int pow(int a, int b){
    if( b == 0){
        return 1;
    } else {
       return a * pow(a, b - 1);
    }
}

int main() {
    int a, b;
    cout << "Digite dois números separados: ";
    
    cin >> a;
    cin >> b;

    cout << "O maior número é: " << max(a, b) << "\n";

    cout << "O primeiro elevado ao segundo é: " << pow(a, b) << "\n";



}

