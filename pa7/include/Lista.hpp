#ifndef LISTA_HPP
#define LISTA_HPP

#include "../include/Celula.hpp"

template<typename T>
class Lista {
public:
    Lista();
    ~Lista();

    T getItem(int pos);
    void setItem(T item, int pos);
    void insereInicio(T item);
    void insereFinal(T item);
    void inserePosicao(T item, int pos);
    T removeInicio();
    T removeFinal();
    T removePosicao(int pos);
    T pesquisa(T c);
    void imprime();
    void limpa();
    int getTamanho();
private:
    Celula<T>* primeiro;
    Celula<T>* ultimo;
    Celula<T>* posiciona(int pos, bool antes);
    int tamanho;
};

#endif