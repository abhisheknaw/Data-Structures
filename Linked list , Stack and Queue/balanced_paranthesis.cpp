<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
bool arepair(char opening,char closing)
{
	if(opening=='(' && closing==')')
	{
		return true;
	}
	else if(opening=='{' && closing=='}')
	{
		return true;
	}
	else if(opening=='[' && closing==']')
	{
		return true;
	}
	return false;
}
bool areparanthesesbalanced(string exp)
{
	int i;
	stack<char>s;
	for(i=0;i<strlen(exp.c_str());i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			s.push(exp[i]);
		}
		else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		{	
			if(s.empty() || !arepair(s.top(),exp[i]))
			{
				return false;
		    }
		    else
		    {
		    	s.pop();
		    }	
		}
	}
	return s.empty() ? true:false;
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
	string exp;
	cin>>exp;
	if(areparanthesesbalanced(exp))
		cout<<"balanced";
	else
		cout<<"not balanced";
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
bool arepair(char opening,char closing)
{
	if(opening=='(' && closing==')')
	{
		return true;
	}
	else if(opening=='{' && closing=='}')
	{
		return true;
	}
	else if(opening=='[' && closing==']')
	{
		return true;
	}
	return false;
}
bool areparanthesesbalanced(string exp)
{
	int i;
	stack<char>s;
	for(i=0;i<strlen(exp.c_str());i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			s.push(exp[i]);
		}
		else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		{	
			if(s.empty() || !arepair(s.top(),exp[i]))
			{
				return false;
		    }
		    else
		    {
		    	s.pop();
		    }	
		}
	}
	return s.empty() ? true:false;
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
	string exp;
	cin>>exp;
	if(areparanthesesbalanced(exp))
		cout<<"balanced";
	else
		cout<<"not balanced";
	return 0;
>>>>>>> 08699f2d6f6a8e9050b7ef9fdf73968f044d3d6e
}	