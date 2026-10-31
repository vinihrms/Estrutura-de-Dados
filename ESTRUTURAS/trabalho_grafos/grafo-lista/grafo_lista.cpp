#include "grafo_lista.hpp"

TipoLista::TipoLista()
    : Primeiro(new TipoCelula()), Ultimo(Primeiro){}

TipoLista::~TipoLista()
{
    FLVazia();
    delete Primeiro;
    Primeiro = nullptr;
    Ultimo = nullptr;
}

void TipoLista::FLVazia()
{
    TipoApontador atual = Primeiro->prox;

    while (atual != nullptr)
    {
        TipoApontador proxima = atual->prox;
        delete atual;
        atual = proxima;
    }

    Primeiro->prox = nullptr;
    Ultimo = Primeiro;
}

bool TipoLista::vazia() const
{
    return Primeiro == Ultimo;
}

void TipoLista::insere(const TipoItem& i)
{
    insere(i, Ultimo);
}

void TipoLista::insere(const TipoItem& i, TipoApontador l)
{
    if (l == nullptr)
    {
        return;
    }

    TipoApontador nova = new TipoCelula(i, l->prox);
    l->prox = nova;

    if (l == Ultimo)
    {
        Ultimo = nova;
    }
}

bool TipoLista::retira(TipoApontador p, TipoItem *i)
{
    if (p == nullptr || p->prox == nullptr || i == nullptr)
    {
        return false;
    }

    TipoApontador q = p->prox;
    *i = q->item;
    p->prox = q->prox;

    if (q == Ultimo)
    {
        Ultimo = p;
    }

    delete q;
    return true;
}

void TipoLista::imprime() const
{
    TipoApontador aux = Primeiro->prox;
    while (aux != nullptr)
    {
        printf("%3d (%d) ", aux->item.Vertice, aux->item.Peso);
        aux = aux->prox;
    }
    putchar('\n');
}

TipoGrafo::TipoGrafo(TipoValorVertice n)
    : N_Vertices(n), N_Arestas(0)
{
    if (n < 0 || n > MAX_VERTICES)
    {
        N_Vertices = 0;
    }
}

void TipoGrafo::FGVazio()
{
    for (int i = 0; i < N_Vertices; i++)
    {
        Adj[i].FLVazia();
    }
    N_Arestas = 0;
}

void TipoGrafo::insereAresta(TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p)
{
    if (v1 == nullptr || v2 == nullptr || p == nullptr ||
        *v1 < 0 || *v1 >= N_Vertices ||
        *v2 < 0 || *v2 >= N_Vertices)
    {
        return;
    }

    Adj[*v1].insere(TipoItem(*v2, *p));
    ++N_Arestas;
}

bool TipoGrafo::existeAresta(TipoValorVertice v1, TipoValorVertice v2)
{
    if (v1 < 0 || v1 >= N_Vertices || v2 < 0 || v2 >= N_Vertices)
    {
        return false;
    }

    for (TipoApontador aux = Adj[v1].Primeiro->prox;
         aux != nullptr;
         aux = aux->prox)
    {
        if (aux->item.Vertice == v2)
        {
            return true;
        }
    }

    return false;
}

bool TipoGrafo::listaAdjVazia(TipoValorVertice *v)
{
    if (v == nullptr || *v < 0 || *v >= N_Vertices)
    {
        return true;
    }

    return Adj[*v].vazia();
}

TipoApontador TipoGrafo::primeiroListaAdj(TipoValorVertice *v)
{
    if (v == nullptr || *v < 0 || *v >= N_Vertices)
    {
        return nullptr;
    }

    return Adj[*v].Primeiro->prox;
}


void TipoGrafo::proxAdj(TipoValorVertice *v, TipoValorVertice *adj, TipoPeso *p, TipoApontador *prox, bool *fimListaAdj)
{
    if (v == nullptr || adj == nullptr || p == nullptr ||
        prox == nullptr || fimListaAdj == nullptr || *prox == nullptr)
    {
        *fimListaAdj = true;
        return;
    }

    *adj = (*prox)->item.Vertice;
    *p = (*prox)->item.Peso;
    *prox = (*prox)->prox;
    *fimListaAdj = (*prox == nullptr);
}


void TipoGrafo::retiraAresta(TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p)
{
    if (v1 == nullptr || v2 == nullptr || p == nullptr ||
        *v1 < 0 || *v1 >= N_Vertices ||
        *v2 < 0 || *v2 >= N_Vertices)
    {
        return;
    }

    TipoApontador anterior = Adj[*v1].Primeiro;
    while (anterior->prox != nullptr)
    {
        if (anterior->prox->item.Vertice == *v2)
        {
            TipoItem removido;
            if (Adj[*v1].retira(anterior, &removido))
            {
                *p = removido.Peso;
                --N_Arestas;
            }
            return;
        }
        anterior = anterior->prox;
    }
}

void TipoGrafo::liberaGrafo()
{
    FGVazio();
}

void TipoGrafo::imprimeGrafo()
{
    for (int i = 0; i < N_Vertices; i++)
    {
        printf("Vertice%2d: ", i);
        Adj[i].imprime();
    }
}