#include "ListaCircularDupla.hpp"
#include <stdio.h>

using namespace std;

template<typename T>
ListaCircularDupla<T>::ListaCircularDupla()
{
    _dados = nullptr;
    _tamanho = 0;
}

template<typename T>
ListaCircularDupla<T>::~ListaCircularDupla()
{
}

template<typename T>
bool ListaCircularDupla<T>::listaVazia()
{
    return (_tamanho == 0);
}

template<typename T>
T ListaCircularDupla<T>::getUltimo()
{
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }

    return _dados->GetAnterior()->GetInfo();
}


template<typename T>
void ListaCircularDupla<T>::adicionaNoInicio(T dado)
{
    ElementoDuplo<T> *aux = new ElementoDuplo<T>;
    if (aux == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }
    aux->SetInfo(dado);

    if (listaVazia())
    {
        // ligando nele mesmo o próximo e o anterior
        aux->SetProximo(aux);
        aux->SetAnterior(aux);
        _dados = aux;
    }
    else
    {

        // agora, como o primeiro liga nele mesmo, a cada inserção ele ligará no último (anteior do pronteiro para dados {que aponta para o fim})
        ElementoDuplo<T> *ultimo = _dados->GetAnterior();

        aux->SetProximo(_dados);
        aux->SetAnterior(ultimo);
        ultimo->SetProximo(aux);
        _dados->SetAnterior(aux);
        _dados = aux;
    }

    _tamanho++;
}

template<typename T>
T ListaCircularDupla<T>::retiraDoInicio()
{
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }
    else
    {
        ElementoDuplo<T> *aux = _dados;
        T volta = aux->GetInfo();

        if (_tamanho == 1)
        {
            _dados = nullptr;
        }
        else
        {
            // novo inicio = proximo de _dados (proximo do inicio)
            ElementoDuplo<T> *novoInicio = aux->GetProximo();

            // guarda o fim da lista (anterior do inicio = anterior de _dados)
            ElementoDuplo<T> *ultimo = aux->GetAnterior();

            ultimo->SetProximo(novoInicio);
            novoInicio->SetAnterior(ultimo);
            _dados = novoInicio;
        }

        _tamanho--;
        delete aux;
        return volta;
    }
}

template<typename T>
void ListaCircularDupla<T>::adicionaNaPosicao(T dado, int posicao)
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
T ListaCircularDupla<T>::retiraDaPosicao(int posicao)
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
void ListaCircularDupla<T>::adicionaEmOrdem(T dado)
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
int ListaCircularDupla<T>::posicao(T dado)
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
bool ListaCircularDupla<T>::contem(T dado)
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
void ListaCircularDupla<T>::adiciona(T dado)
{
    ElementoDuplo<T> *novo = new ElementoDuplo<T>;
    if (novo == nullptr)
    {
        throw(ERRO_LISTA_CHEIA);
    }

    novo->SetInfo(dado);

    if (listaVazia())
    {
        novo->SetProximo(novo);
        novo->SetAnterior(novo);
        _dados = novo;
    }
    else
    {
        ElementoDuplo<T> *ultimo = _dados->GetAnterior();

        novo->SetProximo(_dados);
        novo->SetAnterior(ultimo);
        ultimo->SetProximo(novo);
        _dados->SetAnterior(novo);
    }

    _tamanho++;
}

template<typename T>
T ListaCircularDupla<T>::retira()
{
    return retiraDaPosicao(_tamanho);
}

template<typename T>
T ListaCircularDupla<T>::retiraEspecifico(T dado)
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
void ListaCircularDupla<T>::limpaLista(){
    while (!listaVazia())
    {
        retiraDoInicio();
    }
}
