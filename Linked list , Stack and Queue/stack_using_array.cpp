#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int arr[MAX];
int top=-1;

void push(int arr[],int x)
{
	if(top==MAX-1)
	{
		cout<<"stack overflow";
	}
	else
	{
		top=top+1;
	    arr[top]=x;
	    
	}

}
void pop()
{
	if(top==-1)
	{
		cout<<"stack underflow:";
		return;
	}
	top=top-1;
}
void print()
{
	int i;
	if(top==-1)
	{
		cout<<"no item";
		return;
	}
	for(i=0;i<=top;i++)
	{
		cout<<arr[i];
	}

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
	int i,x,choice;
	cout<<"1. push\n";
	cout<<"2. pop\n";
	cout<<"3. display\n";
	cout<<"enter your choice:\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		cout<<"enter the number:\n";
		cin>>x;
		push(arr,x);
		cout<<"stack is:\n";
		print();
		break;
		case 2:
		pop();
		cout<<"stack is:\n";
		print();
		break;
		default:
		cout<<"wrong option:";
	}
	return 0;
}	

	

