#ifndef DATASTRUCTURESANDALGORITHMS_LIST_H
#define DATASTRUCTURESANDALGORITHMS_LIST_H


class List {
private:
    int m_count; // stores the count of elements in the list
    int* m_items; // a pointer to the array of elements

public:
    List(); // constructor
    ~List(); // destructor
    int Get(int index); // fetches the element at the index if it exists, else return -1
    void Insert(int index, int value); // inserts the element of value v at the index i
    void Remove(int index); // removes the element in the index i
    int Search(int value); // returns teh first occurrence of the value v (if the value doesn’t exist, the return value is -1)
    int Count(); // returns the count of number of elements in the list
};

#endif //DATASTRUCTURESANDALGORITHMS_LIST_H
