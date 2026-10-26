#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void insertEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void displayForward(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void displayBackward(Node* tail) {
    while (tail != NULL) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertEnd(head, tail, value);
    }

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(tail);

    return 0;
}
