#ifndef GRAFO_MATRIZ_HPP
#define GRAFO_MATRIZ_HPP

#define MAX_VERTICES 100

using TipoValorVertice = int;
using TipoPeso = int;
using TipoApontador = int;

class Grafo
{
private:
    TipoPeso Matriz[MAX_VERTICES][MAX_VERTICES];
    int N_Vertices;
    int N_Arestas;

public:

    explicit Grafo(int numero_vertices);
    ~Grafo() = default;

    void insereAresta(TipoValorVertice*v1, TipoValorVertice *v2,
                        TipoPeso *peso); 
                        
    bool existeAresta(TipoValorVertice v1, TipoValorVertice v2);

    bool listaAdjVazia(TipoValorVertice *i);

    TipoApontador primeiroListaAdj(TipoValorVertice *v);

    void proxAdj(TipoValorVertice *v, TipoValorVertice *adj, TipoPeso *p,
                        TipoApontador *prox, short *fimListaAdj);
                        
    void retiraAresta( TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p);

    void imprimeGrafo();
};

#include "grafo_matriz.cpp"
#endif // !GRAFO_MATRIZ_HPP
