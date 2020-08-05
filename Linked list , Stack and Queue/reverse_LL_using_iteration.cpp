#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *link;
};
struct node *head;
void insert(int x,int n)
{
	node *temp1 =new node();
	temp1->data=x;
	temp1->link=NULL;
	if(n==1)
	{
	    temp1->link=head;
		head=temp1;
		
		return;
	}
	node *temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->link;
	}
	temp1->link=temp2->link;
	temp2->link=temp1;

}
void print()
{
    node *temp=head;
	cout<<"list is:";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<"\n";
}
void reverse()
{
	struct node *prev,*current,*link;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		link=current->link;
		current->link =prev;
		prev=current;
		current=link;
	}
	head=prev;

}

int main() 
{
	head=NULL;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	head=NULL;
	int i,y,x,n;
	cout<<"how many numbers:\n";
	cin>>y;
	for(i=0;i<y;i++)
	{
		cout<<"enter number and position:\n";
		cin>>x;
		cin>>n;
		insert(x,n);

	}
	print();
	reverse();
	cout<<"after reversing ll:\n";
	print();

	return 0;
}	