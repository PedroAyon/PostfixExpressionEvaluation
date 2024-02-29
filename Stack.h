//
// Created by pedro on 27/02/2024.
//

#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <vector>

template<typename T>
class Stack {
    std::vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        T top_element = elements.back();
        elements.pop_back();
        return top_element;
    }

    T& top() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    // Return the number of elements in the stack
    size_t size() const {
        return elements.size();
    }
};

#endif //PILA_H
