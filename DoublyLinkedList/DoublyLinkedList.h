// Header guard prevents the multiple inclusions of the same file which could cause redefinition errors
// and compilation issues.
#ifndef DATASTRUCTURESANDALGORITHMS_DOUBLYLINKEDLIST_H
#define DATASTRUCTURESANDALGORITHMS_DOUBLYLINKEDLIST_H

#include <cstdio>
#include "iostream"
template<typename T>
class DoublyNode
{
public:
    T Value;

    DoublyNode<T>* Prev;
    DoublyNode<T>* Next;

    DoublyNode(T value);
};

template<typename T>
class DoublyLinkedList {
private:
    int m_count;

public:
    // Head node
    DoublyNode<T>* Head;

    // Tail node
    DoublyNode<T>* Tail;

    // Constructor
    DoublyLinkedList();

    // Get() operation
    DoublyNode<T>* Get(int index);

    // Insert operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search() operation
    int Search(T val);

    // Remove() operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    // Additional operation
    int Count();
    void PrintList();
    void PrintListBackward();
};


#endif //DATASTRUCTURESANDALGORITHMS_DOUBLYLINKEDLIST_H
