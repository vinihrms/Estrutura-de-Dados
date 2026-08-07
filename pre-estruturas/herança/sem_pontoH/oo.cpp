#include <iostream>
#include <string>

using namespace std;

class Trabalhador{

    private: 
        string Nome;
        int Idade;
        string Organizacao;

    public:

        void setNome(string nome){

            Nome = nome;
        }
        string getNome(){
            return Nome;
        }
///////////////////////////////////////////////////////////////////
        void setIdade(int idade){
            Idade = idade;
        }
        int getIdade(){
            return Idade;
        }
//////////////////////////////////////////////////////////////////
        void setOrganizacao(string organizacao){
            Organizacao = organizacao;
        }
        string getOrganizacao(){
            return Organizacao;
        }

        void apresenteSe(){
            cout << "Nome: " << getNome() << "\t";
            cout << "Idade: " << getIdade() << "\t";
            cout << "Organizacao: " << getOrganizacao() << "\t" <<endl;
        }
        
        Trabalhador(string nome, int idade, string organizacao){
            Nome = nome;
            Idade = idade;
            Organizacao = organizacao;
        }
        

        /*   
        Trabalhador(){
            Nome = "Sem nome";
            Idade = 0;
            Organizacao = "Sem organizacao";
        }
        */
};



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