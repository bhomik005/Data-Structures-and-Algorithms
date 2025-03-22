/*
 * Node is a basic building block of many data structures in C++
 * A node has a value and a pointer to the next node
 * With node, we can implement many data structures like singly and doubly linked list, stack, queue, deque
 */
#include <iostream>

using namespace std;

class Node {
public:
    int Value;
    Node * Next;

    // constructor
    Node(int val) : Value(val), Next(nullptr) {}
};

// 1 -> 2 -> 3 -> 4 -> NULL
// O(n) time - n is the number of node elements
void PrintNode(Node * node) {
    // It will print the initial node
    // until it finds the null for the next pointer
    while(node != NULL) {
        cout << node->Value << " -> ";
        node = node->Next;
    }
    cout << "NULL";
}

int main() {
    Node * node1 = new Node(1);
    Node * node2 = new Node(2);
    Node * node3 = new Node(3);
    Node * node4 = new Node(4);
    // let's connect these nodes together - Node chaining
    node1->Next = node2;
    node2->Next = node3;
    node3->Next = node4;

    PrintNode(node1);

    return 0;
}