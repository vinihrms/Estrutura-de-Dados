#include "PilhaEnc.hpp"
#include <iostream>

using namespace std;

void printaVazia(PilhaEnc<int> pilha){
    if(pilha.pilhaVazia()){
        printf("Pilha vazia\n");
    } else {
        printf("Não está vazia\n");
    }
}



int main(){
    PilhaEnc<int> p1;

    printaVazia(p1);
    int a = 1;
    int b = 3;
    int c = 2;

    p1.empilha(a);
    cout << "Topo: "<< p1.topo() << endl;
    p1.empilha(b);
    cout << "Topo: "<< p1.topo() << endl;
    p1.empilha(c);
    cout << "Topo: "<< p1.topo() << endl;
    printaVazia(p1);

    p1.desempilha();
    cout << "Topo: "<< p1.topo() << endl;
    p1.desempilha();
    cout << "Topo: "<< p1.topo() << endl;
    p1.desempilha();

    printaVazia(p1);

}