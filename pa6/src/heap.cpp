#include "../include/heap.hpp"
#include <utility>
#include <stdexcept>

Heap::Heap(int maxsize) {
    if (maxsize <= 0)
        throw std::invalid_argument("O tamanho do heap deve ser maior que zero.");
    this->data = new int[maxsize];
    this->tamanho = 0;
}

Heap::~Heap() {
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL;
    }
}

void Heap::Inserir(int x) {
    // Insere o elemento no final
    this->data[this->tamanho] = x;
    int i = this->tamanho;
    this->tamanho++;

    int p = this->GetAncestral(i);
    while(i > 0 && this->data[i] < this->data[p]) {
        std::swap(this->data[i], this->data[p]);
        i = p;
        p = this->GetAncestral(i);
    }
    
}

int Heap::Remover() {
    if (this->Vazio()) {
        throw std::out_of_range("O heap está vazio.");
    }
    
    int minElement = this->data[0];
    this->data[0] = this->data[this->tamanho - 1];
    this->tamanho--;

    // Para implementar o heapify recursivo, comente da linha 44 a linha 58 e descomente a linha 42

    // this->HeapifyPorBaixo(0);

    int i = 0;
    // Continua no while até que a propriedade do min-heap (menor valor no topo) seja restaurada
    while (true) {
        int esq = this->GetSucessorEsq(i);
        int dir = this->GetSucessorDir(i);
        int menor = i;

        if (esq < this->tamanho && this->data[esq] < this->data[menor]) {
            menor = esq;
        }
        if (dir < this->tamanho && this->data[dir] < this->data[menor]) {
            menor = dir;
        }
        if (menor == i) {
            break;
        }

        std::swap(this->data[i], this->data[menor]);
        i = menor;
    }
    return minElement;
}

bool Heap::Vazio() {
    return this->tamanho == 0;
}

int Heap::GetAncestral(int posicao) {
    return (posicao - 1)/2;
}
int Heap::GetSucessorEsq(int posicao) {
    return 2 * posicao + 1;
}
int Heap::GetSucessorDir(int posicao) {
    return 2 * posicao + 2;
}

void Heap::HeapifyPorBaixo(int posicao) {
    int esq = this->GetSucessorEsq(posicao);
    int dir = this->GetSucessorDir(posicao);
    int menor = posicao;

    if (esq < this->tamanho && this->data[esq] < this->data[menor])
        menor = esq;
    if (dir < this->tamanho && this->data[dir] < this->data[menor])
        menor = dir;

    if (menor != posicao) {
        std::swap(this->data[posicao], this->data[menor]);
        this->HeapifyPorBaixo(menor);
    }
}
void Heap::HeapifyPorCima(int posicao) {
    if (posicao > 0) {
        int p = this->GetAncestral(posicao);
        if (this->data[posicao] < this->data[p]) {
            std::swap(this->data[posicao], this->data[p]);
            this->HeapifyPorCima(p);
        }
    }
}