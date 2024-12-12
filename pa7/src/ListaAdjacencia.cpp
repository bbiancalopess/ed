#include "../include/ListaAdjacencia.hpp"
#include <iostream>

ListaAdjacencia::ListaAdjacencia() {
    quantidadeArestas = 0;
}

ListaAdjacencia::~ListaAdjacencia() {
    for (int i = 0; i < vertices.getTamanho(); ++i) {
        delete vertices.getItem(i);
    }
}

void ListaAdjacencia::adicionaVertice() {
    vertices.insereInicio(new Lista<int>());
}

void ListaAdjacencia::adicionaAresta(int v, int w) {
    if (v < 0 || v >= vertices.getTamanho()) {
        throw "ERRO: Vertice invalido!";
    }
    vertices.getItem(v)->insereFinal(w);
    quantidadeArestas++;
}

Lista<int>* ListaAdjacencia::getVizinhos(int v) {
    if (v < 0 || v >= vertices.getTamanho()) {
        throw "ERRO: Vertice invalido!";
    }
    return vertices.getItem(v);
}

int ListaAdjacencia::getQuantidadeVertices() {
    return vertices.getTamanho();
}

int ListaAdjacencia::getQuantidadeArestas() {
    return quantidadeArestas;
}

void ListaAdjacencia::imprime() {
    for (int i = 0; i < vertices.getTamanho(); ++i) {
        std::cout << "Vertice " << i << ": ";
        vertices.getItem(i)->imprime();
    }
}

int ListaAdjacencia::grau(int v) {
    return vertices.getItem(v)->getTamanho();
}