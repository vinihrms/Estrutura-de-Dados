#ifndef NODO_HPP
#define NODO_HPP

template<typename T>
class Nodo{
public:
    Nodo<T> *_filhoEsq;
    Nodo<T> *_filhoDir;
    T *_info;
    Nodo(T dado);
    ~Nodo();
    

    Nodo* criaArvore(int qtd);

};

#endif // !NODO_HPP