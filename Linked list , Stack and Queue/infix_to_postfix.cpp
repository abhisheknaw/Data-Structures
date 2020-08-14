#include <bits/stdc++.h>
using namespace std;
bool isnumber(char num)
{
	if((int)num-'0'>=0 && (int)num-'0'<=9)
		return true;
	return false;
}
bool isoperator(char op)
{
	if(op=='+' || op=='-' || op=='*' || op=='/')
		return true;
	return false;
}
int precedencevalue(char op)
{
	if(op=='*' || op=='/')
		return 2;
	else if(op=='+' || op=='-')
		return 1;
	else
		return 0;
}
bool hashigherprecedence(char op1, char op2)
{
	int opp1=precedencevalue(op1);
	int opp2=precedencevalue(op2);
	if(opp1>opp2)
		return true;
	else
		return false;
}

string postfix(string infix)
{
	int i;
	string postfix="";
	stack <char>s;
	for(i=0;i<infix.length();i++)
	{
		if(infix[i]==' '|| infix[i]==',')
			continue;
		else if(isnumber(infix[i]))
		{
			postfix +=infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(s.top()!='(')
			{
				postfix +=s.top();
				s.pop();
				if(s.empty()) break;
			}
			if(!s.empty())
			{
				s.pop();
			}
		}
		else if(isoperator(infix[i]))
		{
		    if(s.empty() || s.top()=='(')
		    {
			    s.push(infix[i]);
			}
		    else if(hashigherprecedence(infix[i],s.top()))
		    {
		    	s.push(infix[i]);
		    }
		    else
		    {
		    	while(s.top()!='(')
		    	{
		    		postfix +=s.top();
		    		s.pop();
		    		if(s.empty())
		    			break;
		    	}
		    	s.push(infix[i]);
		    }
		}
		else
		{
			cout<<"invalid expression.....";
		}
	}
	while(!s.empty())
	{
		postfix +=s.top();
		s.pop();
	}
	return postfix;
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
	string infix;
	cout<<"enter string:\n";
	getline(cin,infix);
	string res=postfix(infix);
	cout<<"output: "<<res<<"\n";
	return 0;
}	