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

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node(value);

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;
    cout << "Deleted element: " << temp->data << endl;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

void display() {
    Node* temp = front;

    if (temp == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue: ";
    display();

    dequeue();

    cout << "Queue after dequeue: ";
    display();

    return 0;
}
