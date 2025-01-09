//
// Created by bhomik kinger on 9/1/2025.
//

#include "Queue.h"

template<typename T>
Queue<T>::Queue() : m_count(0), m_front(nullptr), m_back(nullptr) {}

template<typename T>
bool Queue<T>::IsEmpty() {
    // if m_count is less than or equal to 0
    // return true else return false
    return m_count <= 0;
}

template<typename T>
T Queue<T>::Front() {
    // Just return the value of the
    // m_front node
    return m_front->Value;
}

template<typename T>
void Queue<T>::Enqueue(T val) {
    // insert from the back
    // make use of m_back pointer - pointing to the last element
    Node<T>* node = new Node<T>(val);
    if(m_count == 0) {
        m_front = node;
        m_back = node;
        m_count++;
        return;
    }

    m_back->Next = node;
    m_back = node;
    m_count++;

}

template<typename T>
void Queue<T>::Dequeue() {
    if(m_count == 0) return;
    Node<T>* node = m_front;
    m_front = m_front->Next;
    delete node;
    m_count--;
}