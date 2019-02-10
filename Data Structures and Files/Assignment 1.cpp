#include<iostream>
#include<math.h>

using namespace std;

class node
{
	public:
	char data;
	node *next;
};

class stack
{
	public:
	node *top;
	stack();
	void push(char c);
	char pop();
	int empty();
	char getTop();
};

class convert
{
	public:
	int infixToPostfix(char infix[], char postfix[]);
	int infixToPrefix(char infix[], char prefix[]);
	int inputValidation(char exp[]);
	int precedence(char c);
	int evaluatePostfix(char postfix[]);
	int evaluatePrefix(char prefix[]);
	int evaluate(char x, int op1, int op2);
};

int main()
{
	convert expression;
	int choice, result;
	char infix[50], postfix[50], prefix[50], check;
	
	do
	{
		cout << "\n1. Infix to Postfix\n2. Infix to Prefix\n3. Exit\nEnter your choice: ";
		cin >> choice;
	
		switch(choice)
		{
			case 1:
			{
				cout << "\nEnter infix expression: ";
				cin >> infix;
				result=expression.infixToPostfix(infix, postfix);
				if(result==-1)
				{
					cout << "\nInvalid expression!\n";
				}
				else
				{
					cout << "\nPostfix expression: " << postfix << endl;
					cout << "\nDo you want to evaluate postfix expression?\n";
					cin >> check;
					if(check=='y' || check=='Y')
					{
						result=expression.evaluatePostfix(postfix);
						cout << "\nValue of the expression is " << result << endl;
					}
				}
				break;
			}
			case 2:
			{
				cout << "\nEnter infix expression: ";
				cin >> infix;
				result=expression.infixToPrefix(infix, prefix);
				if(result==-1)
				{
					cout << "\nInvalid expression!\n";
				}
				else
				{
					cout << "\nPrefix expression: " << prefix << endl;
					cout << "\nDo you want to evaluate prefix expression?\n";
					cin >> check;
					if(check=='y' || check=='Y')
					{
						result=expression.evaluatePrefix(prefix);
						cout << "\nValue of the expression is " << result << endl;
					}
				}
				break;
			}
			case 3:	break;
			default:
			{
				cout << "\nInvalid Input!\n";
				break;
			}
		}
	}
	while(choice!=3);
	
	return 0;
}

int convert::evaluatePrefix(char prefix[])
{
	stack s;
	char x;
	int op1, op2, value, i, length=0;
	while(prefix[length]!='\0')
	{
		length++;
	}
	for(i=length-1; i>=0; i--)
	{
		x=prefix[i];
		if(isalpha(x))
		{
			cout << "\nEnter the value of " << x << ": ";
			cin >> value;
			s.push(value);
		}
		else
		{
			op1=s.pop();
			op2=s.pop();
			value=evaluate(x, op1, op2);
			s.push(value);
		}
	}
	value=s.pop();
	return value;
}

int convert::evaluatePostfix(char postfix[]) /*function to evaluate postfix expression*/
{
	stack s;
	char x;
	int op1, op2, value, i;
	for(i=0; postfix[i]!='\0'; i++)
	{
		x=postfix[i];
		if(isalpha(x))
		{
			cout << "\nEnter the value of " << x << ": ";
			cin >> value;
			s.push(value);
		}
		else
		{
			op2=s.pop();
			op1=s.pop();
			value=evaluate(x, op1, op2);
			s.push(value);
		}
	}
	value=s.pop();
	return value;
}

int convert::evaluate(char x, int op1, int op2) /*function to get value of an expression*/
{
	if(x=='+')
		return(op1+op2);
	else if(x=='-')
		return(op1-op2);
	else if(x=='*')
		return(op1*op2);
	else if(x=='/')
		return(op1/op2);
	else if(x=='^')
		return(pow(op1, op2));
}

int convert::infixToPostfix(char infix[], char postfix[]) /*function to convert expression from infix to postfix*/
{
	if(inputValidation(infix)==-1)
	{
		return -1;
	}
	else
	{
		stack s;
		char c, scan;
		int i, j=0;
		for(i=0; infix[i]!='\0'; i++)
		{
			scan=infix[i];
			if((scan>='a' && scan<='z') || (scan>='A' && scan<='Z') || (scan>='0' && scan<='9'))
			{
				postfix[j]=scan;
				j++;
			}
			else if(scan=='(')
			{
				s.push(scan);
			}
			else if(scan==')')
			{
				while(s.getTop()!='(')
				{
					c=s.pop();
					postfix[j]=c;
					j++;
				}
				if(s.getTop()=='(')
				{
					c=s.pop();
				}
			}
			else
			{
				while(precedence(scan)<=precedence(s.getTop()) && !s.empty())
				{
					c=s.pop();
					postfix[j]=c;
					j++;
				}
				s.push(scan);
			}	
		}
		while(!s.empty())
		{
			c=s.pop();
			postfix[j]=c;
			j++;
		}
		postfix[j]='\0';
		return 0;
	}
}

int convert::inputValidation(char exp[]) /*function to validate input expression*/
{
	int i, opening=0, closing=0, operands=0, operators=0;
	for(i=0; exp[i]!='\0'; i++)
	{
		if(exp[i]=='(')
			opening++;
		else if(exp[i]==')')
			closing++;
		else if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9'))
			operands++;
		else
			operators++;
	}
	if(opening!=closing || operators>=operands)
		return -1;
	else
		return 1;
}

int convert::precedence(char c) /*function to get priority of operators*/
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
}

int convert::infixToPrefix(char infix[], char prefix[]) /*function to convert expression from infix to prefix*/
{
	char rInfix[50], temp[50];
	int i, j, length=0, check;
	while(infix[length]!='\0')
		length++;
	for(i=length-1, j=0;i>=0; i--, j++)
	{
		if(infix[i]=='(')
		{
			rInfix[j]=')';
		}
		else if(infix[i]==')')
		{
			rInfix[j]='(';
		}
		else
		{
			rInfix[j]=infix[i];
		}
	}
	rInfix[j]='\0';
	check=infixToPostfix(rInfix, temp);
	if(check==-1)
	{
		return -1;
	}
	else
	{
		length=0;
		while(temp[length]!='\0')
			length++;
		for(i=length-1, j=0;i>=0; i--, j++)
		{
			prefix[j]=temp[i];
		}
		prefix[j]='\0';
		return 1;
	}
}

stack::stack() /*constructor*/
{
	top=NULL;
}

void stack::push(char c) /*function to push elements on stack*/
{
	node *temp=new node;
	if(temp==NULL)
	{
		cout << "\nStack Overflow!\n";
	}
	else
	{
		temp->data=c;
		temp->next=top;
		top=temp;
	}
}

char stack::pop() /*function to pop elements from stack*/
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		node *temp=new node;
		char c;
		c=top->data;
		temp=top;
		top=top->next;
		temp->next=NULL;
		return c;
	}
}

int stack::empty() /*function to check if the stack is empty*/
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char stack::getTop() /*function to get element on top of the stack*/
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return top->data;
	}
}
