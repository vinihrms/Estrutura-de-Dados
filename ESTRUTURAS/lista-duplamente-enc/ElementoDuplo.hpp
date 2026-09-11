#ifndef ELEMENTODUPLO_H
#define ELEMENTODUPLO_H

template<typename T>
class ElementoDuplo{
private:
    ElementoDuplo<T> *_proximo;
    ElementoDuplo<T> *_anterior;
    T _info;
public:
    ElementoDuplo();
    ~ElementoDuplo();

    ElementoDuplo<T>* GetProximo();
    ElementoDuplo<T>* GetAnterior();
    T GetInfo();
    void SetProximo(ElementoDuplo<T> *proximo);
    void SetAnterior(ElementoDuplo<T> *anterior);
    void SetInfo(T info);

};

#include "ElementoDuplo.cpp"
#endif // !ELEMENTODUPLO_H
