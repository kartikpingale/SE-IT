#include<iostream>

using namespace std;

class A
{
	double x,y;
	public:
	void accept()
	{
		cout << "\nEnter two numbers: ";
		cin >> x >> y;
	}
	double divide()
	{
		try
		{
			if(y==0)
				throw(y);
			cout << "\nDivision of the entered numbers is " << x/y << endl;
		}
		catch(double p)
		{
			cout << "\nDivide by zero exception" << endl;
		}
	}
};

int main()
{
	A obj;
	obj.accept();
	obj.divide();
	return 0;
}
