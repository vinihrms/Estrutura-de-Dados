#include <iostream>
#include <string>

using namespace std;

class Trabalhador
{

private:
    string Nome;
    int Idade;
    string Organizacao;

public:
    Trabalhador(string nome, int idade, string organizacao);

    void SetNome(string nome);

    string GetNome();

    void SetIdade(int idade);

    int GetIdade();

    void SetOrganizacao(string organizacao);

    string GetOrganizacao();

    void ApresenteSe();
};