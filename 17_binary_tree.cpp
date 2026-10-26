#include <iostream>
using namespace std;
//Creating Node 
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        
    }
};

// Insertion
Node* insert(Node* root, int n) {
    if (root == NULL)
        return new Node(n);

    if (n < root->data) {
        root->left = insert(root->left, n);
        root->left->parent = root;
    }
    else {
        root->right = insert(root->right, n);
        root->right->parent = root;
    }

    return root;
}
//Deletion
Node* deleteNode(Node* root, int n) {
    if (root == NULL)
        return root;
    if (n < root->data)
        root->left = deleteNode(root->left, n);
    else if (n > root->data)
        root->right = deleteNode(root->right, n);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp != NULL)
                temp->parent = root->parent;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            if (temp!= NULL)
                temp->parent = root->parent;
            return temp;
        }
    }
    return root;
}
//All three traversals in Binary Tree
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(9);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->parent = root;
    root->right->parent = root;
    inorder(root);
    Node* n1 = insert(root, 7);
cout<<endl;
    preorder(root);
    Node* n2= insert(root, 2);
cout<<endl;
    postorder(root);
    Node* n3 = deleteNode(root, 5);
    cout<<endl;
    inorder(root);
    return 0;
}
