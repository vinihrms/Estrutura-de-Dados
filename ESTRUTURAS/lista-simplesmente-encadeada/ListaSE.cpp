#include "ListaSE.h"
#include <stdio.h>

using namespace std;

template<typename T>
Lista<T>::Lista()
{
    _dados = nullptr;
    _tamanho = 0;
}

template<typename T>
Lista<T>::~Lista()
{
    destroiLista();
}

template<typename T>
bool Lista<T>::listaVazia()
{
    return (_tamanho == 0);
}

template<typename T>
void Lista<T>::adicionaNoInicio(T dado)
{
    Elemento<T> *aux = new Elemento<T>;
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
T Lista<T>::retiraDoInicio()
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
void Lista<T>::adicionaNaPosicao(T dado, int posicao)
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
T Lista<T>::retiraDaPosicao(int posicao)
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
void Lista<T>::adicionaEmOrdem(T dado)
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
int Lista<T>::posicao(T dado)
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
bool Lista<T>::contem(T dado)
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
void Lista<T>::adiciona(T dado)
{
    return adicionaNaPosicao(dado, _tamanho + 1);
}

template<typename T>
T Lista<T>::retira()
{
    return retiraDaPosicao(_tamanho);
}

template<typename T>
T Lista<T>::retiraEspecifico(T dado)
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
void Lista<T>::limpaLista(){
    while (!listaVazia())
    {
        retiraDoInicio();
    }
}

template<typename T>
void Lista<T>::destroiLista()
{
    Elemento<T> *atual = _dados;
    while (atual != nullptr)
    {
        Elemento<T> *proximo = atual->GetProximo();
        delete atual;
        atual = proximo;
    }
    _dados = nullptr;
    _tamanho = 0;
}
