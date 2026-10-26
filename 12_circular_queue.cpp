#include <iostream>
using namespace std;

const int SIZE = 5;
int queueArr[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }

    queueArr[rear] = value;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Deleted element: " << queueArr[front] << endl;

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    int i = front;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << "Circular Queue: ";
    display();

    dequeue();
    enqueue(50);

    cout << "Queue after dequeue and enqueue: ";
    display();

    return 0;
}
