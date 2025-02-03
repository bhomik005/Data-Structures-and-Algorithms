
#ifndef DATASTRUCTURESANDALGORITHMS_DEQUE_H
#define DATASTRUCTURESANDALGORITHMS_DEQUE_H

template<typename T>
class DoublyNode
{
public:
    T Value;

    DoublyNode<T>* Prev;
    DoublyNode<T>* Next;

    DoublyNode(T value);
};

template <typename T>
class Deque
{
private:
    int m_count;
    DoublyNode<T>* m_front;
    DoublyNode<T>* m_back;

public:
    // public member functions

    Deque(); // constructor
    bool IsEmpty(); // return true if the elements are none
    T Front(); // fetch the front element's value
    T Back(); // fetch the back most element's value
    void EnqueueFront(T val); // insert a new element into the front side
    void EnqueueBack(T val); // insert a new element into the back side
    void DequeueFront(); // removing the element from the front side
    void DequeueBack(); // removing the element from the back side
};

#include "Deque.tpp"
#endif //DATASTRUCTURESANDALGORITHMS_DEQUE_H
