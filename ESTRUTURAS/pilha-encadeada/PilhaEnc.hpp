#ifndef PILHAENC_H
#define PILHAENC_H

#define ERRO_PILHA_CHEIA 0
#define ERRO_PILHA_VAZIA 1
#include "Elemento.hpp"

template<typename T>
class PilhaEnc{
private:
    Elemento<T> *_dados;
    int _tamanho;

public:
    PilhaEnc();
    ~PilhaEnc();
    bool pilhaVazia();
    void empilha(T dado);
    T desempilha();
    T topo();


};

#include "PilhaEnc.cpp"

#endif // !PILHAENC_H
