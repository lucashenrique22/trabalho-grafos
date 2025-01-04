#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "No.h"

// Declaração de classe template
template <typename T>
class ListaEncadeada {
private:
    T* cabeca; // Ponteiro para o início da lista
    int tamanho;

public:
    // Construtor
    ListaEncadeada(int tamanho = 0) : cabeca(nullptr), tamanho(tamanho) {}

    // Destrutor
    ~ListaEncadeada() {
        T* atual = cabeca;
        T* proximo = nullptr;

        while (atual != nullptr) {
            proximo = atual->getProximo();
            delete atual;
            atual = proximo;
        }
    }

    // Inserir elemento no início da lista
    void inserirComNo(int no) {
        T* novo = new T(no);
        novo->addAdjacente(cabeca); // Assume que T possui um método addAdjacente()
        cabeca = novo;
        ++tamanho;
    }

    // Verificar se contém um elemento
    bool contem(int valor) const {
        T* atual = cabeca;
        while (atual != nullptr) {
            if (atual->getValor() == valor) { // Assume que T possui um método getValor()
                return true;
            }
            atual = atual->getProximo(); // Assume que T possui um método getProximo()
        }
        return false;
    }

    // Obter um elemento
    T& get_elemento(int pos) const {
        T* atual = cabeca;
        for (int i = 0; i < pos; ++i) {
            atual = atual->getProximo(); // Assume que T possui um método getProximo()
        }
        return *atual;
    }

    // Obter o tamanho da lista
    int get_tamanho() const { return tamanho; }
};

#endif
