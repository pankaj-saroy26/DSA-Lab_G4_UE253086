#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;
    cout << "Deleted element: " << temp->data << endl;
    top = top->next;
    delete temp;
}

void display() {
    Node* temp = top;

    if (temp == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Stack: ";
    display();

    pop();

    cout << "Stack after pop: ";
    display();

    return 0;
}
