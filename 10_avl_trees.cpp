#include <iostream>
#include <algorithm>
using namespace std;

// AVL Tree with the height of a leaf node initialized to 1.
class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;

    public:
    Node(int value){
        data=value;
        left=right=NULL;
        height=1;
    }
};

// getHeight() - return the height of a node/tree.
int getHeight(Node* root){
    if(root == NULL) return 0;

    return root->height;
}

// getBalance() - calculate the balance factor of a node.
int getBalance(Node* root){
    if(root == NULL) return 0;

    return getHeight(root->left) - getHeight(root->right);
}

// LL case - right rotation.
Node* LL(Node* root){
    Node* newRoot = root->left;
    Node* subtree = newRoot->right;

    newRoot->right = root;
    root->left = subtree;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// RR case - left rotation.
Node* RR(Node* root){
    Node* newRoot = root->right;
    Node* subtree = newRoot->left;

    newRoot->left = root;
    root->right = subtree;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// LR case - left rotation on the left child, then right rotation.
Node* LR(Node* root){
    root->left = RR(root->left);
    return LL(root);
}

// RL case - right rotation on the right child, then left rotation.
Node* RL(Node* root){
    root->right = LL(root->right);
    return RR(root);
}

// Insert a value and return the updated root of this subtree.
Node* insert(Node* root, int value){
    if(root == NULL){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    else{
        return root; // Do not insert duplicate values.
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // LL case
    if(balance > 1 && value < root->left->data){
        return LL(root);
    }

    // RR case
    if(balance < -1 && value > root->right->data){
        return RR(root);
    }

    // LR case
    if(balance > 1 && value > root->left->data){
        return LR(root);
    }

    // RL case
    if(balance < -1 && value < root->right->data){
        return RL(root);
    }

    return root;
}

// Find the smallest node in a subtree.
Node* findMin(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

// Delete a value and return the updated root of this subtree.
Node* deleteNode(Node* root, int value){
    if(root == NULL){
        return root;
    }

    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else{
        // Node has no child or only a right child.
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Node has only a left child.
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node has two children: copy its inorder successor's value.
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // LL case
    if(balance > 1 && getBalance(root->left) >= 0){
        return LL(root);
    }

    // LR case
    if(balance > 1 && getBalance(root->left) < 0){
        return LR(root);
    }

    // RR case
    if(balance < -1 && getBalance(root->right) <= 0){
        return RR(root);
    }

    // RL case
    if(balance < -1 && getBalance(root->right) > 0){
        return RL(root);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;

    int size;
    cout << "Enter the size of the tree" << endl;
    cin >> size;

    for(int i=0; i<size; i++){
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int value;
    cout << "Enter the value to delete" << endl;
    cin >> value;
    root = deleteNode(root, value);

    cout << "Tree after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
