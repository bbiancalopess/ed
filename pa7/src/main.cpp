#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/graph.hpp"

void processaEntrada(Grafo &grafo) {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        grafo.InsereVertice();
    }

    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int vizinho;
            std::cin >> vizinho;
            if (vizinho != i)
                grafo.InsereAresta(i, vizinho);
        }
    }
}

int main (int argc, char ** argv) {
    if (argc != 2) {
        std::cerr << "Uso: ./bin/pa3.out -d|-n|-k" << std::endl;
        return 1;
    }

    Grafo grafo;
    processaEntrada(grafo);

    int opt;
    while ((opt = getopt(argc, argv, "dnk")) != -1){
        switch(opt) {
        case 'd': {
            std::cout << grafo.QuantidadeVertices() << "\n"
                      << grafo.QuantidadeArestas() << "\n"
                      << grafo.GrauMinimo() << "\n"
                      << grafo.GrauMaximo() << "\n";
            break;
        }
        case 'n': {
            for (int i = 0; i < grafo.QuantidadeVertices(); i++) {
                grafo.ImprimeVizinhos(i);
            }
            break;
        }
        case 'k': {
            int n = grafo.QuantidadeVertices();
            int totalArestas = grafo.QuantidadeArestas();
            int maxArestas = n * (n - 1) / 2;
            std::cout << (totalArestas == maxArestas ? 1 : 0) << "\n";
            break;
        }
        default: {
            std::cerr << "Opção inválida! Uso: ./bin/pa3.out -d|-n|-k" << std::endl;
            return 1;
        }
        }
    }
    return 0;
}