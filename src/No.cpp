#include "../include/No.h"

No::No(int id) : id(id), proximo(nullptr) {}

int No::getId() const {
    return id;
}

No* No::getProximo() const {
    return proximo;
}

int No::getGrau() const {
    int grau = 0;
    No* atual = proximo;
    while (atual != nullptr) {
        grau++;
        atual = atual->getProximo();
    }
    return grau;
}

void No::addAdjacente(No* no) {
    if (proximo == nullptr) {
        proximo = no;
        return;
    }
    No* atual = proximo;
    while (atual->getProximo() != nullptr) {
        atual = atual->getProximo();
    }
    atual->proximo = no;
}