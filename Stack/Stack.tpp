#include "Stack.h"

// constructor implementation
template<typename T>
Stack<T>::Stack() : m_count(0), m_top(nullptr) {}

// return true if the stack is empty
template<typename T>
bool Stack<T>::IsEmpty() {
    // check the m_count
    // return true if there are no elements in the stack
    return m_count <= 0;
}

// return the value top most / last inserted element of the stack
template<typename T>
T Stack<T>::Top() {
    // check if the m_count is greater than 0 and return the value
    // of the top most element
    if (m_count > 0) return m_top->Value;
    return NULL;
}

template<typename T>
void Stack<T>::Push(T val) {
    // push the element on the top
    // create a Node with value val
    Node<T> *node = new Node<T>(val);

    // make the node next ptr pointing to the top node
    node->Next = m_top;
    // then make the new node as top node
    m_top = node;
    // increment the m_count
    m_count++;
}

template<typename T>
void Stack<T>::Pop() {
    if (IsEmpty()) {
        return;
    }
    Node<T> *node = m_top;
    m_top = node->Next;
    delete node;
    m_count--;
}
