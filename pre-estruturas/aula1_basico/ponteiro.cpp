#include <iostream>
using namespace std;

int main() {
    string alimento = "carne";
    string *refeicao = &alimento;

    cout << *refeicao << '\n';

    return 0;
}