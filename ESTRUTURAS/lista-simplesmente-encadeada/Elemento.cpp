#ifndef _ELEMENTO_CPP
#define _ELEMENTO_CPP

#include "Elemento.h"

using namespace std;


template<typename T>
Elemento<T>::Elemento(){
    _proximo = nullptr;
}

template<typename T>
Elemento<T>::~Elemento(){
}

template<typename T>
Elemento<T>* Elemento<T>::GetProximo(){
  return _proximo;
}

template<typename T>
T Elemento<T>::GetInfo(){
    return _info;
}

template<typename T>
void Elemento<T>::SetProximo(Elemento<T>* proximo){
    _proximo = proximo;
}

template<typename T>
void Elemento<T>::SetInfo(T info){
    _info = info;
}

#endif
