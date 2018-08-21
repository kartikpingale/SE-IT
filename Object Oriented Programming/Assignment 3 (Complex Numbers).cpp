#include<iostream>

using namespace std;

class complex
{
	int real, imaginary;
	
	public:
	complex()
	{
		real=0;
		imaginary=0;
	}
	complex(int a, int b)
	{
		real=a;
		imaginary=b;
	}
	void getData();
	void putData(complex &number);
	friend complex add(complex &a, complex &b);
	friend complex subtract(complex &a, complex &b);
	complex multiply(complex &a, complex &b)
	{
		complex product;
		product.real = (a.real+b.real) + (-1*a.imaginary*b.imaginary);
		product.imaginary = (a.real*b.imaginary) + (b.real*a.imaginary);
		return product;
	}
	complex divide(complex &a, complex &b)
	{
		complex division;
		
		return division;
	}
};

int main()
{
	complex number1, number2, number3;
	int choice;
	char repeat='y';
	
	while(repeat=='y' || repeat=='Y')
	{
		cout << "First number\n";
		number1.getData();
		cout << "\nSecond number\n";
		number2.getData();
		
		cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nSelect the operation: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					number3=add(number1, number2);
					number3.putData(number3);
					break;
				}
			case 2:
				{
					number3=subtract(number1, number2);
					number3.putData(number3);
					break;
				}
			case 3:
				{
					number3=number3.multiply(number1, number2);
					number3.putData(number3);
					break;
				}
			case 4:
				{
					number3=number3.divide(number1, number2);
					number3.putData(number3);
					break;
				}
			default:
				{
					cout << "Invalid selection! Select a number between 1-4";
					break;
				}
		}
		cout << "\nDo you want to perform another operation? (y/n)";
		cin >> repeat;
	}
	
	return 0;
}

void complex::getData()
{
	cout << "Enter real part: ";
	cin >> real;
	cout << "Enter imaginary part: ";
	cin >> imaginary;
}

void complex::putData(complex &number)
{
	if(number.imaginary>=0)
		cout << "\n" << real << "+" << imaginary << "i\n";
	else
		cout << "\n" << real << imaginary << "i\n";
}

complex add(complex &a, complex &b)
{
	complex sum;
	sum.real = a.real+b.real;
	sum.imaginary = a.imaginary+b.imaginary;
	return sum;
}

complex subtract(complex &a, complex &b)
{
	complex diff;
	diff.real = a.real-b.real;
	diff.imaginary = a.imaginary-b.imaginary;
	return diff;
}
