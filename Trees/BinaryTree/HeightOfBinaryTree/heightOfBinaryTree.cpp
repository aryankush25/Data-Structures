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

int findHeight(Node* root)
{
    if (root == NULL) {
        return -1;
    }
    int left = findHeight(root->left);
    int right = findHeight(root->right);

    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

void printTree(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%d ", root->value);
    printTree(root->right);
}

int main() {
    Node *root = newNode(1);
    root->right = newNode(3);
    root->left = newNode(2);
    root->right->right = newNode(7);
    root->right->left = newNode(6);
    root->left->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right->right = newNode(9);
    root->left->right->left = newNode(8);

    printf("Height - %d\n", findHeight(root));
    printTree(root);

    return 0;
}
