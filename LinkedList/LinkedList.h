#ifndef DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H
#define DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H

#include <iostream>
#include <cstddef>


template<typename T>
class Node {
public:
    T Value;
    Node<T>* Next;

    Node(T value): Value(value), Next(nullptr) {}
};


template<typename T>
class LinkedList {
private:
    int m_count;

public:
    // The first node in the list
    // or null if empty
    Node<T>* Head;

    // The last node in the list
    // or null if empty
    Node<T>* Tail;

    // Constructor
    LinkedList();

    // Get() operation
    Node<T>* Get(int index);

    // Insert() operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search() operation
    int Search(T val);

    // Remove() operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    // Additonal operation
    int Count();
    void PrintList();
};

#include "LinkedList.tpp"
#endif //DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H
