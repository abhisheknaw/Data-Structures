#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int arr[MAX];
int front=-1;
int rear=-1;

bool isfull()
{
	if((rear+1)%10==front)
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
		rear=(rear+1)%10;
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
		front=(front+1)%10;
	}
	return x;
}
void print()
{
		// Finding number of elements in queue  
	int count = (rear+MAX-front)%MAX + 1;
	for(int i = 0; i <count; i++)
	{
		int index = (front+i) % MAX; // Index of element while travesing circularly from front
		cout<<arr[index]<<" ";
	}
	cout<<"\n";
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
	//int x=dequeue();
	//cout<<x<<"\n";
	enqueue(50);
	print();
	enqueue(60);
	print();
	enqueue(70);
	print();
	enqueue(80);
	print();
	enqueue(90);
	print();
	enqueue(100);
	print();
	int x=dequeue();
	cout<<x<<"\n";
	print();
	enqueue(110);
	print();
	return 0;
}	