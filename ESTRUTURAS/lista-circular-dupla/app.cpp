#include <iostream>
#include "ListaCircularDupla.hpp"

using namespace std;

int main()
{
    ListaCircularDupla<int> *l1 = new ListaCircularDupla<int>;

    l1->adicionaNoInicio(1);
    l1->adiciona(2);

    cout << "Após inserção de 1 e 2, printando o anterior do primeiro.\n";
    cout << l1->getUltimo() << "\n";

    l1->adicionaNaPosicao(99, 1);
    l1->adicionaNoInicio(3);
    cout << "O 99 está na lista?" << endl;
    if (l1->contem(99))
    {
        cout << "Sim, e está na posição: " << l1->posicao(99) << endl;
    }
    else
    {
        cout << "Não contém" << endl;
    }

    cout << "Lista\n";

    int i = 1;

    while (!l1->listaVazia())
    {

        if (i == 2)
        {
            cout << "O 99 está na lista?" << endl;
            if (l1->contem(99))
            {
                cout << "Sim, e está na posição: " << l1->posicao(99) << endl;
            }
            else
            {
                cout << "Não contém" << endl;
            }
        }

        cout <<"Retirando em ordem. "<< i << "a retirada: " << l1->retiraDoInicio() << "\n";
        i++;
    }

    if (l1->listaVazia())
    {
        cout << "A lista está vazia!\n";
    }
    else
    {
        cout << "Ainda há elementos na lista!\n";
    }
    return 0;
}
