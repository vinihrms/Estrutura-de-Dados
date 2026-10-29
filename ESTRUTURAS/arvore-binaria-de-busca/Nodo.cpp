#include "Nodo.hpp"

template<typename T>
Nodo<T>::Nodo(T dado){
    _filhoEsq = nullptr
    _filhoDir = nullptr
    _info = dado;
}

template<typename T>
Nodo<T>::~Nodo(){
    
}

template<typename T>
Nodo<T>* criaArvore(int qtd){
    int esq, dir;
    T *info;
    Nodo *novo;

    if(qtd == 0){
        return NULL;
    }

    esq = qtd / 2;
    dir = qtd - esq - 1;

    info = new T;


}