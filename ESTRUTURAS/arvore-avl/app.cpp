// app.cpp
// autor: Vinícius A. Hermes
// Programa: Testes do programa de Árvore ALV fornecidos pelo professor
// clang++ app.cpp -o app.exe && ./app.exe


#include <iostream>
#include "ArvoreAVL.hpp"

using namespace std;

void imprimirEmOrdem( ArvoreAVL<int> *av){
    av->emOrdem(av);
    auto elementos = av->getElementos();
    for (int i = 0; i < elementos.size(); i++) {
        cout << *elementos[i]->getDado() << " ";
    }
    cout << "\n";

}

void rotacaoSimplesEsq(){
    ArvoreAVL<int> *av = new ArvoreAVL<int>(1);
    cout << "Criando a árvore com raiz 1 e imprimindo sua altura.\n";
    cout <<av->getAltura() << "\n";
    cout <<"Inserindo: 2; 1." << "\n";
    av = av->inserir(2, av);
    av = av->inserir(3, av);
    cout << "Os elementos foram rotacionados à esquerda.\n";
    cout << "Altura: "<< av->getAltura() << "\n";
    cout << "Raiz: " << *av->getDado() << "\n";

    imprimirEmOrdem(av);
}


void rotacaoSimplesDir(){
    ArvoreAVL<int> *av = new ArvoreAVL<int>(9);
    cout << "Criando a árvore com raiz 9 e imprimindo sua altura.\n";
    cout <<av->getAltura() << "\n";
    cout <<"Inserindo: 8; 7." << "\n";
    av = av->inserir(8, av);
    av = av->inserir(7, av);
    cout << "Os elementos foram rotacionados à direita.\n";
    cout << "Altura: "<< av->getAltura() << "\n";
    cout << "Raiz: " << *av->getDado() << "\n";

    imprimirEmOrdem(av);
}



void rotacaoDuplaEsq(){
    ArvoreAVL<int> *av = new ArvoreAVL<int>(5);
    cout << "Criando a árvore com raiz 5 e imprimindo sua altura.\n";
    cout <<av->getAltura() << "\n";
    cout <<"Inserindo: 0; 10; 8; 9" << "\n";
    av = av->inserir(0, av);
    av = av->inserir(10, av);
    av = av->inserir(8, av);
    av = av->inserir(9, av);
    cout << "Os elementos foram rotacionados duplamente à esquerda.\n";
    cout << "Altura: "<< av->getAltura() << "\n";
    cout << "Raiz: " << *av->getDado() << "\n";

    imprimirEmOrdem(av);
}


void rotacaoDuplaDir(){
    ArvoreAVL<int> *av = new ArvoreAVL<int>(5);
    cout << "Criando a árvore com raiz 5 e imprimindo sua altura.\n";
    cout <<av->getAltura() << "\n";
    cout <<"Inserindo: 0; 10; 4; 3" << "\n";
    av = av->inserir(0, av);
    av = av->inserir(10, av);
    av = av->inserir(4, av);
    av = av->inserir(3, av);
    cout << "Os elementos foram rotacionados duplamente à direita.\n";
    cout << "Altura: "<< av->getAltura() << "\n";
    cout << "Raiz: " << *av->getDado() << "\n";

    imprimirEmOrdem(av);
}


int main() {

    bool fim = false;

    do {
    unsigned int opcao;
    cout << "Digite uma opcao:\n[1] Rotação simples à esquerda\n[2] Rotação simples à direira\n[3] Rotação dupla à esquerda\n[4] Rotação dupla à esquerda\n[0] Fim\n";
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao)
        {
        case 0:
            fim = true;
            break;
        case 1:
            rotacaoSimplesEsq();
            break;
        case 2:
            rotacaoSimplesDir();
            break;
        case 3:
            rotacaoDuplaEsq();
            break;
        case 4:
            rotacaoDuplaDir();
            break;
        default:
            cout << "Opção inválida!!\n";
            break;
        }
    } while(fim == false);
    

    return 0;
}