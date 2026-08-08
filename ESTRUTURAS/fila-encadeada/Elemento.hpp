#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class Elemento
{
private:
    Elemento<T> *_proximo;
    T _info;
public:
    Elemento();
    ~Elemento();

    Elemento<T> *GetProximo();
    void SetProximo(Elemento<T> *proximo);

    T GetInfo();
    void SetInfo(T dado);
};



#include "Elemento.h"
#endif // !ELEMENTO_HPP
