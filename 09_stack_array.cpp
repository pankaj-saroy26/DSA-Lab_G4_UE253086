#include <iostream>
using namespace std;

const int SIZE = 100;
int stackArr[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    stackArr[top] = value;
}
void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Deleted element: " << stackArr[top] << endl;
    top--;
}
void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
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
