#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    Node *left;
    Node *right;
};

Node* newNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

void printTree(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%d\n", root->value);
    printTree(root->right);
}

int main() {
    Node *root = newNode(5);
    root->right = newNode(1);
    root->left = newNode(2);
    root->right->right = newNode(3);
    root->right->left = newNode(4);
    root->left->right = newNode(6);
    root->left->left = newNode(7);

    printTree(root);

    return 0;
}
