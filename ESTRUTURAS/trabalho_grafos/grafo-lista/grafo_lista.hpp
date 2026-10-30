/**
 * @file grafo_lista.hpp
 * @author Vinícius Almeida Hermes (vinicius.hermes@unioeste.br)
 * @brief Implementação orientada a objetos da estrutura de Grafo por Lista de Adjacência para a 3a Avaliação da disciplina de Estrutura de Dados do ano letivo de 2026, ministrada pelo professor MSc. Leonardo Medeiros
 * @version 0.1
 * @date 2026-10-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef GRAFO_LISTA_HPP
#define GRAFO_LISTA_HPP

#define MAX_VERTICES 100

#include <cstdio>

using TipoValorVertice = int;
using TipoPeso = int;


/**
 * @brief Define o Tipo item, isto é, cada elemento do grafo, que tem um vértice e um peso
 * 
 */
class TipoItem
{
public:
    TipoValorVertice Vertice;
    TipoPeso Peso;

    /**
     * @brief Consturtor do objeto Tipo Item
     * 
     * @param v 
     * @param p 
     */
    TipoItem(TipoValorVertice v = 0, TipoPeso p = 0): Vertice(v), Peso(p){}
};

/**
 * @brief Define a célula do grafo, que contém um item do TipoItem e uma refência para a próxima célula
 * 
 */
class TipoCelula
{
public:
    TipoItem item;
    TipoCelula* prox;

    TipoCelula(const TipoItem& item = TipoItem(), TipoCelula* prox = nullptr)
        : item(item), prox(prox)
    {
    }
};

using TipoApontador = TipoCelula*;

/**
 * @brief Define a lista de células, que armazena a primeira e a última lista de células
 * 
 */
class TipoLista
{
public:
    TipoApontador Primeiro;
    TipoApontador Ultimo;

    TipoLista();
    ~TipoLista();

    //  Apesar de não estarem descritos um por um nos slides, estes métodos são necessários para a criação da implementação
    //  orientada a objetos do Grafo por lista. Implementações semelhantesjá foram vistas em sala de aula 
    //  e essas em específico foram retiradadas do livro:
    //  Projeto de Algoritmos com Implementação em Pascal e C - Nivio Ziviani

    /**
     * @brief Torna a lista vazia
     * 
     */
    void FLVazia();

    /**
     * @brief Verifica se a lista está vazia
     * 
     * @return `true` quando a lista está vazia
     * @return `false` quando contém algum item na lista
     */
    bool vazia() const;

    /**
     * @brief Insere um item no final da lista
     * 
     * @param i item a ser inserido
     */
    void insere(const TipoItem& i);

    /**
     * @brief Insere um item em uma posição específica
     * 
     * @param i item a ser inserido
     * @param l célula da lista na qual o item será inserido
     */
    void insere(const TipoItem& i, TipoApontador l);

    /**
     * @brief Retira um item da lista
     * 
     * @param p elemento anterior do item a ser removido
     * @param i item a ser removido
     */
    bool retira(TipoApontador p, TipoItem *i);

    /**
     * @brief Imprime a lista
     * 
     */
    void imprime() const;

};

/**
 * @brief Define o grafo, contendo as listas de células, o núemro de vertices e arestas
 * 
 */
class TipoGrafo
{
public:
    TipoLista Adj[MAX_VERTICES + 1];
    TipoValorVertice N_Vertices;
    short N_Arestas;

    /**
     * @brief Consturtor do objeto Tipo Grafo. Constrói o grafo com n vérticés
     * 
     * @param n
     */
    TipoGrafo(TipoValorVertice n);

    /**
     * @brief Torna o grafo vazio 
     * 
     */
    void FGVazio();

    /**
     * @brief Insere uma aresta no grafo
     * 
     * @param v1 vértice de origem
     * @param v2 vértice de destino
     * @param p peso da aresta
     */
    void insereAresta(TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p);

    /**
     * @brief Verifica se há uma aresta entre dois vértices
     * 
     * @param v1 vértice de origem
     * @param v2 vértice de destino
     * @return `true` se há uma aresta entre os vértices
     * @return `false` se não há aresta entre os vértices
     */
    bool existeAresta(TipoValorVertice v1, TipoValorVertice v2);

    /**
     * @brief Verifica se há adjacência para o vértice
     * 
     * @param v vértice a ser verificado
     * @return `true` 
     * @return `false` 
     */
    bool listaAdjVazia(TipoValorVertice *v);

    /**
     * @brief Retrona a primeira aresta da lista de adjacência do vértice
     * 
     * @param v vértice a ser verificado
     * @return TipoApontador 
     */
    TipoApontador primeiroListaAdj(TipoValorVertice *v);

    /**
     * @brief Obtém a próxima adjacência e o peso da aresta correspondente
     * 
     * @param v Vértice cuja lista de adjacência será percorrida.
     * @param[out] adj Recebe o vértice adjacente encontrado.
     * @param[out] p Recebe o peso da aresta entre `v` e `adj`.
     * @param[out] prox Posição da próxima adjacência a ser consultada.
     * @param[out] fimListaAdj Recebe true quando não existem mais adjacências a consultar e false caso ainda existam.
     */
    void proxAdj(TipoValorVertice *v, TipoValorVertice *adj, TipoPeso *p, TipoApontador *prox, bool *fimListaAdj);

    /**
     * @brief Remove uma aresta entre dois vértices e coloca em `*p` o peso que a aresta tinha
     * 
     * @param v1 vértice de origem
     * @param v2 vértice de destino
     * @param[out] p recebe o peso da aresta removida
     */
    void retiraAresta(TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p);

    /**
     * @brief Limpa todo o grafo
     * 
     */
    void liberaGrafo();

    /**
     * @brief Imprime o grafo
     * 
     */
    void imprimeGrafo();

};

#include "grafo_lista.cpp"
#endif // !GRAFO_LISTA_HPP
