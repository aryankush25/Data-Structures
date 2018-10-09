#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

void push(Node **head, int value)
{
    Node *newNode = new Node, *temp = *head;

    newNode->value = value;
    newNode->next = nullptr;

    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;

}

void remove(Node **head, int pos)
{
    if(*head == nullptr)
    {
        return;
    }
    
    Node *temp = *head;

    if(pos == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    int i = 0;
    Node *temp1 = nullptr;

    while(i < pos && temp != nullptr)
    {
        temp1 = temp;
        temp = temp->next;
        i++;
    }
    
    if(temp == nullptr)
    {
        return;
    }

    temp1->next = temp->next;
    free(temp);

}

void display(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->value<<" ";
        head = head->next;
    }
}

void removeDuplicates(Node **head)
{
    Node *temp = *head;

    while(temp != nullptr && temp->next != nullptr)
    {
        Node *t = temp;
        while(t->next != nullptr)
        {
            if(temp->value == t->next->value)
            {
                remove(&t,1);
            }
            else
            {
                t = t->next;
            }
        }
        
        temp = temp->next;
    }

}

int main()
{
    Node *head = nullptr;

    push(&head, 2);
    push(&head, 2);
    push(&head, 2);
    push(&head, 2);
    push(&head, 2);

    //remove(&head, 9);

    removeDuplicates(&head);

    display(head);


}