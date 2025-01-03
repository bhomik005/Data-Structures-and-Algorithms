#include "DoublyLinkedList.h"

// constructor implementation of the Doubly Node
template<typename T>
DoublyNode<T>::DoublyNode(T value) : Value(value), Prev(nullptr), Next(nullptr) {}

// constructor implementation of the Doubly Linked List
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : m_count(0) {}


// removing the tail node of the list
template<typename T>
void DoublyLinkedList<T>::RemoveTail() {
    // potential edge cases
    // list has zero nodes - do nothing
    if(m_count == 0) return;

    // list has only one node
    if(m_count == 1) {
        // we want to grab the node
        DoublyNode<T>* node = Head;
        // point the head to the nullptr
        Head = nullptr;
        // point the tail to the nullptr
        Tail = nullptr;
        // delete the node
        delete* node;
        // decrement the m_count
        m_count--;
        return;
    }

    // list has two or more nodes
    // start from the tail node
    DoublyNode<T>* lastNode = Tail;
    // grab the prevNode and point the next to nullptr
    DoublyNode<T>* prevNode = Tail->Prev;
    prevNode->Next = nullptr;
    // point the tail to the prevNode
    Tail = prevNode;
    // delete the tail node
    delete* lastNode;
    // decrement the m_count
    m_count--;
}

// removing the head node of the list
template<typename T>
void DoublyLinkedList<T>::RemoveHead() {
    // potential edge cases
    // list has zero nodes - do nothing
    if(m_count == 0) return;

    // list has only one node
    if(m_count == 1) {
        // we want to grab the node
        DoublyNode<T>* node = Head;
        // point the head to the nullptr
        Head = nullptr;
        // point the tail to the nullptr
        Tail = nullptr;
        // delete the node
        delete* node;
        // decrement the m_count
        m_count--;
        return;
    }

    // list has two or more nodes
    // start from the head node
    DoublyNode<T>* headNode = Head;
    // point the head to the second node
    Head = Head->Next;
    // delete the first node
    delete* headNode;
    // decrement the m_count
    m_count--;
}

// fetch the node at the index value
template<typename T>
DoublyNode<T>* DoublyLinkedList<T>::Get(int index) {
    // check if the index is out of bounds
    if(index < 0 || index >= m_count) {
        return NULL;
    }
    // Start from the head node
    DoublyNode<T>* node = Head;

    // start iterating through the list till the index
    for(int i = 0; i < index; ++i) {
        node = node->Next;
    }
    // return the node
    return node;
}



// returns the count of elements in the list
template<typename T>
int DoublyLinkedList<T>::Count() {
    return m_count;
}

// prints the element of the list from start to end
template<typename T>
void DoublyLinkedList<T>::PrintList() {
    // Start from the head node
    DoublyNode<T>* node = Head;
    // iterate through the list and print the elements until the node is null
    while(node != NULL) {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }
    std::cout << "NULL" << "\n";
}

// print the list element from back to front
template<typename T>
void DoublyLinkedList<T>::PrintListBackward() {
    // Start from the tail node
    DoublyNode<T>* node = Tail;

    // iterate through the list and print the elements until the node is null
    while(node != NULL) {
        std::cout << node->Value << " -> ";
        node = node->Prev;
    }
    std::cout << "NULL" << "\n";
}
