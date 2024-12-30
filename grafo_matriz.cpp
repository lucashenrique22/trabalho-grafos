#include "grafo_matriz.h"
#include <fstream>
#include <iostream>

GrafoMatriz::GrafoMatriz(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas)
    : ordem(ordem), direcionado(direcionado), peso_vertices(peso_vertices), peso_arestas(peso_arestas) {
    matriz.resize(ordem, std::vector<int>(ordem, 0));
}

GrafoMatriz::~GrafoMatriz() {}

bool GrafoMatriz::eh_bipartido() const {
    // Implementação inicial para checar bipartição
    return false;
}

int GrafoMatriz::n_conexo() const {
    // Implementação inicial para encontrar componentes conexas
    return 1;
}

int GrafoMatriz::get_grau(int vertice) const {
    int grau = 0;
    for (int i = 0; i < ordem; ++i) {
        grau += matriz[vertice][i];
    }
    return grau;
}

bool GrafoMatriz::eh_completo() const {
    for (int i = 0; i < ordem; ++i) {
        for (int j = i + 1; j < ordem; ++j) {
            if (matriz[i][j] == 0) return false;
        }
    }
    return true;
}

bool GrafoMatriz::eh_arvore() const {
    // Verificar se é conexo e não tem ciclos
    return false;
}

bool GrafoMatriz::possui_articulacao() const {
    // Implementação inicial para detectar articulação
    return false;
}

bool GrafoMatriz::possui_ponte() const {
    // Implementação inicial para detectar ponte
    return false;
}

void GrafoMatriz::carrega_grafo(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
    int u, v;
    while (file >> u >> v) {
        matriz[u][v] = 1;
        if (!direcionado) matriz[v][u] = 1;
    }
}

void GrafoMatriz::novo_grafo(const std::string& config) {
    // Gerar grafo aleatório com base na configuração
}