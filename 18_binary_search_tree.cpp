#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *create(int value)
{
    Node *newNode = new Node(value);
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

Node *search(Node *root, int key)
{
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
    {
        Node *leftsearch = search(root->left, key);
        return leftsearch;
    }

    else
    {
        Node *rightsearch = search(root->right, key);
        return rightsearch;
    }
}

Node *deletebst(Node *root, int n)
{
    // If tree is empty
    if (root == nullptr)
        return nullptr;

    // Search in left subtree
    if (n < root->data)
    {
        root->left = deletebst(root->left, n);
        return root;
    }

    // Search in right subtree
    if (n > root->data)
    {
        root->right = deletebst(root->right, n);
        return root;
    }

    // Node found

    // Case 1: No child
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

    // Case 2: Only right child
    if (root->left == nullptr)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }

    // Case 2: Only left child
    if (root->right == nullptr)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }

    // Case 3: Two children
    Node *temp = root->right;

    
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }

    
    root->data = temp->data;

   
    root->right = deletebst(root->right, temp->data);

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;

    int size;
    cout << "Enter the number of nodes: ";
    cin >> size;

    cout << "Enter the values: ";

    for (int i = 0; i < size; i++)
    {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int key;
    cout << "Enter the value to be deleted: ";
    cin >> key;

    root = deletebst(root, key);

    cout << "Tree after deletion: ";
    inorder(root);

    return 0;
}
