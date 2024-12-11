#include "../include/graph.hpp"
#include <iostream>

Grafo::Grafo() : vertices() {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    vertices.adicionaVertice();
}

void Grafo::InsereAresta(int v, int w) {
    vertices.adicionaAresta(v, w);
}

int Grafo::QuantidadeVertices() {
    return vertices.getQuantidadeVertices();
}

int Grafo::QuantidadeArestas() {
    return vertices.getQuantidadeArestas();
}

int Grafo::GrauMinimo() {
    int grauMin = vertices.getVizinhos(0)->getTamanho();
    for (int i = 1; i < vertices.getQuantidadeVertices(); ++i) {
        if (vertices.getVizinhos(i)->getTamanho() < grauMin)
            grauMin = vertices.getVizinhos(i)->getTamanho();
    }
    return grauMin;
}

int Grafo::GrauMaximo() {
    int grauMax = vertices.getVizinhos(0)->getTamanho();
    for (int i = 1; i < vertices.getQuantidadeVertices(); ++i) {
        if (vertices.getVizinhos(i)->getTamanho() > grauMax)
            grauMax = vertices.getVizinhos(i)->getTamanho();
    }
    return grauMax;
}

void Grafo::ImprimeVizinhos(int v) {
    std::cout << "Vizinhos do vertice " << v << ": ";
    vertices.getVizinhos(v)->imprime();
}
