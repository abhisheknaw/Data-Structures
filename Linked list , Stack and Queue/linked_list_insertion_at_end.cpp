#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *link;
};
void insert(node **pointertohead,int x)
{
	node *temp=new node();
	node *last =*pointertohead;
	temp->data=x;
	temp->link=NULL;
	if(*pointertohead==NULL)
	{
		*pointertohead=temp;
	}
	else
	{
		while(last->link!=NULL)
		{
			last=last->link;
		}
		last->link=temp;
	}
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"\n";
		head=head->link;
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
	node *head=NULL;
	int i,x,n;
	cout<<"how many numbers?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter number:"<<"\n";
		cin>>x;
		insert(&head,x);
		print(head);
	}
	return 0;
}	
