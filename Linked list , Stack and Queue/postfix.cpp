#include <bits/stdc++.h>
using namespace std;
bool isdigits(char c)
{
	if(c>='0' || c<='9')
		return true;
	return false;
}
bool isoperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return true;
	return false;
}
int performoperation(char operation,int operand1,int operand2)
{
	if(operation=='/')
		return operand1/operand2;
	else if(operation=='*')
		return operand1*operand2;
	else if(operation=='+')
		return operand1+operand2;
	else if(operation=='-')
		return operand1-operand2;	
	else cout<<"unexpected error:";
	return -1;			
}
int postfix(string exp)
{
	int i;
	stack<int>s;
	for(i=0;i<exp.length();i++)
	{
	    if(exp[i] == ' ' || exp[i] == ',')
	    	continue;
	    else if(isdigits(exp[i]))
	    {
	    	int num=0;
	    	while(isdigits(exp[i]))
	    	{
	    	
	    		num = (num*10) + (exp[i]-'0');
	    		i++;
	    	}
	    	i--;
	    	//num=exp[i]-'0';
	    	s.push(num);
	    }	    
	    else if(isoperator(exp[i]))
	    {
	    	int operand2=s.top();
	    	s.pop();
	    	int operand1=s.top();
	    	s.pop();
	    	int res=performoperation(exp[i],operand1,operand2);
	    	s.push(res);
	    }

	    
	}
	return s.top();

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
	cout<<"Enter Postfix Expression \n";
	getline(cin,exp);
	int result = postfix(exp);
	cout<<"Output = "<<result<<"\n";
	return 0;
}	