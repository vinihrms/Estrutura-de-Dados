#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class Elemento{
private:
    Elemento<T> *_proximo;
    T _info;
public:
    Elemento();
    ~Elemento();

    Elemento<T>* GetProximo();
    T GetInfo();
    void SetProximo(Elemento<T> *proximo);
    void SetInfo(T info);

};

#include "Elemento.cpp"
#endif // !ELEMENTO_HPP
