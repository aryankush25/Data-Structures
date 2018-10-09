#include<iostream>
using namespace std;
struct Node {
	int value;
	Node *next;
};
void push(Node **head,int value)
{
	Node *new_node = new Node();
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;
}
void display(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->value<<" ";
		head = head->next;
	}
}

int middle(Node *head)
{
	Node *temp1,*temp2;
	temp1=head;
	temp2=head;
	
	if(head==NULL)
		return -1;

	while(temp2!=NULL && temp2->next!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next->next;
	}
	return temp1->value;
}

int main(){
	Node *head = NULL;
	//push(&head,5);
	//push(&head,4);
	int x;
	cin>>x;
	push(&head,x);
	cin>>x;
	push(&head,x);
	cin>>x;
	push(&head,x);
	display(head);
	
	int y = middle(head);
	
	cout<<endl<<y;
	return 0;
}
