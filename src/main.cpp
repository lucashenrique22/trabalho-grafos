#include "../include/grafo_matriz.h"
#include "../include/grafo_lista.h"
#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

GrafoMatriz gerarGrafo(const string& file) {
    
    ifstream arquivo(file);
    string linha;

    // Pega a primeira linha do arquivo
    // a estrutura do arquivo é a seguinte:
    // 1ª linha: número de vértices, isDir, isPonderadoVertice, isPonderadoAresta
    // 2ª linha em diante: as arestas
    if (!getline(arquivo, linha)) {
        cerr << "Erro ao ler o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    // Tokeniza a linha lida
    size_t pos = 0;
    int numVertices;
    bool isDir, isPonderadoVertice, isPonderadoAresta;

    // Extrai número de vértices
    pos = linha.find(' ');
    numVertices = atoi(linha.substr(0, pos).c_str());
    linha = linha.substr(pos + 1);

    // Extrai isDir
    pos = linha.find(' ');
    isDir = static_cast<bool>(atoi(linha.substr(0, pos).c_str()));
    linha = linha.substr(pos + 1);

    // Extrai isPonderadoVertice
    pos = linha.find(' ');
    isPonderadoVertice = static_cast<bool>(atoi(linha.substr(0, pos).c_str()));
    linha = linha.substr(pos + 1);

    // Extrai isPonderadoAresta
    isPonderadoAresta = static_cast<bool>(atoi(linha.c_str()));

    GrafoMatriz grafo(numVertices, isDir, isPonderadoVertice, isPonderadoAresta);
    grafo.carrega_grafo(file);

    return grafo;
}

GrafoLista gerarGrafoLista(const string& file) {
    
    ifstream arquivo(file);
    string linha;

    // Pega a primeira linha do arquivo
    // a estrutura do arquivo é a seguinte:
    // 1ª linha: número de vértices, isDir, isPonderadoVertice, isPonderadoAresta
    // 2ª linha em diante: as arestas

    if (!getline(arquivo, linha)) {
        cerr << "Erro ao ler o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    // Tokeniza a linha lida
    size_t pos = 0;
    int numVertices;
    bool isDir, isPonderadoVertice, isPonderadoAresta;

    // Extrai número de vértices
    pos = linha.find(' ');
    numVertices = atoi(linha.substr(0, pos).c_str());
    linha = linha.substr(pos + 1);

    // Extrai isDir
    pos = linha.find(' ');
    isDir = static_cast<bool>(atoi(linha.substr(0, pos).c_str()));
    linha = linha.substr(pos + 1);

    // Extrai isPonderadoVertice
    pos = linha.find(' ');
    isPonderadoVertice = static_cast<bool>(atoi(linha.substr(0, pos).c_str()));
    linha = linha.substr(pos + 1);

    // Extrai isPonderadoAresta
    isPonderadoAresta = static_cast<bool>(atoi(linha.c_str()));

    GrafoLista grafo(numVertices, isDir, isPonderadoVertice, isPonderadoAresta);
    grafo.carrega_grafo(file);

    return grafo;
}

int main(int argc, char* argv[]) {
    
    string arquivoGrafo = argv[3];
    GrafoMatriz grafo = gerarGrafo(arquivoGrafo);

    // Imprimir propriedades do grafo
    cout << "Grafo carregado de " << arquivoGrafo << ":\n";

    cout << "Grau: " << grafo.get_grau(0) << endl;
    cout << "Ordem: " << grafo.get_ordem() << endl;
    cout << "Direcionado: " << (grafo.eh_direcionado() ? "Sim" : "Não") << endl;
    cout << "Componentes conexas: " << grafo.n_conexo() << endl;
    cout << "Vertices ponderados: " << (grafo.vertice_ponderado() ? "Sim" : "Não") << endl;
    cout << "Arestas ponderadas: " << (grafo.aresta_ponderada() ? "Sim" : "Não") << endl;
    cout << "Completo: " << (grafo.eh_completo() ? "Sim" : "Não") << endl;
    cout << "Bipartido: " << (grafo.eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "Arvore: " << (grafo.eh_arvore() ? "Sim" : "Não") << endl;
    cout << "Aresta Ponte: " << (grafo.possui_ponte() ? "Sim" : "Não") << endl;
    cout << "Vertice de Articulação: " << (grafo.possui_articulacao() ? "Sim" : "Não") << endl;

    return 0;
}