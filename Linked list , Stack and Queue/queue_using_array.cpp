#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int arr[MAX];
int front=-1;
int rear=-1;

bool isfull()
{
	if(rear == MAX-1)
		return true;
	return false;	 
}
bool isempty()
{
	if(rear == -1 && front ==-1)
		return true;
	return false;	 
}
void enqueue(int x)
{
	if(isfull())
	{
		cout<<"already full:\n";
		return;
	}
	else if(isempty())
	{
		rear=0;
		front=0;
	}
	else
	{
		rear=rear+1;
	}
	arr[rear]=x;
}
int dequeue()
{
	int x;
	if(isempty())
	{
		cout<<"nothing to remove:\n";
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		 x=arr[front];
		front=front+1;
	}
	return x;
}
void print()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<'\n';
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif	

	enqueue(10);
	print();
	enqueue(20);
	print();	
	enqueue(30);
	print();
	enqueue(40);
	print();
	int x=dequeue();
	cout<<x<<"\n";
	print();
	return 0;
}	