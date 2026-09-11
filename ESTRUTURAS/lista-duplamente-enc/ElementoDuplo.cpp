#ifndef _ELEMENTO_DUPLO_CPP
#define _ELEMENTO_DUPLO_CPP

#include "ElementoDuplo.hpp"

using namespace std;


template<typename T>
ElementoDuplo<T>::ElementoDuplo(){
    _proximo = nullptr;
}

template<typename T>
ElementoDuplo<T>::~ElementoDuplo(){
}

template<typename T>
ElementoDuplo<T>* ElementoDuplo<T>::GetProximo(){
  return _proximo;
}

template<typename T>
ElementoDuplo<T>* ElementoDuplo<T>::GetAnterior(){
  return _anterior;
}

template<typename T>
T ElementoDuplo<T>::GetInfo(){
    return _info;
}

template<typename T>
void ElementoDuplo<T>::SetProximo(ElementoDuplo<T>* proximo){
    _proximo = proximo;
}

template<typename T>
void ElementoDuplo<T>::SetInfo(T info){
    _info = info;
}
template<typename T>
void ElementoDuplo<T>::SetAnterior(ElementoDuplo<T>* anterior){
    _anterior = anterior;
}


#endif
