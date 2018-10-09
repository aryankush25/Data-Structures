#include<iostream>
using namespace std;

struct node
{
	int value;
	struct node *next;
};

void printList(struct node *n) {
	while(n!=NULL) {
		printf("%d\n",n->value );
		n=n->next;
	}
}

void push(struct node** head_ref, int new_data) {

	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main() {

	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	head->value=1;
	head->next=second;
	second->value=2;
	second->next=third;
	third->value=3;
	third->next=NULL;

	push(&head,0);

	printList(head);

	return 0;
}
