#include "professor.h"
#include <iostream>
using namespace std;

void Professor::setAssunto(string assunto){
    Assunto = assunto;
}
string Professor::getAssunto(){
    return Assunto;
}
void Professor::prepararAula(){
    cout << getNome() << " está preparando uma aula de: " << Assunto << endl;
}
//construtor
Professor::Professor(string nome, int idade, string organizacao, string assunto):Trabalhador(nome, idade, organizacao){
    Assunto = assunto;
}

void Professor::Trabalho(){
    cout << getNome() << " está orientando alunos para IC.\n";
}