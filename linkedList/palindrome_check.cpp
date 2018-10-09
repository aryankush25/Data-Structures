#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

void push(Node **head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void display(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverse(Node *head, Node **head_ref)
{
    if(head == NULL)
    {
        return;
    }
    int x = head->data;
    reverse(head->next, head_ref);
    (*head_ref)->data = x;
    *head_ref = (*head_ref)->next;
}

void rev(Node *head)
{
    reverse(head, &head);
}

void check_palindrome_with_reverse(Node *head)
{
    Node *new_head = head, *temp = head;
    while(temp != NULL)
    {
        push(&new_head, temp->data);
        temp = temp->next;
    }

    rev(new_head);

    while(head != NULL)
    {
        if(new_head->data != head->data)
        {
            cout<<"It is not a Palindrome\n";
            return;
        }
        new_head = new_head->next;
        head = head->next;
    }
    cout<<"It is a Palindrome\n";
    return;
}

void check_palindrome_without_reverse(Node *head, Node **head_ref)
{
    if(head == NULL)
    {
        return;
    }
    
    int x = head->data;
    
    reverse(head->next, head_ref);
    
    if((*head_ref)->data != x)
    {
        return;
    }

    *head_ref = (*head_ref)->next;

    if(head_ref == NULL)
    {
        cout<<"It is a Palindrome\n";
    }
    else
    {
        cout<<"It is not a Palindrome\n";
    }

}

int main() {
    Node *head = NULL;
    
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 4);
    push(&head, 1);

    display(head);

    check_palindrome_with_reverse(head);
    
    check_palindrome_without_reverse(head, &head);


    return 0;
}
