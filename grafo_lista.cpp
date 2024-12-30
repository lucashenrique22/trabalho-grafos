#include "grafo_lista.h"

GrafoLista::GrafoLista(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas)
    : ordem(ordem), direcionado(direcionado), peso_vertices(peso_vertices), peso_arestas(peso_arestas) {
    lista.resize(ordem);
}

GrafoLista::~GrafoLista() {}

bool GrafoLista::eh_bipartido() const {
    // Implementação inicial para checar bipartição
    return false;
}

int GrafoLista::n_conexo() const {
    // Implementação inicial para encontrar componentes conexas
    return 1;
}

int GrafoLista::get_grau(int vertice) const {
    return lista[vertice].size();
}

bool GrafoLista::eh_completo() const {
    for (int i = 0; i < ordem; ++i) {
        if (lista[i].size() != ordem - 1) return false;
    }
    return true;
}

bool GrafoLista::eh_arvore() const {
    // Verificar se é conexo e não tem ciclos
    return false;
}

bool GrafoLista::possui_articulacao() const {
    // Implementação inicial para detectar articulação
    return false;
}

bool GrafoLista::possui_ponte() const {
    // Implementação inicial para detectar ponte
    return false;
}

void GrafoLista::carrega_grafo(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
    int u, v;
    while (file >> u >> v) {
        lista[u].push_back(v);
        if (!direcionado) lista[v].push_back(u);
    }
}

void GrafoLista::novo_grafo(const std::string& config) {
    // Gerar grafo aleatório com base na configuração
}