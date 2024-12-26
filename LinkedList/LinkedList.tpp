#include "LinkedList.h"

// Constructor
// initializing using the initializer list
template<typename T>
LinkedList<T>::LinkedList(): m_count(0) {}

// Get() operation - zero based indexing
// fetch the element at the index i
template<typename T>
Node<T>* LinkedList<T>::Get(int index){
    // index out of bounds
    if(index < 0 || index >= m_count) {
        return -1;
    }
    // Start from the Head node
    Node<T>* node = Head;

    // Iterate through the linked list elements
    for(int i = 0; i < index; ++i) {
        node = node->Next;
    }
    return node;
}


// Insert() operation
// insert the node at the front of the list
template<typename T>
void LinkedList<T>::InsertHead(T val) {
    // Create a new Node
    Node<T>* newNode = new Node<T>(val);

    newNode->Next = Head;
    Head = newNode;

    // if the linked list is empty
    // The tail is also the Head
    if(m_count == 0) {
        Tail = Head;
    }

}

template<typename T>
void LinkedList<T>::InsertTail(T val) {
    // if the list is empty
    if(m_count == 0) {
        InsertHead(val);
        return;
    }
    // Create a new node
    Node<T>* newNode = new Node<T>(val);

    Tail->Next = newNode;
    Tail = newNode;
    // one element is added
    m_count++;
}

template<typename T>
void LinkedList<T>::Insert(int index, T val) {
    // index out of bounds
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
    Node<T>* newNode = new Node<T>(val);

    // pointer to the node at index - 1
    Node<T>* prevNode = NULL;

    // pointer to the node at index
    Node<T>* node = Head;

    // iterate through the linked list
    for(int i = 0; i < index; ++i) {
        prevNode = node;
        node = node->Next;
    }
    prevNode->Next = newNode;
    newNode->Next = node;

    // one element is added
    m_count++;
}

// Search() operation
template<typename T>
int LinkedList<T>::Search(T val) {
    // if the list is empty
    if(m_count == 0) {
        return -1;
    }
    int idx = 0;

    // Start from the head node and have a reference to it
    Node<T>* node = Head;

    // iterating through the list until we found a node with the value
    while(node->Value != val) {
        node = node->Next;
        idx++;
        if(node == NULL){
            return -1;
        }
    }
    return idx; // return the index
}

// Remove() operation
template<typename T>
void LinkedList<T>::RemoveHead() {
    // if the list is empty
    if(m_count == 0) return;

    // Save the current head
    // to a new node
    Node<T>* node = Head;

    // Point the Head Pointer
    // to the element next to the current head
    Head = Head->Next;

    // Now it's safe to remove the first element
    delete node;

    // One element is removed
    m_count--;
}

template<typename T>
void LinkedList<T>::RemoveTail() {
    // if the list is empty
    if(m_count == 0) return;

    // If List element is only one
    // RemoveHead()
    if(m_count == 1) {
        RemoveHead();
        return;
    }

    // Start to find the previous node
    // from the head
    Node<T>* prevNode = Head;

    // the element next to the prev Node
    Node<T>* node = Head->Next;

    while(node->Next != NULL) {
        prevNode = prevNode->Next;
        node = node->Next;
    }

    prevNode->Next = NULL;
    Tail = prevNode;

    delete node;

    // One element is removed
    m_count--;

}

template<typename T>
void LinkedList<T>::Remove(int index) {

    // if the list is empty
    if(m_count == 0) return;

    // index out of bounds
    if(index < 0 || index > m_count) {
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
    Node<T>* prevNode = Head;

    // Find the element before the selected index
    for(int i = 0; i < index - 1; ++i) {
        prevNode = prevNode->Next;
    }

    // The removed element is after the prev Node
    Node<T>* node = prevNode->Next;

    // The next node will be the neighbour once the node is removed
    Node<T>* nextNode = node->Next;

    // Link the prev node to the next node
    prevNode->Next = nextNode;

    delete node;

    m_count--;


}

// Additional operation
template<typename T>
int LinkedList<T>::Count() {
    return m_count;
}

template<typename T>
void LinkedList<T>::PrintList() {
    // Starting from the Head node
    Node<T>* node = Head;

    // iterate through the end of the list
    while(node != NULL) {
        std::cout << node->Value << " ";
        node = node->Next;
    }
    std::cout << "\n";
}