#include "../include/grafo_lista.h"
#include "../include/lista_encadeada.h" 

GrafoLista::GrafoLista(int ordem, bool direcionado, bool peso_vertices, bool peso_arestas)
    :ordem(ordem), direcionado(direcionado), peso_vertices(peso_vertices), peso_arestas(peso_arestas) {
    lista = new ListaEncadeada<No>(ordem); 
}

GrafoLista::~GrafoLista() {
    delete[] lista; 
}

bool GrafoLista::eh_bipartido() const {
    // Implementação inicial para checar bipartição
    return false;
}

int GrafoLista::n_conexo() const {
    // Implementação inicial para encontrar componentes conexas
    return 1;
}

int GrafoLista::get_grau(int vertice) const {
    return lista->get_elemento(vertice).getGrau(); // Supondo que sua classe de lista encadeada tenha um método tamanho()
}

bool GrafoLista::eh_completo() const {
    for (int i = 0; i < ordem; ++i) {
        if (lista->get_elemento(i).getGrau() != ordem - 1) return false; // Supondo que sua classe de lista encadeada tenha um método tamanho()
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
        std::cerr << "Erro ao abrir arquivo " << arquivo << std::endl;
        exit(1);
    }

    int vertice1, vertice2;
    float peso;
    while (file >> vertice1 >> vertice2 >> peso) {
        lista->inserirComNo(vertice1);
        lista->inserirComNo(vertice2);
    }
}

void GrafoLista::novo_grafo(const std::string& config) {
    // Gerar grafo aleatório com base na configuração
}