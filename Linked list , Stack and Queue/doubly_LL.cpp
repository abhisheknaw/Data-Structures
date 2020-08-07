#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head;
struct node*getnewnode(int x)
{
	struct node *newnode=new node();
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void insertathead(int x)
{
	struct node* newnode=getnewnode(x);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;

	}
}
void insertatend(int x)
{
	struct node *newnode=getnewnode(x);
	if(head==NULL)
	{
		newnode->next=head;
		head=newnode;
		return;
	}
	struct node *last=head;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	newnode->prev=last;
	last->next=newnode;
}
void print()
{
	cout<<"list is: ";
	struct node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
void reverseprint()
{
	cout<<"list in reverse is:";
	struct node *temp=head;
	if (temp==NULL)
	{
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->prev;
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
	head=NULL;
	insertathead(10);
	insertathead(20);
	insertathead(30);
	insertathead(40);
	insertathead(50);
	insertathead(60);
	insertatend(70);
	print();
	reverseprint();
	return 0;
}	
