#include <iostream>
#include <string>
#include "trabalhador.h"

using namespace std;

void Trabalhador::setNome(string nome){
    Nome = nome;
}
string Trabalhador::getNome(){
    return Nome;
}
/////////////////////////////////////////////////////////////////
void Trabalhador::setIdade(int idade){
    Idade = idade;
}
int Trabalhador::getIdade(){
    return Idade;
}
////////////////////////////////////////////////////////////////
void Trabalhador::setOrganizacao(string organizacao){
    Organizacao = organizacao;
}
string Trabalhador::getOrganizacao(){
    return Organizacao;
}
void Trabalhador::apresenteSe(){
    cout << "Nome: " << getNome() << "\t";
    cout << "Idade: " << getIdade() << "\t";
    cout << "Organizacao: " << getOrganizacao() << "\t" <<endl;
}

Trabalhador::Trabalhador(string nome, int idade, string organizacao){
    Nome = nome;
    Idade = idade;
    Organizacao = organizacao;

}

Trabalhador::Trabalhador(){
    Nome = "SemNome";
    Idade = -1;
    Organizacao = "SemOrganizacao";
}

void Trabalhador::Trabalho(){
    cout << Nome << " está fazendo relatórios.\n";
}