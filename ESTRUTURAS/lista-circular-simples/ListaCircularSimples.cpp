#include "ListaCircularSimples.hpp"
#include <stdio.h>

using namespace std;

template<typename T>
ListaCircularSimples<T>::ListaCircularSimples()
{
    _dados = new Elemento<T>;

    if (_dados == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }

    _dados->SetProximo(_dados);

    _tamanho = 0;
}

template<typename T>
ListaCircularSimples<T>::~ListaCircularSimples()
{
    
}

template<typename T>
bool ListaCircularSimples<T>::listaVazia()
{
    return (_tamanho == 0);
}

template<typename T>
void ListaCircularSimples<T>::adicionaNoInicio(T dado)
{
    Elemento<T> *aux = new Elemento<T>;
    if (aux == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }
    else
    {
        aux->SetInfo(dado);
        aux->SetProximo(_dados->GetProximo());
        _dados->SetProximo(aux);
        _tamanho++;
    }
}

template<typename T>
T ListaCircularSimples<T>::retiraDoInicio()
{
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }
    else
    {
        Elemento<T> *aux = _dados;
        T volta = aux->GetInfo();
        _dados = aux->GetProximo();
        _tamanho--;
        delete aux;
        return volta;
    }
}

template<typename T>
void ListaCircularSimples<T>::adicionaNaPosicao(T dado, int posicao)
{
    if (posicao > _tamanho + 1 || posicao < 1)
    {
        throw(ERRO_POSICAO);
    }

    if (posicao == 1)
    {
        return adicionaNoInicio(dado);
    }

    Elemento<T> *novo = new Elemento<T>;
    if (novo == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }

    novo->SetInfo(dado);

    Elemento<T> *anterior = _dados;
    for (int i = 1; i < posicao - 1; i++)
    {
        anterior = anterior->GetProximo();
    }

    novo->SetProximo(anterior->GetProximo());
    anterior->SetProximo(novo);
    _tamanho++;
}

template<typename T>
T ListaCircularSimples<T>::retiraDaPosicao(int posicao)
{
    if (posicao > _tamanho || posicao < 1)
    {
        throw(ERRO_POSICAO);
    }

    if (posicao == 1)
    {
        return retiraDoInicio();
    }

    Elemento<T> *anterior = _dados;
    for (int i = 1; i < posicao - 1; i++)
    {
        anterior = anterior->GetProximo();
    }

    Elemento<T> *eliminar = anterior->GetProximo();
    T volta = eliminar->GetInfo();

    anterior->SetProximo(eliminar->GetProximo());
    delete eliminar;
    _tamanho--;

    return volta;
}

template<typename T>
void ListaCircularSimples<T>::adicionaEmOrdem(T dado)
{
    if (listaVazia())
    {
        return adicionaNoInicio(dado);
    }

    Elemento<T> *atual = _dados;
    int posicao = 1;

    while (atual != nullptr && dado > atual->GetInfo())
    {
        atual = atual->GetProximo();
        posicao++;
    }

    adicionaNaPosicao(dado, posicao);
}

template<typename T>
int ListaCircularSimples<T>::posicao(T dado)
{
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }

    Elemento<T> *atual = _dados;
    for (int i = 0; i < _tamanho; i++)
    {
        if (atual->GetInfo() == dado)
        {
            return i + 1;
        }
        atual = atual->GetProximo();
    }

    throw(ERRO_NAO_CONTEM);
}

template<typename T>
bool ListaCircularSimples<T>::contem(T dado)
{
    if (listaVazia())
    {
        return false;
    }

    Elemento<T> *atual = _dados;
    while (atual != nullptr)
    {
        if (atual->GetInfo() == dado)
        {
            return true;
        }
        atual = atual->GetProximo();
    }

    return false;
}

template<typename T>
void ListaCircularSimples<T>::adiciona(T dado)
{
    return adicionaNaPosicao(dado, _tamanho + 1);
}

template<typename T>
T ListaCircularSimples<T>::retira()
{
    return retiraDaPosicao(_tamanho);
}

template<typename T>
T ListaCircularSimples<T>::retiraEspecifico(T dado)
{
    if (contem(dado))
    {
        return retiraDaPosicao(posicao(dado));
    }
    else
    {
        throw(ERRO_NAO_CONTEM);
    }
}

template<typename T>
void ListaCircularSimples<T>::limpaLista(){
    while (!listaVazia())
    {
        retiraDoInicio();
    }
}
