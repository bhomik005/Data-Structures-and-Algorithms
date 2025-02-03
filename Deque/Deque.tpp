#include <cstdlib>
#include "Deque.h"

template<typename T>
DoublyNode<T>::DoublyNode(T value): Value(value), Prev(nullptr), Next(nullptr) {}

// a constructor initializer list to initialize the member variables
template<typename T>
Deque<T>::Deque(): m_count(0), m_front(nullptr), m_back(nullptr) {}
template<typename T>
bool Deque<T>::IsEmpty() {
    // return true if
    // member count is 0
    return m_count == 0;
}

template<typename T>
T Deque<T>::Front() {
    // fetch the front element's value
    if(m_count == 0) return NULL;
    return m_front->Value;
}

template<typename T>
T Deque<T>::Back() {
    // fetch the back element's value
    if(m_count == 0) return NULL;
    return m_back->Value;
}

// insert a new element to the front side
template<typename T>
void Deque<T>::EnqueueFront(T val)
{
    DoublyNode<T>* node = new DoublyNode<T>(val);

    node->Next = m_front;

    if(m_front != NULL)
        m_front->Prev = node;
    m_front = node;

    if(m_count == 0)
        m_back = m_front;
    // increment the count
    m_count++;
}

template<typename T>
void Deque<T>::EnqueueBack(T val) {
    if(m_count == 0) {
        EnqueueFront(val);
        return;
    }
    DoublyNode<T>* node = new DoublyNode<T>(val);
    m_back->Next = node;
    node->Prev = m_back;
    m_back = node;
    // increment the count
    m_count++;
}

template<typename T>
void Deque<T>::DequeueFront()
{
    if (m_count == 0) {
        return;
    }
    // grab the front node
    DoublyNode<T>* node = m_front;
    // move the m_front to the front node -> next
    m_front = m_front->Next;
    delete node;

    if(m_front != NULL)
        m_front->Prev = NULL;
    // One element is removed
    m_count--;

}

template<typename T>
void Deque<T>::DequeueBack()
{
    if(m_count == 0) {
        return;
    }

    if(m_count == 1) {
        DequeueFront();
        return;
    }

    DoublyNode<T>* node = m_back;

    m_back = m_back->Prev;
    m_back->Next = NULL;
    delete node;
    m_count--;
}
