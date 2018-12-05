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

void display(Node* root)
{
    if (root == NULL) {
        return;
    } else {
        display(root->left);
        cout<< root->value << " ";
        display(root->right);
    }
}

int main() {

    Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 12);
    root = insert(root, 100);
    
    display(root);

    return 0;
}
