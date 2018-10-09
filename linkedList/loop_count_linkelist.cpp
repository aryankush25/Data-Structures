#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

void push(node **head,int value)
{
    node *temp = (node *)malloc(sizeof(node *));
    temp->value=value;
    temp->next = *head;
    *head = temp;
}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->value<<" ";
        head=head->next;
    }
}

int countNodes(node *head)
{
    node *temp=head;
    int count=1;
    
    while (temp->next!=head) {
        temp = temp->next;
        count++;
    }
    return count;
}

int circular_node_check(node *head)
{
    node *fast=head,*slow=head;
    
    do
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast->next==NULL || fast->next->next==NULL)
            return 0;
    } while (fast!=slow);
    return countNodes(slow);
}

int main()
{
    node *head=NULL;
    
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    head->next->next->next->next->next = head->next->next;
    
    int i = circular_node_check(head);
    
    cout<<i<<endl;
    
    //display(head);
    
    return 0;
}
