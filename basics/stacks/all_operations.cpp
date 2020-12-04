#include <iostream>
using namespace std;
	int stack[50],top=-1;


		int isEmpty()
	{
		if(top==-1)
		return 1;
		else
		return 0;

	}
	int isFull(int n)
	{
		if(top==(n-1))
		return 1;
		else
		return 0;
	}


	void push(int n)
	{ int a;
		cout<<"Enter the element to be pushed"<<endl;
		cin>>a;
		if(isFull(n))
		cout<<"Stack overflown"<<endl;
		else{
			top++;
			stack[top]=a;
		}
	}

	void pop()
	{
		if(isEmpty())
		cout<<"Stack Underflow"<<endl;
		else{
		cout<<"The element popped is: "<<stack[top]<<endl;
		top--;
		}

	}



	void display(){
		cout<<"The elements of stacks are as follow:"<<endl;
		for(int i=top;i>=0;i--)
		{
			cout<<stack[i]<<endl;
		}

	}

	void peak(int n){
		if(isFull(n))
		cout<<"Stack overflown"<<endl;
		else{
			cout<<"The element at peak is: "<<stack[top]<<endl;
		}


	}




int main(int argc, char** argv) {
	int i,n;
	cout<<"Enter the number of elements in stack"<<endl;
	cin>>n;

		cout<<"Enter 1 for pushing data into the stack"<<endl;
		cout<<"Enter 2 for popping data from the stack"<<endl;
		cout<<"Enter 3 for checking whether the stack is empty"<<endl;
		cout<<"Enter 4 to check whether the stack is full"<<endl;
		cout<<"Enter 5 to display the contents of the stack"<<endl;
		cout<<"Enter 6 to peak the element on the top of the stack"<<endl;
		while(1)
		{
			cout<<"Enter your Choice:"<<endl;
			cin>>i;
			switch(i)
			{
				case 1:
					{
						push(n);
						break;
					}
				case 2:
					{
						pop();
						break;
					}
				case 3:
					{
						isEmpty();
						break;
					}
				case 4:
					{
						isFull(n);
						break;
					}
				case 5:
					{
						display();
						break;
					}
				case 6:
					{
						peak(n);
						break;
					}
					default:{
						cout<<"Enter a valid choice"<<endl;
						break;
					}

			}
		}


	return 0;
}
