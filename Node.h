//
// Created by pedro on 27/02/2024.
//

#ifndef NODO_H
#define NODO_H

#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    explicit Node() : data(nullptr), left(nullptr), right(nullptr) {}
    explicit Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
void printInorder(Node<T> *node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);

    std::cout << node->data << " ";

    printInorder(node->right);
}

template<typename T>
void printPreorder(Node<T> *node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}

template<typename T>
std::string postOrder(Node<T> *node) {
    if (node == nullptr) {
        return "";
    }
    return postOrder(node->left) + postOrder(node->right) + node->data;
}

#endif //NODO_H
