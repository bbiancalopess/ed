#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.hpp"
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (std::cin.fail() || n <= 0) {
        std::cerr << "Erro: O número de elementos deve ser um inteiro positivo.\n";
        return 1;
    }

    Heap heap(n);

    // Insere os elementos no heap
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        if (std::cin.fail()) {
            std::cerr << "Erro: Entrada inválida. Certifique-se de digitar valores inteiros.\n";
            return 1;
        }

        try {
            heap.Inserir(x);
        } catch (const std::overflow_error& e) {
            std::cerr << "Erro: " << e.what() << '\n';
            return 1;
        }
    }

    // Remove os elementos do heap e os imprime
    while(!heap.Vazio()) {
        std::cout << heap.Remover() << (heap.Vazio() ? "\n" : " ");
    }

    heap.~Heap();

    return 0;
}