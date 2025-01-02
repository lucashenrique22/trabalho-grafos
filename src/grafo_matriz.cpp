#include "../include/grafo_matriz.h"
#include <fstream>
#include <iostream>

GrafoMatriz::GrafoMatriz(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas)
    : ordem(ordem), direcionado(direcionado), peso_vertices(peso_vertices), peso_arestas(peso_arestas) {
    matriz.resize(ordem, std::vector<int>(ordem, 0));
}

GrafoMatriz::~GrafoMatriz() {}

bool GrafoMatriz::eh_bipartido() const {
    // Itera sobre todas as possíveis divisões dos vértices em dois conjuntos
    for (int i = 0; i < (1 << ordem); ++i) {
        std::vector<int> cor(ordem, -1);
        // Atribui cores aos vértices com base na divisão atual
        for (int j = 0; j < ordem; ++j) {
            cor[j] = (i & (1 << j)) ? 1 : 0;
        }
        bool bipartido = true;
        // Verifica se a divisão atual é válida (não há arestas entre vértices do mesmo conjunto)
        for (int u = 0; u < ordem && bipartido; ++u) {
            for (int v = 0; v < ordem; ++v) {
                if (matriz[u][v] && cor[u] == cor[v]) {
                    bipartido = false;
                    break;
                }
            }
        }
        // Se encontrou uma divisão válida, retorna true
        if (bipartido) return true;
    }
    // Se nenhuma divisão válida foi encontrada, retorna false
    return false;
}

int GrafoMatriz::n_conexo() const {
    std::vector<bool> visitado(ordem, false);
    int qtdComponentes = 0;

    for (int i = 0; i < ordem; ++i) {
        if (!visitado[i]) {
            ++qtdComponentes;
            std::vector<int> fila;
            fila.push_back(i);
            visitado[i] = true;

            while (!fila.empty()) {
                int u = fila.back();
                fila.pop_back();

                for (int v = 0; v < ordem; ++v) {
                    if (matriz[u][v] && !visitado[v]) {
                        fila.push_back(v);
                        visitado[v] = true;
                    }
                }
            }
        }
    }

    return qtdComponentes;
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
    
    if(n_conexo() == 1 && !possui_ciclo()) { return true; }
    return false;
}

bool GrafoMatriz::possui_ciclo() const {
    std::vector<bool> visitado(ordem, false);
    std::vector<int> pilha(ordem, -1);

    for (int i = 0; i < ordem; ++i) {
        if (!visitado[i]) {
            std::vector<int> fila;
            fila.push_back(i);
            visitado[i] = true;
            pilha[i] = -1;

            while (!fila.empty()) {
                int u = fila.back();
                fila.pop_back();

                for (int v = 0; v < ordem; ++v) {
                    if (matriz[u][v]) {
                        if (!visitado[v]) {
                            fila.push_back(v);
                            visitado[v] = true;
                            pilha[v] = u;
                        } else if (pilha[u] != v) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}
bool GrafoMatriz::possui_articulacao() const {
    for (int i = 0; i < ordem; ++i) {
        std::vector<bool> visitado(ordem, false);
        visitado[i] = true; // Remove o vértice i

        int start = (i == 0) ? 1 : 0; // Encontra um vértice inicial diferente de i
        std::vector<int> fila;
        fila.push_back(start);
        visitado[start] = true;

        while (!fila.empty()) {
            int u = fila.back();
            fila.pop_back();

            for (int v = 0; v < ordem; ++v) {
                if (matriz[u][v] && !visitado[v]) {
                    fila.push_back(v);
                    visitado[v] = true;
                }
            }
        }
        // Verifica se todos os vértices foram visitados
        for (int j = 0; j < ordem; ++j) {
            if (!visitado[j]) return true;
        }
    }
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