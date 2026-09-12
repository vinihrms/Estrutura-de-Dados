#ifndef LISTA_CIRCULAR_DUPLA
#define LISTA_CIRCULAR_DUPLA

#include "ElementoDuplo.hpp"

#define ERRO_LISTA_CHEIA 0
#define ERRO_LISTA_VAZIA 1
#define ERRO_POSICAO 2
#define ERRO_NAO_CONTEM 3

template<typename T>
class ListaCircularDupla{
private:
    ElementoDuplo<T> *_dados;
    int _tamanho;

public:
    ListaCircularDupla(); //
    void limpaLista();
    ~ListaCircularDupla(); //

    bool listaVazia(); //
    int posicao(T dado); //
    bool contem(T dado); //
    T getUltimo();

    void adiciona(T dado);
    void adicionaNoInicio(T dado); //
    void adicionaNaPosicao(T dado, int posicao); //
    void adicionaEmOrdem(T dado); //

    T retira(); //
    T retiraDoInicio(); //
    T retiraDaPosicao(int posicao); //
    T retiraEspecifico(T dado);

};

#include "ListaCircularDupla.cpp"


#endif // !LISTA_CIRCULAR_DUPLA
