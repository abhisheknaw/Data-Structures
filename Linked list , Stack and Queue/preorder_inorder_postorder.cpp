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
void preorder(bstnode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(bstnode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(bstnode *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
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
	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	postorder(root);

	return 0;
}	