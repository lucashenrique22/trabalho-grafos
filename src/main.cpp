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

GrafoMatriz gerarGrafoAleatorio(const string& file) {
    ifstream arquivo(file);
    string linha;

    if (!getline(arquivo, linha)) {
        cerr << "Erro ao ler o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    size_t pos = 0;
    int numVertices;
    bool isDir, isPonderadoVertice, isPonderadoAresta;

    pos = linha.find(' ');
    numVertices = atoi(linha.substr(0, pos).c_str());
    linha = linha.substr(pos + 1);

    pos = linha.find(' ');
    isDir = static_cast<bool>(atoi(linha.substr(0, pos).c_str()));
    linha = linha.substr(pos + 1);

    pos = linha.find(' ');
    isPonderadoVertice = static_cast<bool>(atoi(linha.substr(0, pos).c_str()));
    linha = linha.substr(pos + 1);

    isPonderadoAresta = static_cast<bool>(atoi(linha.c_str()));

    GrafoMatriz grafo(numVertices, isDir, isPonderadoVertice, isPonderadoAresta);
    grafo.novo_grafo(file);

    ofstream outFile("../novo_grafo.txt");
    grafo.salva_grafo(outFile);
    
    outFile.close();

    return grafo;
}

int main(int argc, char* argv[]) {
    
    string comando = argv[1];
    string modo = argv[2];
    string arquivoGrafo = argv[3];
    
    if (comando == "-d" && modo == "-m") {
        GrafoMatriz grafo = gerarGrafo(arquivoGrafo);

        grafo.exibe_propriedades();

    } else if (comando == "-c" && modo == "-m") {

       GrafoMatriz grafo = gerarGrafoAleatorio(arquivoGrafo);
       grafo.exibe_propriedades();
    }

    return 0;
}