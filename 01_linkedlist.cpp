#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* convert(vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* temp = head;

    for (int i = 1; i < values.size(); i++) {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int length(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

bool search(Node* head, int value) {
    while (head != nullptr) {
        if (head->data == value) return true;
        head = head->next;
    }
    return false;
}

// Positions start from 1. Insert at the end with position length(head) + 1.
Node* insert(Node* head, int value, int position) {
    if (position < 1) return head;

    if (position == 1) {
        Node* newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return head;

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Positions start from 1.
Node* deletion(Node* head, int position) {
    if (head == nullptr || position < 1) return head;

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 1; temp->next != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) return head;

    Node* removed = temp->next;
    temp->next = removed->next;
    delete removed;
    return head;
}

int main() {
    vector<int> values = {5, 2, 9, 1};
    Node* head = convert(values);

    head = insert(head, 3, 1);                 // insert at head
    head = insert(head, 8, length(head) + 1);  // insert at tail
    head = insert(head, 7, 3);                 // insert at position 3
    print(head);

    cout << "Length: " << length(head) << endl;
    cout << "Search 9: " << (search(head, 9) ? "Found" : "Not found") << endl;

    head = deletion(head, 1);                  // delete head
    head = deletion(head, length(head));       // delete tail
    head = deletion(head, 2);                  // delete position 2
    print(head);

    deleteList(head);
    return 0;
}
