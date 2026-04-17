#include <iostream>
using namespace std;

int main() {
    string nome = "Kanye ";
    string sobrenome = "West";

    string nomeCompleto = nome.append(sobrenome);


    cout << nomeCompleto << " tem " << nomeCompleto.length() << " caracteres.\n";


    cout << "Agora digite seu nome ";
    cin >> nomeCompleto;

    cout << nomeCompleto << " tem " << nomeCompleto.length() << " caracteres.\n";


}   