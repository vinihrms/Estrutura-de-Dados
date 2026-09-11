#include "ArvoreBinariaDeBusca.hpp"

template <typename T>
ArvoreBinariaDeBusca<T>::ArvoreBinariaDeBusca()
{
    _raiz = nullptr;
}

template <typename T>
void ArvoreBinariaDeBusca<T>::insere(T dado)
{

    // raiz nula = não tem elementos
    if (_raiz == nullptr)
    {
        _raiz = new Nodo(dado);
        return;
    }

    Nodo<T> *atual = _raiz;

    while (true)
    {
        if (dado == atual->_info)
        {
            return;
        }
        if (dado > atual->_info)
        {
            if (atual->_filhoEsq != nullptr)
            {
                atual = atual->_filhoEsq;
            }
            else
            {
                atual->_filhoEsq = new Nodo<T>(dado);
                return;
            }
        }
        else if (dado > atual->_info)
        {
            if(atual->_filhoDir != nullptr){
                atual = atual->_filhoDir
            } else {
                atual->_filhoDir = new Nodo<t>(dado);
                return;
            }
        }
    }
}

template<typename T>
void ArvoreBinariaDeBusca<T>::escreveEmOrdem(Nodo<T>* atual){
    
}