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
bool issubtreelesser(bstnode *root,int value)
{
	if(root==NULL)
		return true;
	if(root->data<=value && issubtreelesser(root->left,value) && issubtreelesser(root->right,value))
		return true;
	return false;
}
bool issubtreegreater(bstnode *root,int value)
{
	if(root==NULL)
		return true;
	if(root->data>value && issubtreegreater(root->left,value) && issubtreegreater(root->right,value))
		return true;
	return false;	
}
bool isbinarysearchtree(bstnode *root)
{
	if (root==NULL)
		return true;
	if(issubtreelesser(root->left,root->data) && issubtreegreater(root->right,root->data) && isbinarysearchtree(root->left) && isbinarysearchtree(root->right))
		return true;
	return false;
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
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,16);
	root=insert(root,4);
	root=insert(root,7);
	root=insert(root,1);
	root=insert(root,11);
    if(isbinarysearchtree(root))
    {
    	cout<<"yes binary search tree";
    }
    else
    {
    	cout<<"not a binary search tree";
    }

	return 0;
}	