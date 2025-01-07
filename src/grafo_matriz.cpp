#include "../include/grafo_matriz.h"
#include <fstream>
#include <iostream>
using namespace std;

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
    vector<bool> visitado(ordem, false);
    int qtdComponentes = 0;
    for (int i = 0; i < ordem; ++i) {
        if (!visitado[i]) {
            dfs(matriz, visitado, i);
            ++qtdComponentes;
        }
    }
    return qtdComponentes;
}

void GrafoMatriz::dfs(vector<vector<int>> matriz, vector<bool>& visitado, int u) const{
    visitado[u] = true;
    for (int v = 0; v < matriz.size(); ++v) {
        if (matriz[u][v] && !visitado[v]) {
            dfs(matriz, visitado, v);
        }
    }

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
    vector<int> inDegree(ordem, 0);

    // Calcula o grau de entrada (in-degree) de cada vértice
    for (int u = 0; u < ordem; ++u) {
        for (int v = 0; v < ordem; ++v) {
            if (matriz[u][v] == 1) {
                inDegree[v]++;
            }
        }
    }

    // Usa um vector como "fila"
    vector<int> vec;
    for (int i = 0; i < ordem; ++i) {
        if (inDegree[i] == 0) {
            vec.push_back(i); // Adiciona os vértices com grau de entrada 0
        }
    }

    int index = 0; // Índice para simular remoção da "frente" da fila
    int visitedCount = 0;

    while (index < vec.size()) {
        int node = vec[index]; // Pega o elemento da "frente"
        index++;               // Avança o índice para a próxima posição
        visitedCount++;

        for (int v = 0; v < ordem; ++v) {
            if (matriz[node][v] == 1) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    vec.push_back(v); // Adiciona à "fila"
                }
            }
        }
    }
    // Se visitamos todos os vértices, o grafo é um DAG
    return visitedCount == ordem;
}

bool GrafoMatriz::possui_articulacao() const {
    for (int i = 0; i < ordem; ++i) {
       vector<bool> visitado(ordem, false);
        visitado[i] = true; // Remove o vértice i

        int start = (i == 0) ? 1 : 0; // Encontra um vértice inicial diferente de i
       vector<int> fila;
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
   
   for (int u = 0; u < ordem; ++u) {
        for (int v = 0; v < ordem; ++v) {
            if (matriz[u][v] != 0) {
                // Cria uma cópia da matriz
                vector<vector<int>> matriz_copy = matriz;

                // Remove a aresta (u, v) na cópia
                int temp = matriz_copy[u][v];
                matriz_copy[u][v] = 0;
                if (!direcionado) matriz_copy[v][u] = 0;

                // Verifica se o grafo ainda é conexo usando a cópia
                vector<bool> visitado(ordem, false);
                dfs(matriz_copy, visitado, (u == 0) ? 1 : 0);

                // Se o grafo não é mais conexo, (u, v) é uma ponte
                bool conexo = true;
                for (int i = 0; i < ordem; ++i) {
                    if (!visitado[i]) {
                        conexo = false;
                        break;
                    }
                }

                if (!conexo) return true;
            }
        }
    }
    return false;
}

void GrafoMatriz::carrega_grafo(const string& arquivo) {
   ifstream file(arquivo);
    if (!file.is_open()) {
       cerr << "Erro ao abrir o arquivo." <<endl;
        return;
    }
   string line;
   getline(file, line);
    if (peso_vertices) {
       getline(file, line); 
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

void GrafoMatriz::novo_grafo(const string& config) {
   
    // Limpa a matriz
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            matriz[i][j] = 0;
        }
    }

    // Implementação inicial para gerar um grafo aleatório
    srand(time(NULL));
    for (int i = 0; i < ordem; ++i) {
        for (int j = i + 1; j < ordem; ++j) {
            matriz[i][j] = rand() % 2;
            if (!direcionado) matriz[j][i] = matriz[i][j];
        }
    }

    imprime_matriz();
}

void GrafoMatriz::exibe_propriedades() const {

    cout << "Grau: " << get_grau(0) << endl;
    cout << "Ordem: " << get_ordem() << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Não") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Não") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Não") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Não") << endl;
    cout << "Bipartido: " << (eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "Arvore: " << (eh_arvore() ? "Sim" : "Não") << endl;
    cout << "Aresta Ponte: " << (possui_ponte() ? "Sim" : "Não") << endl;
    cout << "Vertice de Articulação: " << (possui_articulacao() ? "Sim" : "Não") << endl;
}

void GrafoMatriz::imprime_matriz() const {
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            cout << matriz[i][j] << " ";
        }
         cout << endl;
    }
}

void GrafoMatriz::salva_grafo(ofstream& outFile) const{
    outFile << ordem << " " << direcionado << " " << peso_vertices << " " << peso_arestas << endl;
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            if (matriz[i][j] != 0) {
                outFile << i << " " << j << " " << matriz[i][j] << endl;
            }
        }
    }
}