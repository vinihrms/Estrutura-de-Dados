#include "PilhaEnc.hpp"


template<typename T>
PilhaEnc<T>::PilhaEnc(){
    _dados = nullptr;
    _tamanho = 0;
}

template<typename T>
PilhaEnc<T>::~PilhaEnc(){
    destroiPilha();
}

template<typename T>
bool PilhaEnc<T>::pilhaVazia(){
    return _tamanho == 0;
}


template<typename T>
void PilhaEnc<T>::empilha(T dado){
    Elemento<T> *novo = new Elemento<T>();
    if(!novo){
        throw(ERRO_PILHA_CHEIA);
    } else{
        novo->SetInfo(dado);
        novo->SetProximo(_dados);
        _dados = novo;
        _tamanho += 1;
    }
}


template<typename T>
T PilhaEnc<T>::desempilha(){
    if(pilhaVazia()){
        throw(ERRO_PILHA_VAZIA);
    } else {
        _tamanho -= 1;
        T volta;
        Elemento<T> *saiu = _dados;
        volta = saiu->GetInfo();

        _dados = saiu->GetProximo();
        delete(saiu);
        return(volta);
    }
}


template<typename T>
T PilhaEnc<T>::topo(){
    if(pilhaVazia()){
        throw(ERRO_PILHA_VAZIA);
    } else {
        return _dados->GetInfo(); 
    }
}