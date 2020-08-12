#include <bits/stdc++.h>
using namespace std;
void reverse(char *ch,int n)
{
	int i;
	stack<char>s;
	for(i=0;i<n;i++)
	{
		s.push(ch[i]);
	}
	for(i=0;i<n;i++)
	{
		ch[i]=s.top();
		s.pop();
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
	
    
	char ch[50];
	gets(ch);
	reverse(ch,strlen(ch));
	cout<<strlen(ch);
	cout<<"after reverse:"<<ch;
	return 0;
}	
