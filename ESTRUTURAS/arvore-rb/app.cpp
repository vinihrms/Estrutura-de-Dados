#include "Arvore.hpp"
#include <iostream>

void imprimir(NoBinario<int> *arvore, int tipo)
{
    if (tipo == 1)
    {
        arvore->preOrdem(arvore);
        std::cout << "Pré ordem: \n";

    }
    else if (tipo == 2)
    {
        arvore->emOrdem(arvore);
        std::cout << "Em ordem: \n";
    }
    else
    {
        arvore->posOrdem(arvore);
        std::cout << "Pós ordem: \n";
    }

    auto vetor = arvore->getElementos();

    for (std::size_t i = 0; i < arvore->getQuantidadeElementos(); ++i)
    {
        std::cout << *vetor[i].getDado() << " ";
    }

    std::cout << "\n";
}

// para testar recoloração da árvore
void recolorir()
{
    NoBinario<int> *arvore = new NoBinario<int>(10);

    arvore->inserir(5, arvore);
    arvore->inserir(15, arvore);
    arvore->inserir(3, arvore);

    
    for(int i = 1; i <= 3; i++){
        imprimir(arvore, i);
    }

    // boas praticas kkkkkkk
    arvore->~NoBinario();
}

void rotacaoSimples()
{
    NoBinario<int> *arvore = new NoBinario<int>(10);
    arvore->inserir(8, arvore);
    arvore->inserir(5, arvore);

    for(int i = 1; i <= 3; i++){
        imprimir(arvore, i);
    }

    // boas praticas kkkkkkk
    arvore->~NoBinario();
}

void rotacaoDupla()
{
    NoBinario<int> *arvore = new NoBinario<int>(10);
    arvore->inserir(5, arvore);
    arvore->inserir(8, arvore);

    for(int i = 1; i <= 3; i++){
        imprimir(arvore, i);
    }

    // boas praticas kkkkkkk
    arvore->~NoBinario();
}

void tudo()
{
    NoBinario<int> *arvore = new NoBinario<int>(10);
    arvore->inserir(20, arvore);
    arvore->inserir(30, arvore);
    arvore->inserir(40, arvore);
    arvore->inserir(50, arvore);
    arvore->inserir(60, arvore);
    arvore->inserir(70, arvore);
    arvore->inserir(80, arvore);

    for(int i = 1; i <= 3; i++){
        imprimir(arvore, i);
    }

    // boas praticas kkkkkkk
    arvore->~NoBinario();
}

int main()
{

    bool fim = false;

    do
    {
        unsigned int opcao;
        std::cout << "Digite uma opcao:\n[1] Recolorir\n[2] Rotação simples\n[3] Rotação dupla\n[4] Tudo\n[0] Fim\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 0:
            fim = true;
            break;
        case 1:
            recolorir();
            break;
        case 2:
            rotacaoSimples();
            break;
        case 3:
            rotacaoDupla();
            break;
        case 4:
            tudo();
            break;
        default:
            std::cout << "Opção inválida!!\n";
            break;
        }
    } while (fim == false);

    return 0;
}