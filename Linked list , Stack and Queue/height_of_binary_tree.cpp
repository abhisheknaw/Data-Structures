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
int findheight(bstnode *root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(findheight(root->left),findheight(root->right))+1;

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
	int x;
	cout<<"enter number to be searched:\n";
	cin>>x;
	if(search(root,x))
		cout<<"found";
	else
		cout<<"not found";
	cout<<"\n";
	int m=findheight(root);
	cout<<"height is:\n";
	cout<<m;
	return 0;
}	