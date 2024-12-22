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
    return vertices.getQuantidadeArestas() / 2;
}

int Grafo::GrauMinimo() {
    int grauMin = vertices.grau(0);
    for (int i = 1; i < vertices.getQuantidadeVertices(); ++i) {
        if (vertices.grau(i) < grauMin)
            grauMin = vertices.grau(i);
    }
    return grauMin;
}

int Grafo::GrauMaximo() {
    int grauMax = vertices.grau(0);
    for (int i = 1; i < vertices.getQuantidadeVertices(); ++i) {
        if (vertices.grau(i) > grauMax)
            grauMax = vertices.grau(i);
    }
    return grauMax / 2;
}

void Grafo::ImprimeVizinhos(int v) {
    vertices.getVizinhos(v)->imprime();
}
