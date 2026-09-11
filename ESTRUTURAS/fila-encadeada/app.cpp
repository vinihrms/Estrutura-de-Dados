#include "FilaEnc.hpp"
#include <iostream>

void printaVazia(FilaEnc<int> fila){
    if(fila.filaVazia()){
        printf("Fila vazia\n");
    } else {
        printf("Não está vazia\n");
    }
}

int main(){
    FilaEnc<int> f1;

    printaVazia(f1);
    int a = 1;
    int b = 3;
    int c = 2;

    f1.adiciona(a);
    f1.adiciona(b);
    f1.adiciona(c);

    f1.imprime();
    
    printaVazia(f1);

    f1.retira();
    f1.imprime();
    f1.retira();
    f1.imprime();
    f1.retira();

    printaVazia(f1);
    f1.imprime();

    f1.~FilaEnc();
}