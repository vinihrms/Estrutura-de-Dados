#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "trabalhador.h"

class Professor: public Trabalhador{
    private:
        string Assunto;
    public:
        void setAssunto(string assunto);
        string getAssunto();
        void prepararAula();
        Professor(string nome, int idade, string organizacao, string assunto);
        void Trabalho();
};

#endif