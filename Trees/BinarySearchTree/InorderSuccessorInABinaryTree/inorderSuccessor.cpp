#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    Node *parent;
};

Node* newNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int value)
{
    if (root == NULL) {
        root = newNode(value);
    }
    else if (root->value >= value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* Find(Node* root, int key)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->value == key) {
        return root;
    } else if (root->value >= key) {
        return Find(root->left, key);
    } else {
        return Find(root->right, key);
    }
}

int findMin(Node* root)
{
    if (root->left == NULL) {
        return root->value;
    } else {
        return findMin(root->left);
    }
}

int inorderSuccessor(Node* root, int key)
{
    Node* current = Find(root, key);

    if (current == NULL) {
        return -1;
    }
    if (current->right != NULL) {
        return findMin(current->right);
    } else {
        Node* parent = NULL;
        Node* child = root;

        while (child != current) {
            if (child->value > key) {
                parent = child;
            }
            if (child->value >= current->value) {
                child = child->left;
            } else {
                child = child->right;
            }
        }

        if (parent == NULL) {
            return -2;
        }
        return parent->value;
    }
}

void infixDisplay(Node* root) {
    if (root == NULL) {
        return;
    }
    infixDisplay(root->left);
    cout << root->value << " ";
    infixDisplay(root->right);
}

int main(int argc, char const *argv[]) {
    Node* root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 11);
    root = insert(root, 20);
    root = insert(root, 17);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 27);

    int y;
    cin >> y;
    while (y != -1) {
        int x = inorderSuccessor(root, y);
        cout << "InorderSuccessor of "<< y << " :- " << x;
        cin >> y;
    }

    cout << endl;
    infixDisplay(root);
    cout << endl;

    return 0;
}
