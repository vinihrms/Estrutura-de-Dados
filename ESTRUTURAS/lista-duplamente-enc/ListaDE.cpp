#include "ListaDE.hpp"
#include <stdio.h>

using namespace std;

template<typename T>
ListaDupla<T>::ListaDupla()
{
    _dados = nullptr;
    _tamanho = 0;
}

template<typename T>
ListaDupla<T>::~ListaDupla()
{
    destroiLista();
}

template<typename T>
bool ListaDupla<T>::listaVazia()
{
    return (_tamanho == 0);
}

template<typename T>
void ListaDupla<T>::adicionaNoInicio(T dado)
{
    ElementoDuplo<T> *aux = new ElementoDuplo<T>;
    if (aux == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }
    else
    {
        aux->SetProximo(_dados);
        aux->SetInfo(dado);
        _dados = aux;
        _tamanho++;
    }
}

template<typename T>
T ListaDupla<T>::retiraDoInicio()
{
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }
    else
    {
        ElementoDuplo<T> *aux = _dados;
        T volta = aux->GetInfo();
        _dados = aux->GetProximo();
        _tamanho--;
        delete aux;
        return volta;
    }
}

template<typename T>
void ListaDupla<T>::adicionaNaPosicao(T dado, int posicao)
{
    if (posicao > _tamanho + 1 || posicao < 1)
    {
        throw(ERRO_POSICAO);
    }

    if (posicao == 1)
    {
        return adicionaNoInicio(dado);
    }

    ElementoDuplo<T> *novo = new ElementoDuplo<T>;
    if (novo == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }

    novo->SetInfo(dado);

    ElementoDuplo<T> *anterior = _dados;
    for (int i = 1; i < posicao - 1; i++)
    {
        anterior = anterior->GetProximo();
    }

    novo->SetProximo(anterior->GetProximo());
    anterior->SetProximo(novo);
    _tamanho++;
}

template<typename T>
T ListaDupla<T>::retiraDaPosicao(int posicao)
{
    if (posicao > _tamanho || posicao < 1)
    {
        throw(ERRO_POSICAO);
    }

    if (posicao == 1)
    {
        return retiraDoInicio();
    }

    ElementoDuplo<T> *anterior = _dados;
    for (int i = 1; i < posicao - 1; i++)
    {
        anterior = anterior->GetProximo();
    }

    ElementoDuplo<T> *eliminar = anterior->GetProximo();
    T volta = eliminar->GetInfo();

    anterior->SetProximo(eliminar->GetProximo());
    delete eliminar;
    _tamanho--;

    return volta;
}

template<typename T>
void ListaDupla<T>::adicionaEmOrdem(T dado)
{
    if (listaVazia())
    {
        return adicionaNoInicio(dado);
    }

    ElementoDuplo<T> *atual = _dados;
    int posicao = 1;

    while (atual != nullptr && dado > atual->GetInfo())
    {
        atual = atual->GetProximo();
        posicao++;
    }

    adicionaNaPosicao(dado, posicao);
}

template<typename T>
int ListaDupla<T>::posicao(T dado)
{
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }

    ElementoDuplo<T> *atual = _dados;
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
bool ListaDupla<T>::contem(T dado)
{
    if (listaVazia())
    {
        return false;
    }

    ElementoDuplo<T> *atual = _dados;
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
void ListaDupla<T>::adiciona(T dado)
{
    return adicionaNaPosicao(dado, _tamanho + 1);
}

template<typename T>
T ListaDupla<T>::retira()
{
    return retiraDaPosicao(_tamanho);
}

template<typename T>
T ListaDupla<T>::retiraEspecifico(T dado)
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
void ListaDupla<T>::limpaLista(){
    while (!listaVazia())
    {
        retiraDoInicio();
    }
}

template<typename T>
void ListaDupla<T>::destroiLista()
{
    ElementoDuplo<T> *atual = _dados;
    while (atual != nullptr)
    {
        ElementoDuplo<T> *proximo = atual->GetProximo();
        delete atual;
        atual = proximo;
    }
    _dados = nullptr;
    _tamanho = 0;
}
