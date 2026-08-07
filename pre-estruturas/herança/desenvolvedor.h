#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H

#include "trabalhador.h"

class Desenvolvedor:public Trabalhador{
    private:
        string LP;
    public:
        void setLP(string lp);
        string getLP();
        void prepararCodigo();
        Desenvolvedor(string nome, int idade, string organizacao, string lp);
        void Trabalho();
};

#endif