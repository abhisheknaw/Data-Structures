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
	int i;
	struct node *temp1 = new node();
	temp1->data=x;
	temp1->link=NULL;
	if(n==1)
	{
		temp1->link=head;
		head=temp1;
		return;
	}
	node *temp2=head;
	for(i=0;i<n-2;i++)
	{
		temp2=temp2->link;
	}
	temp1->link=temp2->link;
	temp2->link=temp1;
}
void print()
{
	struct node *temp=head;
	cout<<"list is: ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<"\n";
}
void Delete(int m)
{
	int i;
	struct node *temp=head;
	if(m==1)
	{
		head=temp->link;
		delete(temp);
		return;
	}
	for(i=0;i<m-2;i++)
	{
		temp=temp->link;
	}
	struct node *temp1=temp->link;
	temp->link=temp1->link;
	delete(temp1);
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
    int y,x,i,n,m;
    head=NULL;
    cout<<"how many numbers:\n";
    cin>>y;
    for(i=0;i<y;i++)
    {
    	cout<<"enter number and position:\n";
    	cin>>x;
    	cin>>n;
    	insert(x,n);
    	print();
    }
    cout<<"enter position to be deleted:\n";
    cin>>m;
    if(m>y)
    {
    	cout<<"not able to delete.....";
    }
    else
    {
    	Delete(m);
    	print();
    }
    
    return 0;	
}
