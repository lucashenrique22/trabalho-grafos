#include "../include/grafo_matriz.h"
#include "../include/grafo_lista.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

GrafoMatriz gerarGrafo(const std::string& file) {
    ifstream arquivo(file);
    string linha;
    // Pega a primeira linha do arquivo
    // a estrutura do arquivo é a seguinte:
    // 1ª linha: número de vértices, isDir, isPonderadoVertice, isPonderadoAresta
    // 2ª linha em diante: as arestas

    getline(arquivo, linha);
    stringstream ss;
    ss << linha;
    int numVertices;
    bool isDir, isPonderadoVertice, isPonderadoAresta;
    ss >> numVertices >> isDir >> isPonderadoVertice >> isPonderadoAresta;
    
    GrafoMatriz grafo(numVertices, isDir, isPonderadoVertice, isPonderadoAresta);
    grafo.carrega_grafo(file);
    return grafo;
}

int main() {
    GrafoMatriz grafoMatriz = gerarGrafo("../grafo.txt");

    if (grafoMatriz.eh_bipartido()) {
        std::cout << "O grafo é bipartido." << std::endl;
    } else {
        std::cout << "O grafo não é bipartido." << std::endl;
    }

    if (grafoMatriz.possui_articulacao()) {
        std::cout << "O grafo possui articulação." << std::endl;
    } else {
        std::cout << "O grafo não possui articulação." << std::endl;
    }

    if(grafoMatriz.eh_arvore()) {
        std::cout << "O grafo é uma árvore." << std::endl;
    } else {
        std::cout << "O grafo não é uma árvore." << std::endl;
    }

    if(grafoMatriz.eh_completo()) {
        std::cout << "O grafo é completo." << std::endl;
    } else {
        std::cout << "O grafo não é completo." << std::endl;
    }

    grafoMatriz.imprime_grafo();

    return 0;
}