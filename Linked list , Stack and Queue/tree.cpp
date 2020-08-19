#include <bits/stdc++.h>
using namespace std;
struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
bstnode *getnewnode(int data)
{
	bstnode *newnode=new bstnode();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
void insert(bstnode **root,int data)
{
	if(*root==NULL)
	{
		*root=getnewnode(data);
		return;
	}
	bstnode *tvrptr=*root;
	bstnode *nowpointer=NULL;
	while(tvrptr!=NULL)
	{
		nowpointer=tvrptr;
		if(data<=tvrptr->data)
			tvrptr=tvrptr->left;
		else
			tvrptr=tvrptr->right;
	}
	if(data<=nowpointer->data)
	{
		nowpointer->left=getnewnode(data);
	}
	else
	{
		nowpointer->right=getnewnode(data);
	}

}
bool search(bstnode *root,int data)
{
	if(root== NULL)return false;
	else if(root->data==data) return true;
	else if(root->data>=data)
	{
		return search(root->left,data);
	}
	else
		return search(root->right,data);
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
	bstnode *root=NULL;
	insert(&root,15);
	insert(&root,25);
	insert(&root,10);
	insert(&root,13);
	insert(&root,7);
	insert(&root,20);
	insert(&root,27);
	int x;
	cout<<"enter number to be searched:\n";
	cin>>x;
	if(search(root,x))
		cout<<"found";
	else
		cout<<"not found";
	return 0;
}	