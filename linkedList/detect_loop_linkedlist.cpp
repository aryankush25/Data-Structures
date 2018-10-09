#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

void push(node **head,int value)
{
    node *temp=(node *)malloc(sizeof(node *));
    temp->value=value;
    
    temp->next=*head;
    *head=temp;
}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->value<<" ";
        head=head->next;
    }
}

int detectLoop(node *head)
{
    node *fast,*slow;
    fast=head;
    slow=head;
    
    do
    {
        if(fast->next==NULL || fast->next->next==NULL)
        {
            return 0;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    while(fast!=slow);
    return 1;
}

int main()
{
    node *head=NULL;
    
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,0);
    
    head->next->next->next->next->next->next=head->next;
    
    int x = detectLoop(head);
    
    if(x==1)
        cout<<"Loop Detected\n";
    else
        cout<<"No Loop Detected\n";
    
    //display(head);
    
    return 0;
}
