#include "../include/ArvoreBinaria.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    ArvoreBinaria arvore;

    for (int i = 0; i < n; i++) {
        char operacao;
        int valor;
        std::cin >> operacao >> valor;

        if (operacao == 'i') 
            arvore.insere(valor);
        else if (operacao == 'r')
            arvore.remove(valor);
    }

    arvore.preOrdem(arvore.raiz);
    std::cout << std::endl;

    arvore.inOrdem(arvore.raiz);
    std::cout << std::endl;
    
    arvore.posOrdem(arvore.raiz);
    std::cout << std::endl;
}