//reverse word with stack
#include<iostream>
#include<string>
using namespace std;
int top = -1;
char stack[1000];
void reverse(string word)
{
	for(int i = 0;i<word.length();i++)
	{
		stack[i] = word[i];
		top++;
	}
	for (int i = top;i>=0;i--)
	{
		cout<<stack[i];
	}

}

int main()
{
    string word;
	cin>>word;
	reverse(word);

}
