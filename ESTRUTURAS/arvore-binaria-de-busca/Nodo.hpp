#ifndef NODO_HPP
#define NODO_HPP

template<typename T>
class Nodo{
public:
    Nodo<T> *_filhoEsq;
    Novo<T> *_filhoDir;
    T *_info;
    Nodo(T dado);
    ~Nodo();
    
};

#endif // !NODO_HPP