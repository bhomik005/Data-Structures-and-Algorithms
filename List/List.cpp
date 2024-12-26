#include "List.h"

// constructor
List::List() : m_count(0), m_items(nullptr) {}

// destructor
List::~List() {
    delete[] m_items;
    m_items = nullptr;
}

// fetches the element at the index if it exists, else return -1
int List::Get(int index) {
    // check if index is out of bounds
    if(index < 0 || index >= m_count) {
        return - 1;
    }
    // access the element by passing in the index
    return m_items[index]; // O(1) time
}

// inserts the element of value v at the index i
void List::Insert(int index, int value) {
    if(index < 0 || index > m_count) {
        return;
    }
    // store the copy of the array first
    int* oldArray = m_items;

    // increment the m_count
    m_count++;

    // create a new memory for m_items with new m_count
    m_items = new int[m_count];

    // O(N) time
    for(int i = 0, j = 0; i < m_count; ++i) {
        if(i == index) {
            m_items[i] = value;
        } else {
            m_items[i] = oldArray[j];
            j++;
        }
    }
    delete[] oldArray;
}

// removes the element in the index i
void List::Remove(int index) {
    if(index < 0 || index > m_count) {
        return;
    }

    // store the copy of the array first
    int* oldArray = m_items;

    // decrement the m_count
    m_count--;

    // create a new memory for m_items with new m_count
    m_items = new int[m_count];

    // O(N) time
    for(int i = 0, j = 0; i < m_count; ++i) {
        if(i == index) {
            j++;
        }
        m_items[i] = oldArray[j];
        j++;
    }
    delete[] oldArray;
}

// returns the first occurrence of the value v (if the value doesn’t exist, the return value is -1)
int List::Search(int value) {
    // iterate over the elements and return the index
    // O(n) time
    for(int i = 0; i < m_count; ++i) {
        if(m_items[i] == value) return i;
    }
    // if the value does not exist - return -1
    return -1;
}

// returns the count of number of elements in the list
int List::Count() {
    return m_count;
}