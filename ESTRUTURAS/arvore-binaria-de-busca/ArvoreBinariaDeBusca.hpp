#ifndef ARVORE_BINARIA_DE_BUSCA_HPP
#define ARVORE_BINARIA_DE_BUSCA_HPP

#include "Nodo.hpp"

template<typename T>
class ArvoreBinariaDeBusca{
private:
    Nodo<T> *_raiz;

public:
    ArvoreBinariaDeBusca();

    void insere(T dado);
    void escreveEmOrdem(Nodo<T>* atual);

};


#endif // ARVORE_BINARIA_DE_BUSCA_HPP