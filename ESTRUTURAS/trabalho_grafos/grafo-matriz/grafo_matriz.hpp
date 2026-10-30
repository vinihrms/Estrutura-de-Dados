/**
 * @file grafo_matriz.hpp
 * @author Vinícius Almeida Hermes (vinicius.hermes@unioeste.br)
 * @brief Implementação orientada a objetos da estrutura de Grafo por Matriz de Adjacência para a 3a Avaliação da disciplina de Estrutura de Dados do ano letivo de 2026, ministrada pelo professor MSc. Leonardo Medeiros
 * @version 0.1
 * @date 2026-10-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef GRAFO_MATRIZ_HPP
#define GRAFO_MATRIZ_HPP

#define MAX_VERTICES 100

/**
 * @brief Inicialiação de tipos de dados para melhor interpretação da estrutura
 * 
 */
using TipoValorVertice = int;
using TipoPeso = int;
using TipoApontador = int;


/**
 * @class Grafo
 * @brief Representa um grafo usando uma matriz de adjacência.
 *
 * A classe armazena o peso de cada aresta em uma matriz, de tamanho máximo de 100x100.
 * Cada linha representa o vértice de origem e cada coluna representa
 * o vértice de destino.
 *
 * Uma posição com valor zero indica que não existe aresta entre os
 * respectivos vértices. Já uma posição com valor, representa o peso da aresta.
 * 
 *
 * Os vértices são identificados por índices no intervalo
 * [0, numero_vertices - 1].
 */
class Grafo
{
private:
    TipoPeso Matriz[MAX_VERTICES][MAX_VERTICES];
    int N_Vertices;
    int N_Arestas;

public:
    /**
     * @brief Construtor do objeto Grafo.
     * 
     * Recebe o número de vértices e inicializa um grafo com nenhuma aresta.
     * 
     * @param numero_vertices 
     */
    explicit Grafo(int numero_vertices);

    /**
     * @brief Destrutor do objeto Grafo
     * 
     */
    ~Grafo() = default;

    /**
     * @brief Função que insere uma aresta entre dois vértices.
     *  
     * @param v1 Vértice de origem
     * @param v2 Vértice de destino
     * @param peso Peso (valor) da aresta
     */
    void insereAresta(TipoValorVertice*v1, TipoValorVertice *v2,
                        TipoPeso *peso); 

    /**
     * @brief Verifica se existe uma aresta entre dois pontos quaisquer.
     * 
     * @param v1 Vértice de origem
     * @param v2 Vértice de destino
     * @return `true` caso exista uma aresta entre os vértices (possui peso > 0)
     * @return `false` caso não exista aresta entre os vértices (peso >= 0)
     */
    bool existeAresta(TipoValorVertice v1, TipoValorVertice v2);

    /**
     * @brief Verifica se há adjacência no vértice em questao
     * 
     * @param i Vertice que se dejseja verificar se há adjacências
     * @return `true` caso haja adjacências
     * @return `false` caso não haja adjacências
     */
    bool listaAdjVazia(TipoValorVertice *v);

    /**
     * @brief Obtém o primeiro vértice que tem adjacência a determinado vértice
     * 
     * @param v Vértice que se deseja verificar
     * @return Índice do primeiro vértice adjacênte
     * 
     * @note Quando não há adjacência, retorna N_Vertices, pois percorreu toda a matriz  
     */
    TipoApontador primeiroListaAdj(TipoValorVertice *v);
    
    /**
     * @brief Obtém uma adjacência e avança o apontador da lista.
     * 
     * A posição indicada por `prox` deve ser a primeira adjacência
     * encontrada ou uma posição válida para a próxima consulta.
     * 
     * @param v Vértice cuja lista de adjacência será percorrida.
     * @param[out] adj Recebe o vértice adjacente encontrado.
     * @param[out] p Recebe o peso da aresta entre `v` e `adj`.
     * @param[in,out] prox Recebe a posição da próxima adjacência a ser
     * consultada.
     * @param[out] fimListaAdj Recebe true quando não existem mais adjacências
     * a consultar e false caso ainda existam.
     */
    void proxAdj(TipoValorVertice *v, TipoValorVertice *adj, TipoPeso *p,
                        TipoApontador *prox, bool *fimListaAdj);
    
    /**
     * @brief Remove uma aresta entre dois vértices e retorna o peso que tinha
     * 
     * @param v1 Vértice de origem
     * @param v2 Vértice de origem
     * @param[out] p Após a execução, recebe o peso que a aresta removida tinha
     */
    void retiraAresta( TipoValorVertice *v1, TipoValorVertice *v2, TipoPeso *p);

    /**
     * @brief Imprime a matriz de adjacência do grafo, com os pesos de cada aresta
     * 
     */
    void imprimeGrafo();
};

#include "grafo_matriz.cpp"
#endif // !GRAFO_MATRIZ_HPP
