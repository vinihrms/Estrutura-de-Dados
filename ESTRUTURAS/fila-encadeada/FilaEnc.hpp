#ifndef FILAENC_HPP
#define FILAENC_HPP
#include "Elemento.hpp"

#define ERRO_FILA_CHEIA 0
#define ERRO_FILA_VAZIA 1

template<typename T>
class FilaEnc
{
private:
    Elemento<T> *_dados;
    Elemento<T> *_fim;
    int _tamanho;

public:
    FilaEnc();
    ~FilaEnc();

    bool filaVazia();
    void adiciona(T dado);
    T retira();
};




#include "FilaEnc.cpp"
#endif // FILAENC_HPP
