#ifndef ELEMENTO_H
#define ELEMENTO_H

template<typename T>
class Elemento{
private:
    Elemento<T> *_proximo;
    T _info;
public:
    Elemento();
    ~Elemento();

    Elemento* GetProximo();
    T GetInfo();
    void SetProximo(Elemento<T> *proximo);
    void SetInfo(T dado);



};

#include "Elemento.cpp"
#endif // !ELEMENTO_H
