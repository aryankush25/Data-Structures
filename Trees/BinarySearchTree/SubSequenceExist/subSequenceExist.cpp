#include<bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new BST node
// with key as given num
struct Node* newNode(int num)
{
    struct Node* temp = new Node;
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a given key to BST
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void seqExistArrCheck(Node *root, int *seq, int n, int *i) {
    if (root == NULL) {
        return;
    }

    seqExistArrCheck(root->left, seq, n, i);
    //cout << root->data << " " << seq[*i] << endl;
    if (root->data == seq[*i]) {
        (*i) = (*i) + 1;
    }
    seqExistArrCheck(root->right, seq, n, i);
}

bool seqExist(Node *root, int *seq, int n) {
    int i = 0;

    seqExistArrCheck(root, seq, n, &i);

    //cout << i << " " << n << endl;

    if (i == n) {
        return true;
    }

    return false;
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    int seq[] = {4, 6, 8, 12, 13};
    int n = sizeof(seq)/sizeof(seq[0]);

    seqExist(root, seq, n)? cout << "Yes" : cout << "No";

    return 0;
}
