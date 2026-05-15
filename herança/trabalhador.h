#ifndef TRABALHADOR_H
#define TRABALHADOR_H

#include <iostream>
#include <string>

using namespace std;

class Trabalhador{

    private: 
        string Nome;
        int Idade;
        string Organizacao;

    public:
        void setNome(string nome);
        string getNome();
        void setIdade(int idade);
        int getIdade();
        void setOrganizacao(string organizacao);
        string getOrganizacao();
        void apresenteSe();
        Trabalhador();
        Trabalhador(string nome, int idade, string organizacao);
        void Trabalho();
};

#endif
