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

char minimum(Node *root)
{
    if (root->left == NULL) {
        return root->value;
    }
    return minimum(root->left);
}

char maximum(Node *root)
{
    if (root->right == NULL) {
        return root->value;
    }
    return minimum(root->right);
}

bool isBST(Node *root)
{
    if (root == NULL) {
        return true;
    }
    else if (root->left == NULL && root->right == NULL) {
        return true;
    }
    else if (root->left == NULL) {
        if (minimum(root->right) > root->value) {
            return isBST(root->right);
        } else {
            return false;
        }
    }
    else if (root->right == NULL) {
        if (maximum(root->left) <= root->value) {
            return isBST(root->left);
        } else {
            return false;
        }
    }
    if (minimum(root->right) > root->value && maximum(root->left) <= root->value) {
        return (isBST(root->left) && isBST(root->right));
    } else {
        return false;
    }
}

bool isBSTinRange(Node* root, char minVal, char maxVal)
{
    if (root == NULL) {
        return true;
    }

    if (root->value >= minVal && root->value < maxVal) {
        return (isBSTinRange(root->left, minVal, root->value) && isBSTinRange(root->right, root->value, maxVal));
    } else {
        return false;
    }
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
    root->right->left->right->left = newNode('H'); // Change 'A' to 'H' to make it BST

    // isBST() Function is More Complex and Time Taking

    if (isBST(root)) {
        cout<< "Is a BST\n";
    } else {
        cout<< "Is Not a BST\n";
    }

    // isBSTinRange() Function is more Efficient

    if (isBSTinRange(root, CHAR_MIN, CHAR_MAX)) {
        cout<< "Is a BST\n";
    } else {
        cout<< "Is Not a BST\n";
    }

    // std::cout << CHAR_MIN << " - " << CHAR_MAX << '\n';
    // std::cout << INT_MIN << " - " << INT_MAX << '\n';
    // std::cout << LONG_MIN << " - " << LONG_MAX << '\n';

    printf("Inorder - ");
    printInOrder(root);

    return 0;
}
