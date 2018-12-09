#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node* temp = new Node();
    //Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* insert(Node* root, int value)
{
    Node *temp = newNode(value);

    if (root == NULL) {
        root = temp;
    } else if (value <= root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* minimum(Node* root)
{
    if (root == NULL) {
        return root;
    }
    if (root->left == NULL) {
        return root;
    } else {
        return minimum(root->left);
    }
}

Node* maximum(Node* root)
{
    if (root == NULL) {
        return root;
    }
    if (root->right == NULL) {
        return root;
    } else {
        return maximum(root->right);
    }
}

Node* deleteNode(Node *root, int key)
{
    if (root == NULL) {
        return root;
    }

    if (root->value == key) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* minRight = minimum(root->right);
            root->value = minRight->value;
            root->right = deleteNode(root->right, minRight->value);
        }
    }
    else if (root->value < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        root->left = deleteNode(root->left, key);
    }
    return root;
}

void infixDisplay(Node* root)
{
    if (root == NULL) {
        return;
    } else {
        infixDisplay(root->left);
        cout<< root->value << " ";
        infixDisplay(root->right);
    }
}

int main() {

    Node* root = NULL;

    root = insert(root, 12);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 14);
    root = insert(root, 13);
    root = insert(root, 17);
    root = insert(root, 20);
    root = insert(root, 18);

    root = deleteNode(root, 18); // Case 1 : With no child
    root = deleteNode(root, 7); // Case 1 : With one child
    root = deleteNode(root, 12); // Case 1 : With two children

    infixDisplay(root);

    return 0;
}
