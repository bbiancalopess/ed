#include "../include/ArvoreBinaria.hpp"
#include <stdlib.h>
#include <iostream>

ArvoreBinaria::ArvoreBinaria() : raiz(NULL) {}

ArvoreBinaria::~ArvoreBinaria() {
    this->limpa();
}

void ArvoreBinaria::insere(int item) {
    this->raiz = this->insereRecursivo(this->raiz, item);
}

Node* ArvoreBinaria::insereRecursivo(Node* p, int item) {
    if (p == NULL) {
        p = new Node();
        p->item = item;
    } else {
        if (item < p->item)
            p->esq = this->insereRecursivo(p->esq, item);
        else
            p->dir = this->insereRecursivo(p->dir, item);
    }
    return p;
}

void ArvoreBinaria::preOrdem(Node* p) {
    if (p != NULL) {
        std::cout << p->item << " ";
        this->preOrdem(p->esq);
        this->preOrdem(p->dir);
    }
}

void ArvoreBinaria::inOrdem(Node* p) {
    if (p != NULL) {
        this->inOrdem(p->esq);
        std::cout << p->item << " ";
        this->inOrdem(p->dir);
    }
}

void ArvoreBinaria::posOrdem(Node* p) {
    if (p != NULL) {
        this->posOrdem(p->esq);
        this->posOrdem(p->dir);
        std::cout << p->item << " ";
    }
}

void ArvoreBinaria::limpa() {
    this->apagaRecursivo(this->raiz);
    raiz = NULL;
}

void ArvoreBinaria::apagaRecursivo(Node* p) {
    if (p != NULL) {
        this->apagaRecursivo(p->esq);
        this->apagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreBinaria::remove(int item) {
    this->raiz = this->removeRecursivo(this->raiz, item);
}

Node* ArvoreBinaria::removeRecursivo(Node* p, int item) {
    if (p == NULL)
        return NULL;
    
    if (item < p->item)
        p->esq = this->removeRecursivo(p->esq, item);
    else if (item > p->item)
        p->dir = this->removeRecursivo(p->dir, item);
    else {
        if (p->esq == NULL) {
            Node* temp = p->dir;
            delete p;
            return temp;
        } else if (p->dir == NULL) {
            Node* temp = p->esq;
            delete p;
            return temp;
        } else {
            Node* sucessor = this->encontraMinimo(p->dir);
            p->item = sucessor->item;
            p->dir = this->removeRecursivo(p->dir, sucessor->item);
        }
    }
    return p;
}

Node* ArvoreBinaria::encontraMinimo(Node* p) {
    while (p->esq != NULL) {
        p = p->esq;
    }
    return p;
}