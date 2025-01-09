//
// Created by bhomik kinger on 9/1/2025.
//

#ifndef DATASTRUCTURESANDALGORITHMS_QUEUE_H
#define DATASTRUCTURESANDALGORITHMS_QUEUE_H

#include <cstddef>
template<typename T>
class Node {
public:
    T Value;
    Node<T>* Next;

    Node(T value): Value(value), Next(nullptr) {}
};

template<typename T>
class Queue {
private:
    int m_count;
    Node<T>* m_front;
    Node<T>* m_back;

public:
    Queue();
    bool IsEmpty();
    T Front();
    void Enqueue(T val);
    void Dequeue();
};

#include "Queue.tpp"

#endif //DATASTRUCTURESANDALGORITHMS_QUEUE_H
