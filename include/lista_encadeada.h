#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

template <typename T>
class ListaEncadeada {
private:
    struct No {
        T dado;
        No* proximo;
        No(T valor) : dado(valor), proximo(nullptr) {}
    };

    No* cabeca;
    int tamanho;

public:
    ListaEncadeada() : cabeca(nullptr), tamanho(0) {}
    ~ListaEncadeada(); // Destrutor

    void inserir(T valor);
    bool contem(T valor);
    int get_tamanho() const;
    T get_elemento(int indice) const;
    // Outras funções úteis, como remover, etc., podem ser adicionadas conforme necessário
};

#endif