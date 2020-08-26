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
bstnode *findmin(bstnode *root)
{
	while(root->left!=NULL)
	    root=root->left;
	return root;
}
bstnode *Delete(bstnode *root,int data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left=Delete(root->left,data);
	else if(data>root->data)
		root->right=Delete(root->right,data);
	else
	{
		if(root->left==NULL &&root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			bstnode *temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			bstnode *temp=root;
			root=root->left;
			delete temp;
		}
		else
		{
			bstnode *temp=findmin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}		
	}
	return root;	

}
void levelorder(bstnode *root)
{
	if(root==NULL)
		return;
	else
	{
		queue<bstnode *>q;
	    q.push(root);
	    while(!q.empty())
	    {
		    struct bstnode *temp=q.front();
		    cout<<temp->data<<" ";
		    if(temp->left!=NULL)
		        q.push(temp->left);
		    if(temp->right!=NULL)
		        q.push(temp->right);
		    q.pop();
		} 

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
	struct bstnode *root=NULL;
	insert(&root,10);
	insert(&root,5);
	insert(&root,15);
	insert(&root,1);
	insert(&root,7);
	insert(&root,13);
	insert(&root,20);
	levelorder(root);
	cout<<"\n";
	Delete(root,10);
	levelorder(root);
	return 0;

}	