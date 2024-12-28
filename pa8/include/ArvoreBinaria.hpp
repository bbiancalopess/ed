#ifndef ARVOREBINARIA_HPP
#define ARVOREBINARIA_HPP

#include "../include/Node.hpp"

class ArvoreBinaria {
public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void insere(int item);
    void remove(int item);
    void limpa();
    void preOrdem(Node* p);
    void inOrdem(Node* p);
    void posOrdem(Node* p);
    Node* raiz;
private:
    Node* insereRecursivo(Node* p, int item);
    void apagaRecursivo(Node* p);
    Node* removeRecursivo(Node* p, int item);
    Node* encontraMinimo(Node* p);
};

#endif