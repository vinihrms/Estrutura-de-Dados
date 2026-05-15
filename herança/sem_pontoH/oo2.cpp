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
        Trabalhador(string nome, int idade, string organizacao);
};

    void Trabalhador::setNome(string nome){
        Nome = nome;
    }
        string Trabalhador::getNome(){
            return Nome;
        }
///////////////////////////////////////////////////////////////////
        void Trabalhador::setIdade(int idade){
            Idade = idade;
        }
        int Trabalhador::getIdade(){
            return Idade;
        }
//////////////////////////////////////////////////////////////////
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
        

        /*   
        Trabalhador::Trabalhador(){
            Nome = "Sem nome";
            Idade = 0;
            Organizacao = "Sem organizacao";
        }
        */



int main(){

    Trabalhador t1("JoaoPedro", 20, "Estudante");
    Trabalhador t2("SemNome", 0, "SemOrganizacao");

    t1.apresenteSe();
    t2.apresenteSe();

    cout << endl;

    t2.setNome("LucasW");
    t2.setIdade(21);
    t2.setOrganizacao("Unioeste");

    t2.apresenteSe();

    return 0;
}