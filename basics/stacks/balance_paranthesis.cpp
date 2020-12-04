//balanced paranthesis wih stack
//algo
//first store all opening paranthesis in a stack
// map closing paranthesis to corresponsing opening paranthesis
// if match is found in the stack, we'll pop the corresponding opening paranthesis
// then check whether stack is empty or not towards the end
#include<iostream>
using namespace std;
int top = -1;
char stack[100000];
void push(char paran)
{
	stack[top+1] = paran;
	top++;
}

void pop(char paran)
{
	for(int i = 0;i<=top;i++)
	{
	if(stack[i] == paran)
	{
	top--;
	break;
	}
    }
}
int main()
{
	string exp;
	cin>>exp;
	for(int i = 0; i<exp.length(); i++)
	{
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			push(exp[i]);
		}
		else
		{
			//assuming that corresponding opening brace is present
			if(exp[i] == ')')
			{
				pop('(');
			}
			if(exp[i] == ']')
			{
				pop('[');
			}
			if(exp[i] == '}')
			{
				pop('{');
			}

		}

	}
	if(top == -1)
	{
		cout<<"Expression is balanced";
	}
	else
	{
		cout<<"Expression is imbalanced";
	}

}
