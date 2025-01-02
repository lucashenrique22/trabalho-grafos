#include "../include/grafo_matriz.h"
#include <fstream>
#include <iostream>

GrafoMatriz::GrafoMatriz(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas)
    : ordem(ordem), direcionado(direcionado), peso_vertices(peso_vertices), peso_arestas(peso_arestas) {
    matriz.resize(ordem, std::vector<int>(ordem, 0));
}

GrafoMatriz::~GrafoMatriz() {}

bool GrafoMatriz::eh_bipartido() const {
    std::vector<int> cor(ordem, -1); // -1: não colorido, 0: cor 0, 1: cor 1

    for (int inicio = 0; inicio < ordem; ++inicio) {
        if (cor[inicio] == -1) { // Se o vértice não foi colorido
            cor[inicio] = 0;
            std::vector<int> fila;
            fila.push_back(inicio);

            while (!fila.empty()) {
                int u = fila.back();
                fila.pop_back();

                for (int v = 0; v < ordem; ++v) {
                    if (matriz[u][v] && cor[v] == -1) {
                        cor[v] = 1 - cor[u];
                        fila.push_back(v);
                    } else if (matriz[u][v] && cor[v] == cor[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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
    std::string line;
    std::getline(file, line);
    if (peso_vertices) {
        std::getline(file, line); 
    }
    int u, v;
    if (peso_arestas) {
        int peso;
        while (file >> u >> v >> peso) {
            matriz[u-1][v-1] = peso;
            if (!direcionado) matriz[v-1][u-1] = peso;
        }
    } else {
        while (file >> u >> v) {
            matriz[u-1][v-1] = 1;
            if (!direcionado) matriz[v-1][u-1] = 1;
        }
    }
}

void GrafoMatriz::novo_grafo(const std::string& config) {
    // Gerar grafo aleatório com base na configuração
}

void GrafoMatriz::imprime_grafo() const {
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}