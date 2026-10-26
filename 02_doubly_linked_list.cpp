
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};


void insertAtBeginning(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {          // empty list
        head = tail = newNode;
    } else {
        newNode->next = head;       // new node -> old head
        head->prev = newNode;       // old head -> new node
        head = newNode;
    }
}

void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {          
        head = tail = newNode;
    } else {
        tail->next = newNode;      
        newNode->prev = tail;       
        tail = newNode;
    }
}

// ---------- DELETE (first node with this value) ----------
void deleteValue(Node*& head, Node*& tail, int value) {
    Node* current = head;

    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << value << " not found.\n";
        return;
    }

    if (current == head && current == tail) {   // only one node
        head = tail = nullptr;
    } else if (current == head) {               // first node
        head = head->next;
        head->prev = nullptr;
    } else if (current == tail) {               // last node
        tail = tail->prev;
        tail->next = nullptr;
    } else {                                    // middle node
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << value << " deleted.\n";
}


int search(Node* head, int value) {
    int index = 0;
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data == value) return index;
        index++;
    }
    return -1;
}


void display(Node* head) {
    cout << "List: NULL <-> ";
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " <-> ";
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;   // first node
    Node* tail = nullptr;   // last node

    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtBeginning(head, tail, 5);
    display(head);                          // 5 <-> 10 <-> 20

    cout << "20 is at position " << search(head, 20) << "\n";

    deleteValue(head, tail, 10);
    display(head);                          // 5 <-> 20

    return 0;               
}
