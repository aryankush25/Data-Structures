#include <stdio.h>
#include <stdlib.h>

void swap(int *arr,int j,int k)
{

}
void add(int *arr,int i,int val)
{
	arr[i]=val;
	swim(arr,i);
}

void swim(int *arr,int size)
{
	if(arr[size]>arr[size/2]) return ;

	if(size==0) return ;

	else
	{
		swap(arr,size,size/2);

		swim(arr,size/2);
	}
}


int main(int argc, char const *argv[])
{
	int *arr;
	arr = calloc(5,sizeof(int));
	int i,x;
	for(i=0;i<5;i++)
	{
		add(arr,i,scanf("%d",&x));
	}

	for(i=0;i<5;i++)
	{
		printf("%d \n",arr[i] );
	}
	return 0;
}