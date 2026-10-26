#include <iostream>
using namespace std;

const int SIZE = 100;
int queueArr[SIZE];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }

    rear++;
    queueArr[rear] = value;
}

void dequeue() {
    if (front > rear) {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Deleted element: " << queueArr[front] << endl;
    front++;
}

void display() {
    if (front > rear) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
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
