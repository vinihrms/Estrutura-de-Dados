#ifndef LISTA_SE_H
#define LISTA_SE_H

#include "Elemento.h"

#define ERRO_LISTA_CHEIA 0
#define ERRO_LISTA_VAZIA 1
#define ERRO_POSICAO 2
#define ERRO_NAO_CONTEM 3



template<typename T>
class Lista{
private:
    Elemento<T> *_dados;
    int _tamanho;

public:
    Lista(); //
    void limpaLista();
    ~Lista(); //

    void destroiLista();

    bool listaVazia(); //
    int posicao(T dado); //
    bool contem(T dado); //

    void adiciona(T dado);
    void adicionaNoInicio(T dado); //
    void adicionaNaPosicao(T dado, int posicao); //
    void adicionaEmOrdem(T dado); //

    T retira();
    T retiraDoInicio(); //
    T retiraDaPosicao(int posicao); //
    T retiraEspecifico(T dado);
};

#include "ListaSE.cpp"


#endif // !LISTA_SE_H
