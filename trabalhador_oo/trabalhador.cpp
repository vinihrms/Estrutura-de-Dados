#include <iostream>
#include <string>
#include "trabalhador.h"

using namespace std;

Trabalhador::Trabalhador(string nome, int idade, string organizacao)
{
    Nome = nome;
    Idade = idade;
    Organizacao = organizacao;
}

void Trabalhador::SetNome(string nome){
    Nome = nome;
}
string Trabalhador::GetNome()
{
    return Nome;
}
void Trabalhador::SetIdade(int idade)
{
    Idade = idade;
}
int Trabalhador::GetIdade()
{
    return Idade;
}
void Trabalhador::SetOrganizacao(string organizacao)
{
    Organizacao = organizacao;
}
string Trabalhador::GetOrganizacao()
{
    return Organizacao;
}

void Trabalhador::ApresenteSe()
{
    cout << "Nome: " << GetNome() << endl;
    cout << "Idade: " << GetIdade() << endl;
    cout << "Organização: " << GetOrganizacao() << endl;
}


