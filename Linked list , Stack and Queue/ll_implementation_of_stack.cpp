
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL;
void push(int x)
{
	struct node *temp=new node();
	temp->data=x;
	temp->link=top;
	top=temp;
}
void pop()
{
	struct node *temp;
	if(top==NULL)
		return;
	temp=top;
	top=temp->link;
	delete(temp);
}
void print()
{
	struct node *temp=top;
	cout<<"stack is:\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
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
	push(20);
	push(30);
	push(40);
	pop();
	print();
	return 0;
}	
