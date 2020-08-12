
#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
void insert(node **pointertohead,int x)
{
  struct node *temp=new node();
  temp->data=x;
  temp->next=NULL;
  if(*pointertohead==NULL)
  {
    *pointertohead=temp;
  }
  else
  {
    struct node *last=*pointertohead;
    while(last->next!=NULL)
    {
      last=last->next;
    }
    last->next=temp;
  }
}
void reverse(node**pointertohead)
{
    struct node*temp=*pointertohead;
    if(*pointertohead==NULL)
    {
        return;
    }
    else
    {
        

        stack<struct node*>s;
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->next;
        }
         struct node *temp2=NULL;
         temp2=s.top();
        *pointertohead=temp2;
        s.pop();
        while(!s.empty())
        {
            temp2->next=s.top();
            s.pop();
            temp2=temp2->next;
        }
        temp2->next=NULL;
    }
    
}
void print(node **pointertohead)
{
  cout<<"list is:\n";
  struct node *temp=*pointertohead;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
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


  struct node *head=NULL;
  insert(&head,10);
  insert(&head,20);
  insert(&head,30);
  print(&head);
  reverse(&head);
  print(&head);
  return 0;
}