#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "../include/Lista.hpp"

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void adicionaVertice();
    void adicionaAresta(int v, int w);
    Lista<int>* getVizinhos(int v);
    int getQuantidadeVertices();
    int getQuantidadeArestas();
    void imprime();
    int grau(int v);

private:
    Lista<Lista<int>*> vertices;
    int quantidadeArestas;
};

#endif