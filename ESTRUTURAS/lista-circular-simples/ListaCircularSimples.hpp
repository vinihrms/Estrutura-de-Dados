#ifndef LISTA_CIRCULAR_SIMPLES
#define LISTA_CIRCULAR_SIMPLES

#include "Elemento.hpp"

#define ERRO_LISTA_CHEIA 0
#define ERRO_LISTA_VAZIA 1
#define ERRO_POSICAO 2
#define ERRO_NAO_CONTEM 3



template<typename T>
class ListaCircularSimples{
private:
    Elemento<T> *_dados;
    int _tamanho;

public:
    ListaCircularSimples(); //
    void limpaLista();
    ~ListaCircularSimples(); //

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

#include "ListaCircularSimples.cpp"


#endif // !LISTA_CIRCULAR_SIMPLES
