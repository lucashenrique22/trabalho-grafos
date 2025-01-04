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

int main() {
    // GrafoMatriz grafoMatriz = gerarGrafo("../grafo.txt");

    //  grafoMatriz.imprime_grafo();

    // if(grafoMatriz.eh_direcionado()) {
    //     cout << "O grafo é direcionado." << endl;
    // } else {
    //     cout << "O grafo não é direcionado." << endl;
    // }

    // int qtdComponentes = grafoMatriz.n_conexo();
    //     cout << qtdComponentes << endl;
    
    
    // if (grafoMatriz.eh_bipartido()) {
    //     cout << "O grafo é bipartido." << endl;
    // } else {
    //     cout << "O grafo não é bipartido." << endl;
    // }

    // if (grafoMatriz.possui_articulacao()) {
    //     cout << "O grafo possui articulação." << endl;
    // } else {
    //     cout << "O grafo não possui articulação." << endl;
    // }

    // cout << grafoMatriz.possui_ciclo() << endl;

    // if(grafoMatriz.eh_arvore()) {
    //     cout << "O grafo é uma árvore." << endl;
    // } else {
    //     cout << "O grafo não é uma árvore." << endl;
    // }

    // if(grafoMatriz.eh_completo()) {
    //     cout << "O grafo é completo." << endl;
    // } else {
    //     cout << "O grafo não é completo." << endl;
    // }

    GrafoLista grafoLista = gerarGrafoLista("../grafo.txt");
     cout << "o grau do grafo eh: " << grafoLista.get_grau(0) << endl;
    return 0;
}