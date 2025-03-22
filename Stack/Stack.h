/*
 * A stack is a data structure which follows the last in first out principle. The insertions and removal can only
 * be done from one end. In the real life, a stack can be visualized as a stack of plates - the element which inserts
 * most recent is the element that will come out first.
 * Stack implementation using the singly linked list
 */
#ifndef DATASTRUCTURESANDALGORITHMS_STACK_H
#define DATASTRUCTURESANDALGORITHMS_STACK_H
#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node * next;
    Node(T val) : value(val), next(nullptr) {}
};

template<typename T>
class Stack {
private:
    int m_count; // number of elements in the stack
    Node<T> * m_top; // refers to the topmost element of the stack

public:
    bool isEmpty();
    T Top();
    void Push(T val);
    void Pop();
};

#include "Stack.tpp" // Include template implementation

#endif //DATASTRUCTURESANDALGORITHMS_STACK_H
