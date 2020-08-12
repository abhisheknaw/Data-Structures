<<<<<<< HEAD
#include<iostream>
#include<stack>

// Define the namespace for standard library
using namespace std;

// Evaluates the result in the postfix expression.
int EvaluateResult(int operand1, int operand2, char symbol)
{
  if(symbol=='+') return operand1+operand2;       // Addition
  else if(symbol=='-') return operand1-operand2;  // Subtraction
  else if(symbol=='*') return operand1*operand2;  // Multiplication
  else if(symbol=='/') return operand1/operand2;  // Division
  else if(symbol=='%') return operand1%operand2;  // Modulus
  else if(symbol=='^') return operand1^operand2;  // Exponentiation
  else return -1;
}

// Evaluate PostFix expression using the stack algorithm methodology.
// Return -1 of invalid expression is given otherwise return the result.
int EvaluatePostfix(string expression)
{
  int i,num=-1;             // Variable declarations
  stack<int> temp_stack;

  for(i=0;i<expression.length();i++)
  { // Iterate over characters

    int mychar=expression[i];

    if(mychar==',' || mychar==' ')
    {  // Delimiter comma handling
      if(num!=(-1)){
        temp_stack.push(num);
        num=-1;
      }
      continue;
    }
    else if(mychar-'0' <= 9 && mychar-'0' >= 0)
    {  // Numbers handling 
      if(num==-1)
      {
        num=mychar-'0'; // Find the exact number from the character
      }
      else
      {
        num=num*10+(mychar-'0');  // Number is greater than 1 digit.
      }
    }
    else if(mychar=='+'||mychar=='-'||mychar=='*'||mychar=='/'||mychar=='^'||mychar=='%'){  
      // Operating on the given symbols

      // Main Algorithm for the evaluation of result
      if(temp_stack.empty()) 
        return -1;
      int operand2=temp_stack.top();
      temp_stack.pop();

      if(temp_stack.empty()) 
        return -1;
      int operand1=temp_stack.top();
      temp_stack.pop();

      // Pop two previous elements from the stack and push their result onto stack again.
      temp_stack.push(EvaluateResult(operand1,operand2,mychar));
    }
    else
    {
      cout<<"Invalid operand";
    }
  }

  return temp_stack.top();
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
	string expression; 
	cout<<"Enter Postfix Expression \n";
	getline(cin,expression);
	int result = EvaluatePostfix(expression);
	cout<<"Output = "<<result<<"\n";
	return 0;
}
=======
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
>>>>>>> 08699f2d6f6a8e9050b7ef9fdf73968f044d3d6e
