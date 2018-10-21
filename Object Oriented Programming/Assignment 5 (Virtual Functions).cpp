#include<iostream>

using namespace std;

class shape
{
	protected:
	float side1, side2;
	public:
	void accept()
	{
		cout << "Enter sides: ";
		cin >> side1 >> side2;
	}
	virtual void compute_area()=0;
};

class triangle: public shape
{
	public:
	void compute_area()
	{
		cout << "\nThe area of the triangle is " << 0.5*side1*side2;
	}
};

class rectangle: public shape
{
	public:
	void compute_area()
	{
		cout << "\nThe area of the rectangle is " << side1*side2;
	}
};

int main()
{
	shape *S;
	triangle T;
	rectangle R;
	int choice;
	
	do
	{
		cout<<"\n1. Triangle\n2. Rectangle\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					S=&T;
					S->accept();
					S->compute_area();
					break;
				}
			case 2:
				{
					S=&R;
					S->accept();
					S->compute_area();
					break;
				}
			default:
				{
					cout << "\nWrong Choice";
					break;
				}
		}
	}
	while(choice<3 && choice>0);
	
	return 0;
}
