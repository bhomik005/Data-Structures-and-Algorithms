#include "Stack.h"
template<typename T>
bool Stack<T>::isEmpty() {
    // returns true if the member count is zero or less than zero
    return m_count <= 0;
}

template<typename T>
T Stack<T>::Top() {
    // peeks the top most element of the stack
    return m_top->value;
}

// 1 -> 2 -> 3
// ^
// m_top
template<typename T>
void Stack<T>::Push(T val) {
    // create a node with a value
    Node<T> * node = new Node<T>(val);

    // insert the node at the front of the top most node
    node->next = m_top;

    // and make this as a new top
    m_top = node;

    // increment the m_count
    m_count++;
}

template<typename T>
void Stack<T>::Pop() {
    // do nothing if the stack is empty
    if(this->isEmpty()) return;

    // capture the top node for the later deletion
    Node<T> * top = m_top;

    // make the m_top pointing to the next of m_top
    m_top = m_top->next;

    // decrement the m_count
    m_count--;

    // safely delete the top most node
    delete top;
}