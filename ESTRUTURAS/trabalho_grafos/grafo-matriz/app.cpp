#include "grafo_matriz.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << endl;

    int a = 10;

    // *************** TESTE Grafo() *************** //

    Grafo *g = new Grafo(a);
    cout << "Grafo inicializado com " << a << " vértices!\n";

    // *************** TESTE imprimeGrafo() *************** //
    g->imprimeGrafo();

    cout << "Adicionando algumas arestas...\n";

    // neste caso adicionei na diagonal com um laço para fácil representacao visual
    // claro que pode ser adicionada manualmente conforme necessidade para o grafo

    for (TipoValorVertice i = 0; i < 10; i++)
    {
        TipoPeso a = 10 - i;

        // *************** TESTE insereAresta() *************** //
        g->insereAresta(&i, &i, &a);
    }

    // *************** TESTE imprimeGrafo() com arestas preenchidas *************** //

    cout << endl;

    cout << "Impressão do grafo atual, com arestas adicionadas!\n";
    g->imprimeGrafo();

    // *************** TESTE existeAresta() *************** //

    TipoValorVertice v1 = 9;
    TipoValorVertice v2 = 7;
    printf("Testando a aresta (%d, %d)...\n", v1, v2);
    if (g->existeAresta(v1, v2))
    {
        printf("Existe aresta (%d, %d)!\n", v1, v2);
    }
    else
    {
        printf("Não existe aresta (%d, %d)!\n", v1, v2);
    }

    printf("\n");

    v1 = 5;
    v2 = 5;
    printf("Testando a aresta (%d, %d)...\n", v1, v2);
    if (g->existeAresta(v1, v2))
    {
        printf("Existe aresta (%d, %d)!\n", v1, v2);
    }
    else
    {
        printf("Não existe aresta (%d, %d)!\n", v1, v2);
    }

    cout << endl;
    printf("Retirando a aresta (%d, %d)...\n", v1, v2);

    // *************** TESTE retiraAresta() *************** //

    TipoPeso j = 0;
    g->retiraAresta(&v1, &v1, &j);

    g->imprimeGrafo();

    printf("Aresta retirada, seu peso era: %d!\n", j);

    cout << endl;

    // *************** TESTE listaAdjVazia() *************** //

    TipoValorVertice i = 1;
    printf("Verificação de lista de adjacência para %d\n", i);

    if (g->listaAdjVazia(&i))
    {
        printf("Lista de adjacência para i = %d está vazia!\n", i);
    }
    else
    {
        printf("Lista de adjacência para i = %d está com item(s)!\n", i);
    }

    cout << endl;

    // é para dar vazio, removemos o 5, 5!
    i = 5;
    printf("Agora, verificação de lista de adjacência para %d...\n", i);

    if (g->listaAdjVazia(&i))
    {
        printf("Lista de adjacência para i = %d está vazia!\n", i);
    }
    else
    {
        printf("Lista de adjacência para i = %d está com item(s)!\n", i);
    }

    // *************** TESTE primeiroListaAdj() *************** //

    i = 4;

    printf("Testando adjacencia para o vertice %d...\n", i);

    if (g->listaAdjVazia(&i))
    {
        printf("O vertice %d nao possui adjacencias.\n", i);
    }
    else
    {
        TipoApontador primeiro = g->primeiroListaAdj(&i);
        printf("Primeira adjacencia: %d\n", primeiro);
    }


    TipoValorVertice teste1 = 4;
    TipoValorVertice teste2 = 1;

    printf("Adicionando uma nova adjacencia \"menor\" em (%d, %d)...\n", teste1, teste2);

    a = 77;

    g->insereAresta(&teste1, &teste2, &a);

    g->imprimeGrafo();


    if (g->listaAdjVazia(&i))
    {
        printf("O vertice %d nao possui adjacencias.\n", i);
    }
    else
    {
        TipoApontador primeiro = g->primeiroListaAdj(&i);
        printf("Primeira adjacencia: %d.\n", primeiro);
    }

    // *************** TESTE proxAdj() *************** //

    TipoValorVertice v = 4;
    TipoValorVertice adj;
    TipoPeso p;
    TipoApontador prox = g->primeiroListaAdj(&v);
    bool fimListaAdj = false;

    printf("\nPercorrendo as adjacencias do vertice %d...\n", v);

    while (!fimListaAdj)
    {
        g->proxAdj(&v, &adj, &p, &prox, &fimListaAdj);
        printf("Aresta: %d -> %d, peso: %d\n", v, adj, p);
    }

    cout << "Destruindo grafo...\n";
    // *************** TESTE ~Grafo() *************** //

    delete g;
}