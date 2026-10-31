#include "grafo_matriz.hpp"
#include <iostream>

using namespace std;

Grafo::Grafo(int numero_vertices)
    : N_Vertices(numero_vertices), N_Arestas(0){
    for (int i = 0; i < numero_vertices; i++){
        for (int j = 0; j < numero_vertices; j++){
            Matriz[i][j] = 0;}}}

void Grafo::insereAresta(TipoValorVertice *v1, TipoValorVertice *v2,
                         TipoPeso *peso)
{
    if (v1 == nullptr || v2 == nullptr || peso == nullptr ||
        *v1 < 0 || *v1 >= N_Vertices ||
        *v2 < 0 || *v2 >= N_Vertices || *peso <= 0)
    {
        return;
    }

    if (this->Matriz[*v1][*v2] == 0)
    {
        ++N_Arestas;
    }

    this->Matriz[*v1][*v2] = *peso;
}

bool Grafo::existeAresta(TipoValorVertice v1, TipoValorVertice v2)
{
    if (this->Matriz[v1][v2] > 0)
    {
        return true;
    }

    return false;
}

bool Grafo::listaAdjVazia(TipoValorVertice *v)
{
    bool vazio = true;
    int j = 0;
    while (j < this->N_Vertices && vazio)
    {
        if (this->Matriz[*v][j] > 0)
        {
            return false;
        }
        else
        {
            j++;
        }
    }

    return true;
}

TipoApontador Grafo::primeiroListaAdj(TipoValorVertice *v)
{
    TipoApontador j = 0;
    bool vazio = true;

    while(j < this->N_Vertices && vazio)
    {
        if (this->Matriz[*v][j] > 0)
        {
            vazio = false;
        }
        else
        {
            j++;
        }
    }

    if(j == this->N_Vertices)
    {
        printf("ERRO: Lista adjacência vazia!\n");
    }

    return j;
}

void Grafo::proxAdj(TipoValorVertice *v, TipoValorVertice *adj, TipoPeso *p,
                        TipoApontador *prox, bool *fimListaAdj)
{
    *adj = *prox;
    *p = this->Matriz[*v][*prox];
    (*prox)++;

    while(*prox < this->N_Vertices && this->Matriz[*v][*prox] == 0)
    {
        (*prox)++;
    }

    if (*prox == this->N_Vertices)
    {
        *fimListaAdj = true;
    }
    else
    {
        *fimListaAdj = false;
    }
}

void Grafo::retiraAresta( TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p)
{
    if (v1 == nullptr || v2 == nullptr || p == nullptr ||
        *v1 < 0 || *v1 >= N_Vertices ||
        *v2 < 0 || *v2 >= N_Vertices ||
        this->Matriz[*v1][*v2] == 0)
    {
        printf("Aresta não existe!\n");
    }
    else
    {
        *p = this->Matriz[*v1][*v2];
        this->Matriz[*v1][*v2] = 0;
        --N_Arestas;
    }
}

void Grafo::imprimeGrafo()
{
    printf("   ");
    for (int i = 0; i < this->N_Vertices; i++)
    {
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < this->N_Vertices; i++)
    {
        printf("%3d", i);
        for (int j = 0; j < this->N_Vertices; j++)
        {
            printf("%3d", this->Matriz[i][j]);
        }
        printf("\n");
    }
    cout << endl;
}