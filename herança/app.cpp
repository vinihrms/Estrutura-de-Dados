#include <iostream>
#include <string>
#include "trabalhador.h"
#include "professor.h"
#include "desenvolvedor.h"

using namespace std;

int main(){

    Trabalhador* t1 = new Trabalhador();
    Professor* p1 = new Professor("Josue", 15, "Unioeste", "Algoritimossssssssss");
    t1->apresenteSe();
    p1->apresenteSe();
    p1->prepararAula();
    t1->Trabalho();
    p1->Trabalho();



    /*
    Trabalhador t1("JoaoPedro", 20, "Estudante");
    Professor p1("Jesus", 36, "Unioeste", "Calculo");
    Trabalhador t2("SemNome", 0, "SemOrganizacao");
    Trabalhador *t3 = new Trabalhador("Leonardo", 42, "Professor");
    Desenvolvedor d1("Fabio Akita", 45, "USP", "Python");

    t1.apresenteSe();
    t2.apresenteSe();

    cout << endl;

    t2.setNome("LucasW");
    t2.setIdade(21);
    t2.setOrganizacao("Unioeste");

    t2.apresenteSe();

    cout << endl;

    t3->apresenteSe();
    t3->setNome("JosueCastro");
    t3->setIdade(50);
    t3->setOrganizacao("Doutor");
    
    cout << endl;

    t3->apresenteSe();

    cout<<endl;

    p1.apresenteSe();
    p1.prepararAula();

    cout<<endl;

    d1.apresenteSe();
    d1.prepararCodigo();

    cout<<endl;

    */

    return 0;
}