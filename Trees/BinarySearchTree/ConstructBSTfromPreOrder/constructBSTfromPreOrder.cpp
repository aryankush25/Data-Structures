#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}



struct node* constructTree(int* pre, int start, int end, int size) {

    if (size == 0) {
        return NULL;
    }

    if (start > end) {
        return NULL;
    }
    struct node* temp = newNode(pre[start]);

    if (start < end) {

        int t = 0;

        for (int i = start + 1; i <= end; i++) {
            if (pre[i] > pre[start]) {
                t = i;
                break;
            }
        }

        cout << start << " " << end << " " << t << " ";

        temp->left = constructTree(pre, start + 1, t - 1, size);
        temp->right = constructTree(pre, t, end, size);
    }

    return temp;
}


void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = constructTree(pre, 0, size - 1, size);

    printf("\nInorder traversal of the constructed tree: \n");
    printInorder(root);
    printf("\n");

    return 0;
}
