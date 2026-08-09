#include "FilaEnc.hpp"

template<typename T>
FilaEnc<T>::FilaEnc(){
    _dados = nullptr;
    _fim = nullptr;
    _tamanho = 0;
}

template<typename T>
FilaEnc<T>::~FilaEnc(){
    destroiFila();
}

template<typename T>
bool FilaEnc<T>::filaVazia(){
    return _tamanho == 0;
}

template<typename T>
void FilaEnc<T>::adiciona(T dado){
    Elemento<T> *novo = new Elemento<T>;
    if(!novo){
        throw(ERRO_FILA_CHEIA);
    } else {
        if(filaVazia()){
            _dados = novo;
        } else {
        _fim->SetProximo(novo);
        }
        novo->SetProximo(nullptr);
        _fim = novo;
        _tamanho += 1;
    }
}

template<typename T>
T FilaEnc<T>::retira(){
    if(filaVazia()){
        throw(ERRO_FILA_VAZIA);
    } else {
        T volta;
        Elemento<T> saiu;
        saiu = _dados;
        volta = saiu->GetInfo();
        _dados = saiu->GetProximo();

        if(_tamanho == 1){
            _fim = nullptr;
        }

        _tamanho -= 1;
        delete(saiu);
        return volta;
    }
}


