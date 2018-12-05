#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
};

Node* newNode(char value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printPreOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%c ", root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    printf("%c ", root->value);
    printInOrder(root->right);
}

void printPostOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%c ", root->value);
}

int main()
{
    Node *root = newNode('F');
    root->left = newNode('D');
    root->right = newNode('J');
    root->left->left = newNode('B');
    root->left->right = newNode('E');
    root->right->left = newNode('G');
    root->right->right = newNode('K');
    root->left->left->left = newNode('A');
    root->left->left->right = newNode('C');
    root->right->left->right = newNode('I');
    root->right->left->right->left = newNode('H');

    printf("Preorder - ");
    printPreOrder(root);
    printf("\nInorder - ");
    printInOrder(root);
    printf("\nPostorder - ");
    printPostOrder(root);

    return 0;
}
