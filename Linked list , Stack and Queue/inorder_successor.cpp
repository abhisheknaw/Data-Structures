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
struct bstnode* Find(bstnode*root, int data) 
{
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}
struct bstnode* FindMIN(struct bstnode* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}
struct bstnode *successor(struct bstnode *root,int data)
{
	struct bstnode *current=Find(root,data);
	if(current==NULL) return NULL;
	if(current->right!=NULL)
		return FindMIN(current->right);
	else
	{
		struct bstnode *suc=NULL;
		struct bstnode *anc=root;
		while(anc!=current)
		{
			if(anc->data>current->data)
			{
				suc=anc;
				anc=anc->left;
			}
			else
			{
				anc=anc->right;
			}
		}
		return suc;
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
	bstnode *root=NULL;
	root=insert(root,15);
	root=insert(root,25);
	root=insert(root,10);
	root=insert(root,13);
	root=insert(root,7);
	root=insert(root,20);
	root=insert(root,27);
	struct bstnode *succ=successor(root,13);
	if(succ==NULL)
	{
		cout<<"no successor:\n";
	}
	else
	{
		cout<<succ->data;
	}
	return 0;
}	