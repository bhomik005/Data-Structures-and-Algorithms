#include "DoublyLinkedList.h"

// constructor implementation of the Doubly Node
template<typename T>
DoublyNode<T>::DoublyNode(T value) : Value(value), Prev(nullptr), Next(nullptr) {}

// constructor implementation of the Doubly Linked List
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : m_count(0) {}

// Insert operation

template<typename T>
void DoublyLinkedList<T>::InsertHead(T val) {
    // base case
    // if a list is empty - then make the node as Head and Tail both
    DoublyNode<T>* newNode = new DoublyNode<T>(val);
    if(m_count == 0) {
        Head = newNode;
        Tail = newNode;
        // one element is added in the list
        m_count++;
        return;
    }
    // store a reference to the head node
    DoublyNode<T>* node = Head;
    // create a new node with the val
    // make new node pointing to the first node
    newNode->Next = node;
    node->Prev = newNode;
    // make a head pointing to the new node
    Head = newNode;

    // one element is added
    m_count++;
}

template<typename T>
void DoublyLinkedList<T>::InsertTail(T val) {
    if(m_count == 0) {
        InsertHead(val);
        return;
    }

    DoublyNode<T>* newNode =  new DoublyNode<T>(val);
    // reference to the last node
    DoublyNode<T>* node = Tail;
    // make the last node points to the new Node
    node->Next = newNode;
    newNode->Prev = node;

    Tail = newNode;
    // one element is added
    m_count++;

}

template<typename T>
void DoublyLinkedList<T>::Insert(int index, T val) {
    // check if index is out of bounds
    if(index < 0 || index > m_count) {
        return;
    }

    // Inserting node at the start
    if(index == 0) {
        InsertHead(val);
        return;
    }
    // Inserting node at the last
    if(index == m_count) {
        InsertTail(val);
        return;
    }


    // Create a new node
    DoublyNode<T>* newNode = new DoublyNode<T>(val);

    // pointer to the node at index - 1
    DoublyNode<T>* prevNode = NULL;

    // pointer to the node at index
    DoublyNode<T>* node = Head;

    // iterate through the linked list
    for(int i = 0; i < index; ++i) {
        prevNode = node;
        node = node->Next;
    }
    prevNode->Next = newNode;
    newNode->Prev = prevNode;
    newNode->Next = node;
    node->Prev = newNode;

    // one element is added
    m_count++;
}



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
        delete node;
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
    delete lastNode;
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
        delete node;
        // decrement the m_count
        m_count--;

    }

    // list has two or more nodes
    // start from the head node
    DoublyNode<T>* headNode = Head;
    // point the head to the second node
    Head = Head->Next;
    // delete the first node
    delete headNode;
    // decrement the m_count
    m_count--;
}




template<typename T>
void DoublyLinkedList<T>::Remove(int index) {
    // if the list is empty
    if(m_count == 0) return;

    // index out of bounds
    if(index < 0 || index >= m_count) {
        return;
    }

    // if removing the current Head
    if(index == 0) {
        RemoveHead();
        return;
    }

    // if removing the current Tail
    if(index == m_count - 1) {
        RemoveTail();
        return;
    }

    // Start to traverse the list
    DoublyNode<T>* prevNode = Head;

    // Find the element before the selected index
    for(int i = 0; i < index - 1; ++i) {
        prevNode = prevNode->Next;
    }

    // The removed element is after the prev Node
    DoublyNode<T>* node = prevNode->Next;

    // The next node will be the neighbour once the node is removed
    DoublyNode<T>* nextNode = node->Next;

    // Link the prev node to the next node
    prevNode->Next = nextNode;

    nextNode->Prev = prevNode;

    delete node;

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

// Search the node with value V and return the index
template<typename T>
int DoublyLinkedList<T>::Search(T val) {

    // base check
    // if the list is empty - return -1
    if(m_count == 0) return -1;
    // start iterating through the list and if a node has a value V - return the index
    // have an index variable which increments each iteration


    // Start from the head node
    DoublyNode<T>* node = Head;
    int idx = 0;

    while(node->Value != val) {
        node = node->Next;
        idx++;
        if(node == NULL) {
            return -1;
        }
    }
    return idx;
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
