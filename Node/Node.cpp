#include<iostream>

using namespace std;

// Node ADT
class Node {
public:
    int value;
    Node* next;
};

void PrintNode(Node* node) {
    while(node != NULL) {
        cout << node->value << " -> ";
        node = node->next;
    }
    cout << "NULL";
    cout << "\n";
}

int main() {
    // Have a bunch of nodes
    Node* node1 = new Node; // new keyword
    node1->value = 10;

    Node* node2 = new Node;
    node2->value = 20;

    Node* node3 = new Node;
    node3->value = 30;

    Node* node4 = new Node;
    node4->value = 40;

    // connecting the nodes or creating a node chain
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;


    // 10 -> 20 -> 30 -> 40 -> NULL
    PrintNode(node1);
    return 0;
}