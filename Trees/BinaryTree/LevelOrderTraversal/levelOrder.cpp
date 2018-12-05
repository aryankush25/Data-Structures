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

void addToQueue(queue<Node*> q)
{
    if (q.empty()) {
        return;
    }

    Node* temp = q.front();

    printf("%c ", temp->value);

    if (temp->left) {
        q.push(temp->left);
    }
    if (temp->right != NULL) {
        q.push(temp->right);
    }
    q.pop();
    addToQueue(q);
}

void levelOrder(Node* root)
{
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    // Recursive Method
    printf("Recursive Method - ");
    addToQueue(q);
    printf("\n");

    // Iterative Method
    printf("Iterative Method - ");

    while (!q.empty()) {
        Node* temp = q.front();
        printf("%c ", temp->value);

        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        q.pop();
    }
    printf("\n");
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

    levelOrder(root);

    return 0;
}
