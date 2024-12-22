#ifndef CELULA_HPP
#define CELULA_HPP

#include <stdio.h>

template<typename T>
class Celula {
public:
    Celula();
private:
    T item;
    Celula *prox;

template<typename U>
friend class Lista;
};

#include "../src/Celula.cpp"
#endif