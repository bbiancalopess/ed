#include "../include/Lista.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<typename T>
Lista<T>::Lista() {
    primeiro = new Celula<T>();
    ultimo = primeiro;
    tamanho = 0;
}

template<typename T>
Lista<T>::~Lista() {
    limpa();
    if (primeiro != NULL)
        delete primeiro;
}

template<typename T>
Celula<T>* Lista<T>::posiciona(int pos, bool antes) {
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao inválida!";
    
    Celula<T> *p = primeiro;
    for (int i = 1; i < pos; i++) {
        p = p->prox;
    }

    if (!antes)
        p = p->prox;

    return p;
}

template<typename T>
T Lista<T>::getItem(int pos){
    Celula<T> *p = posiciona(pos);
    return p->item;
}

template<typename T>
void Lista<T>::setItem(T item, int pos){
    Celula<T> *p = posiciona(pos);
    p->item = item;
}

template<typename T>
void Lista<T>::insereInicio(T item) {
    Celula<T> *nova = new Celula<T>();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if (nova->prox == NULL)
        ultimo = nova;
}

template<typename T>
void Lista<T>::insereFinal(T item) {
    Celula<T> *nova = new Celula<T>();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
}

template<typename T>
void Lista<T>::inserePosicao(T item, int pos) {
    Celula<T> *p = posiciona(pos,true); // posiciona na célula anterior
    Celula<T> *nova = new Celula<T>();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if(nova->prox == NULL)
        ultimo = nova;
}

template<typename T>
T Lista<T>::removeInicio() {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    Celula<T> *p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;

    if (primeiro->prox == NULL)
        ultimo = primeiro;
    T aux = p->item;
    delete p;
    return aux;
}

template<typename T>
T Lista<T>::removeFinal() {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    Celula<T> *p = posiciona(tamanho, true);

    T aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    ultimo->prox = NULL;
    tamanho--;

    return aux;
}

template<typename T>
T Lista<T>::removePosicao(int pos) {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
       
    Celula<T> *p = posiciona(pos, true);
    Celula<T> *q = p->prox;
    p->prox = q->prox;
    tamanho--;
    
    T aux = q->item;
    delete q;

    if (p->prox == NULL)
        ultimo = p;
    return aux;
}

template<typename T>
T Lista<T>::pesquisa(T c) {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    Celula<T> *p = primeiro->prox;
    while (p != NULL) {
        if (p->item == c) {
            return p->item;
        }
        p = p->prox;
    }

    throw "ERRO: Item nao encontrado!";
}

template<typename T>
void Lista<T>::imprime() {
    Celula<T> *p = primeiro->prox;

    while (p != NULL) {
        std::cout << p->item << " ";
        p = p->prox;
    }

    std::cout << "\n";
}

template<typename T>
void Lista<T>::limpa() {
    Celula<T> *p = primeiro->prox;

    while (p != NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

template<typename T>
int Lista<T>::getTamanho() {
    return tamanho;
}