#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "grafo.h"
#include "lista_encadeada.h" // Inclua o cabeçalho da sua classe de lista encadeada
#include <iostream>
#include <fstream>
#include <cstdlib>

class GrafoLista : public Grafo {
public:
    GrafoLista(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas);
    ~GrafoLista();

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
    void carrega_grafo(const std::string& arquivo) override;
    void novo_grafo(const std::string& config) override;

private:
    ListaEncadeada <No>* lista; 
    bool peso_arestas;
    bool peso_vertices;
    bool direcionado;
    int ordem;
};

#endif // GRAFO_LISTA_H