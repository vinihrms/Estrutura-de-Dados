#include "ListaSE.h"
#include <stdio.h>

template <typename T>
Lista<T>::Lista()
{
    _dados = nullptr;
    _tamanho = 0;
}

template <typename T>
Lista<T>::~Lista()
{
    destroiLista();
}

template <typename T>
bool Lista<T>::listaVazia()
{
    if (_tamanho == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void Lista<T>::adicionaNoInicio(T dado)
{
    Elemento<T> *aux;
    aux = new Elemento;
    if (aux == NULL)
    {
        throw(ERRO_LISTA_CHEIA);
    }
    else
    {
        aux->_proximo = _dados;
        aux->_info = dado;
        _dados = aux;
        _tamanho++;
    }
}

template <typename T>
T Lista<T>::retiraDoInicio()
{
    Elemento<T> *aux;
    T volta;
    if (listaVazia())
    {
        throw(ERRO_LISTA_VAZIA);
    }
    else
    {
        aux = _dados;
        volta = aux->_info;
        _dados = aux->_proximo;
        _tamanho--;
        delete (aux);
        return volta;
    }
}

template <typename T>
void Lista<T>::adicionaNaPosicao(T dado, int posicao)
{
    Elemento<T> *novo;
    Elemento<T> *anterior;

    if (posicao > _tamanho + 1 || posicao < 1)
    {
        throw(ERRO_POSICAO);
    }
    else
    {
        if (posicao == 1)
        {
            return adicionaNoInicio(dado);
        }
        else
        {
            novo = new Elemento;
            if (novo == NULL)
            {
                throw(ERRO_LISTA_CHEIA);
            }
            else
            {
                anterior = _dados;
                for (int i = 0; i < posicao - 2; i++)
                {
                    anterior = anterior->_proximo;
                }
                novo->_proximo = anterior->_proximo;
                novo->_info = dado;
                anterior->_proximo = novo;
                _tamanho += 1;
            }
        }
    }
}

template <typename T>
T Lista<T>::retiraDaPosicao(int posicao)
{
    if (posicao > _tamanho || posicao < 1)
    {
        throw(ERRO_POSICAO);
    }
    else
    {
        if (posicao == 1)
        {
            return retiraDoInicio();
        }
        else
        {
            Elemento<T> *anterior;
            Elemento<T> *eliminar;
            T volta;
            anterior = _dados;
            for (int i = 0; i < posicao - 2; i++)
            {
                anterior = anterior->_proximo;
            }

            eliminar = anterior->_proximo;

            // volta = anterior->_proximo->_info
            volta = eliminar->_info;

            // anterior->_proximo = anterior->_proximo->_proximo;
            anterior->_proximo = eliminar->_proximo;

            _tamanho -= 1;
            delete (eliminar);
            return volta;
        }
    }
}

template<typename T>
void Lista<T>::adicionaEmOrdem(T dado){
    Elemento<T> *atual;
    int posicao;

    if(listaVazia()){
        return adicionaNoInicio(dado);
    } else {
        atual = _dados;
        posicao = 1;
        while(atual->_proximo != nullptr && dado > atual->_info){
            atual = atual->_proximo;
            posicao += 1;
        }

        if(dado > atual->_info){
            return adicionaNaPosicao(dado, posicao + 1);
        } else {
            adicionaNaPosicao(dado, posicao);
        }
    }
}


template<typename T>
int Lista<T>::posicao(T dado){
    if(listaVazia()){
        throw(ERRO_LISTA_VAZIA);
    } else {
        Elemento<T> *atual;

        atual = _dados;

        for(int i = 0; i < _tamanho; i++){
            if(atual->_info == dado){
                return i + 1;
            }
            atual = atual->_proximo;
        }

        throw(ERRO_NAO_CONTEM);
    }
}

template<typename T>
bool Lista<T>::contem(T dado){
    if(listaVazia()){
        throw(ERRO_LISTA_VAZIA);
    } else {
        Elemento<T> *atual;

        atual = _dados;

        for(int i = 0; i < _tamanho; i++){
            if(atual->_info == dado){
                return true;
            }
            atual = atual->_proximo;
        }

        return false;
    }
}


template<typename T>
void Lista<T>::adiciona(T dado){
    return adicionaNaPosicao(dado, _tamanho + 1);
}

template<typename T>
T Lista<T>::retira(){
    return retiraDaPosicao(_tamanho);
}

template<typename T>
T Lista<T>::retiraEspecifico(T dado){
    if(contem(dado)){
        return retiraDaPosicao(posicao(dado));
    } else {
        throw(ERRO_NAO_CONTEM);
    }
}

template<typename T>
void Lista<T>::limpaLista(){
    if(listaVazia()){
        throw(ERRO_LISTA_VAZIA);
    } else {
        while (!listaVazia()) {
            retira();
        }
    }
}

template<typename T>
void Lista<T>::destroiLista(){
    Elemento<T> *atual;
    Elemento<T> *anterior;
    atual = _dados;
    while (atual != nullptr){
        anterior = atual;
        atual = atual->_proximo;
        delete(anterior);
    }
}