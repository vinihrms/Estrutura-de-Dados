#include <iostream>
#include "ListaSE.h"

using namespace std;

int main(){
  Lista<int> li;
  li.adicionaNoInicio(1);
  li.adicionaNoInicio(2);
  li.adicionaNoInicio(3);
  cout << "Lista\n";
  cout << li.retiraDoInicio() << "\n";
  cout << li.retiraDoInicio() << "\n";
  cout << li.retiraDoInicio() << "\n";
  return 0; 
}
