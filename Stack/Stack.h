//
// Created by bhomik kinger on 8/1/2025.
//

#ifndef DATASTRUCTURESANDALGORITHMS_STACK_H
#define DATASTRUCTURESANDALGORITHMS_STACK_H
#include <cstddef>
template<typename T>
class Node {
public:
    T Value;
    Node<T>* Next;

    Node(T value): Value(value), Next(nullptr) {}
};


template<typename T>
class Stack {
private:
    int m_count;
    Node<T>* m_top;

public:
    Stack();
    bool IsEmpty();
    T Top();
    void Push(T val);
    void Pop();
};
#include "Stack.tpp"
#endif //DATASTRUCTURESANDALGORITHMS_STACK_H
