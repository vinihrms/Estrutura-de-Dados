#include "desenvolvedor.h"
#include <iostream>
using namespace std;

void Desenvolvedor::setLP(string lp){
    LP = lp;
}
string Desenvolvedor::getLP(){
    return LP;
}
void Desenvolvedor::prepararCodigo(){
    cout << getNome() << " está codando na linguagem de programação: " << LP << endl;
}
Desenvolvedor::Desenvolvedor(string nome, int idade, string organizacao, string lp):Trabalhador(nome, idade, organizacao){
    LP = lp;
}

void Desenvolvedor::Trabalho(){
    cout << getNome() << " esta desenvolvendo em " << LP <<".\n";
}


