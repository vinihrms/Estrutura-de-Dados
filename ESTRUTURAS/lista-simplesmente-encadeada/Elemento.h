#ifndef ELEMENTO_H
#define ELEMENTO_H

template<typename T>
class Elemento{
private:
    Elemento<T> *_proximo;
    T _info;
public:
    Elemento<T>();
    ~Elemento<T>();

    Elemento<T>* GetProximo();
    T GetInfo();
    void SetProximo(Elemento<T> *proximo);
    void SetInfo(T info);

};

#include "Elemento.cpp"
#endif // !ELEMENTO_H
