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
bstnode *insert(bstnode *root,int data)
{
	if(root==NULL)
	{
		root=getnewnode(data);
		return root;
	}
	else if(root->data >= data)
	{
		root->left=insert(root->left,data);
		return root;
	}
	else
	{
		root->right=insert(root->right,data);
		return root;
	}
}
bool isbinaryUTIL(bstnode *root,int minvalue,int maxvalue)
{
	if(root==NULL)
		return true;
	if(root->data>minvalue && root->data<maxvalue && isbinaryUTIL(root->left,minvalue,root->data) && isbinaryUTIL(root->right,root->data,maxvalue))
		return true;
	return false;
}
bool isbinarysearchtree(bstnode *root)
{
	return(isbinaryUTIL(root,INT_MIN,INT_MAX));
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
	root=insert(root,15);
	root=insert(root,25);
	root=insert(root,10);
	root=insert(root,13);
	root=insert(root,7);
	root=insert(root,20);
	root=insert(root,27);
	if(isbinarysearchtree(root))
		cout<<"yes it is binary search tree";
    else
    	cout<<"not a binary search tree";
	return 0;
}	