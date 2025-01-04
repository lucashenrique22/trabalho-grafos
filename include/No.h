#ifndef NO_H
#define NO_H

#include <vector>

class No {
public:
    No(int id);
    int getId() const;
    void addAdjacente(No* no);
    No* getProximo() const; 
    int getGrau() const;

private:
    int id;
    No* proximo;
};

#endif // NO_H