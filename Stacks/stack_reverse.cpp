#include<iostream>
using namespace std;

class stack {
	public:
		int top=0,arr[100];
		
		void push(int n)
		{
		    arr[top]=n;
		    top++;
		}

		int pop()
		{
			int x;
			x=arr[top];
		    arr[top]=0;
		    top--;
		    return x;
		}

		void display()
		{
		    for(int i=0;i<top;i++)
		    {
		        cout<<arr[i]<<" ";
		    }
		    cout<<endl;
		}
		void reverse()
		{
			if(top>0)
			{
				int x;
				x=pop();
				reverse();
				insert(x);
			}
		}

		void insert(int x)
		{
			if(top==0)
				push(x);
			else
			{
				int y = pop();
				insert(x);
				push(y);
			}
		}
};

int main()
{
	stack s;

	for(int i=0;i<5;i++)
		s.push(i);

	cout<<"Initially Stack : ";

	s.display();

	s.reverse();

	cout<<"Final Stack : ";

	s.display();

	return 0;
}