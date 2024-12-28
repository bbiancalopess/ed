#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    Node();

private:
    int item;
    Node *esq;
    Node *dir;

    friend class ArvoreBinaria;
};

#endif