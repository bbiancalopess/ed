#include "../include/ArvoreBinaria.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void reproduz(ArvoreBinaria* arvore, int p, int valor) {
    if (p == 1) {
        //std::cout << "I " << valor << std::endl;
        arvore->insere(valor);
    } else {
        //std::cout << "R " << valor << std::endl;
        arvore->remove(valor);
    }
    /*
    arvore->preOrdem(arvore->raiz);
    std::cout << std::endl;
    arvore->inOrdem(arvore->raiz);
    std::cout << std::endl;
    arvore->posOrdem(arvore->raiz);
    std::cout << std::endl;
    std::cout << std::endl;
    */
}

int main() {
    /*int n;
    std::cin >> n;
*/
    ArvoreBinaria arvore;
/*
    for (int i = 0; i < n; i++) {
        char operacao;
        int valor;
        std::cin >> operacao >> valor;

        if (operacao == 'i') 
            arvore.insere(valor);
        else if (operacao == 'r')
            arvore.remove(valor);
    }
*/
    reproduz(&arvore, 1, 3789);
    reproduz(&arvore, 1, 1498);
    reproduz(&arvore, 0, 1498);
    reproduz(&arvore, 0, 3789);
    reproduz(&arvore, 1, 5876);
    reproduz(&arvore, 0, 5876);
    reproduz(&arvore, 1, 9594);
    reproduz(&arvore, 1, 1734);
    reproduz(&arvore, 0, 1734);
    reproduz(&arvore, 0, 9594);
    reproduz(&arvore, 1, 4371);
    reproduz(&arvore, 0, 4371);
    reproduz(&arvore, 1, 3889);
    reproduz(&arvore, 1, 5586);
    reproduz(&arvore, 1, 353);
    reproduz(&arvore, 0, 3889);
    reproduz(&arvore, 1, 9444);
    reproduz(&arvore, 1, 707);
    reproduz(&arvore, 1, 2496);
    reproduz(&arvore, 0, 353);
    reproduz(&arvore, 1, 4978);
    reproduz(&arvore, 1, 5653);
    reproduz(&arvore, 1, 8418);
    reproduz(&arvore, 0, 5586);
    reproduz(&arvore, 0, 707);
    reproduz(&arvore, 1, 9837);
    reproduz(&arvore, 0, 4978);
    reproduz(&arvore, 1, 671);
    reproduz(&arvore, 1, 8438);
    reproduz(&arvore, 1, 1149);
    reproduz(&arvore, 1, 7316);
    reproduz(&arvore, 0, 671);
    reproduz(&arvore, 1, 2194);
    reproduz(&arvore, 1, 8488);
    reproduz(&arvore, 1, 6755);
    reproduz(&arvore, 0, 6755);
    reproduz(&arvore, 1, 1407);
    reproduz(&arvore, 0, 1407);
    reproduz(&arvore, 0, 1149);
    reproduz(&arvore, 0, 8488);
    reproduz(&arvore, 1, 3349);
    reproduz(&arvore, 1, 8996);
    reproduz(&arvore, 1, 9279);
    reproduz(&arvore, 0, 9279);
    reproduz(&arvore, 1, 6366);
    reproduz(&arvore, 0, 9444);
    reproduz(&arvore, 1, 5643);
    reproduz(&arvore, 0, 8438);
    reproduz(&arvore, 1, 391);
    reproduz(&arvore, 0, 5643);
    reproduz(&arvore, 1, 1513);
    reproduz(&arvore, 1, 6345);
    reproduz(&arvore, 1, 1288);
    reproduz(&arvore, 0, 8418);
    reproduz(&arvore, 1, 4472);
    reproduz(&arvore, 0, 5653);
    reproduz(&arvore, 1, 314);
    reproduz(&arvore, 1, 7311);
    reproduz(&arvore, 1, 8396);
    reproduz(&arvore, 0, 1288);
    reproduz(&arvore, 0, 2496);
    reproduz(&arvore, 0, 7316);
    reproduz(&arvore, 0, 6345);
    reproduz(&arvore, 1, 5708);
    reproduz(&arvore, 1, 8566);
    reproduz(&arvore, 0, 391);
    reproduz(&arvore, 0, 1513);
    reproduz(&arvore, 0, 8396);
    reproduz(&arvore, 0, 3349);
    reproduz(&arvore, 1, 290);
    reproduz(&arvore, 1, 2975);
    reproduz(&arvore, 1, 15);
    reproduz(&arvore, 1, 1488);
    reproduz(&arvore, 0, 314);
    arvore.preOrdem(arvore.raiz);
    std::cout << std::endl;
    arvore.inOrdem(arvore.raiz);
    std::cout << std::endl;
    arvore.posOrdem(arvore.raiz);
    std::cout << std::endl;
    std::cout << std::endl;
}