#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "grafo.h"
#include <vector>
#include <iostream>
using namespace std;

class GrafoMatriz : public Grafo {
public:
    GrafoMatriz(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas);
    ~GrafoMatriz();

    bool eh_bipartido() const override;
    int n_conexo() const override;
    int get_grau(int vertice) const override;
    int get_ordem() const override { return ordem; }
    bool eh_direcionado() const override { return direcionado; }
    bool vertice_ponderado() const override { return peso_vertices; }
    bool aresta_ponderada() const override { return peso_arestas; }
    bool eh_completo() const override;
    bool eh_arvore() const override;
    bool possui_articulacao() const override;
    bool possui_ponte() const override;
    bool possui_ciclo_dfs(int u, vector<bool>& visitado, vector<int>& pai) const;
    bool possui_ciclo() const;
    void carrega_grafo(const string& arquivo) override;
    void novo_grafo(const string& config) override;
    void exibe_propriedades() const;
    void imprime_matriz() const;
    void salva_grafo(ofstream& outFile) const;
    void dfs(vector<vector<int>> matriz, vector<bool>& visitado, int u) const;

private:
    vector<vector<int>> matriz;
    int ordem;
    bool direcionado;
    bool peso_arestas;
    bool peso_vertices;
};

#endif // GRAFO_MATRIZ_H