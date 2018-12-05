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

int minimum(Node* root)
{
    if (root->left == NULL) {
        return root->value;
    } else {
        return minimum(root->left);
    }
}

int maximum(Node* root)
{
    if (root->right == NULL) {
        return root->value;
    } else {
        return maximum(root->right);
    }
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

    root = insert(root, 300);
    root = insert(root, 300);
    root = insert(root, 300);
    root = insert(root, 300);
    root = insert(root, 300);
    root = insert(root, 100);

    cout<< minimum(root) << endl;
    cout<< maximum(root) << endl;

    display(root);

    return 0;
}
