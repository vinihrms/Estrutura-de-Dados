#include <iostream>
#include "trabalhador.h"

using namespace std;

int main()
{
    Trabalhador t1("Jair Bolsonaro", 22, "PL");
    Trabalhador t2("Kanye West", 30, "Música");

    cout << t1.GetNome() << endl;

    t1.SetNome("Vinícius");
    cout << endl
         << endl
         << "T1" << endl;
    t1.ApresenteSe();
    cout << endl
         << endl
         << "T2" << endl;
    t2.ApresenteSe();
}