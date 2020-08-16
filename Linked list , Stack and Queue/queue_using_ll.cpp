#include <bits/stdc++.h>
using namespace std;
struct node 
{
	int data;
	struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;

void Enqueue(int x)
{
	struct node *temp=new node();
	temp->data=x;
	temp->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front =temp;
		rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
void Dequeue()
{
	struct node *temp=front;
	if(front ==NULL)
	{
		cout<<"queue is empty:\n";
		return;
	}
	else if(front==rear)
	{
		front =NULL;
		rear=NULL;
	}
	else
		front =front->next;
	delete(temp);
}
void Print()
{
	struct node *temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
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
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();	
	return 0;
}	