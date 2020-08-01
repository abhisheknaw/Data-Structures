#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *link;
};
void Insert(node **pointertohead,int x)
{
	node *temp=new node();
	temp->data=x;
	temp->link=(*pointertohead);
	(*pointertohead)=temp;
}

void print(node *Head)
{
	cout<<"list is:"<<" ";
	while(Head!=NULL)
	{
		cout<<Head->data<<"\n";
		Head=Head->link;
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
	int n,x;
	node *Head=NULL;
	cout<<"how many numbers?\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter number:"<<"\n";
		cin>>x;
		Insert(&Head,x);
		print(Head);
	}
	return 0;
}	