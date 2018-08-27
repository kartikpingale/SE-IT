#include<iostream>

using namespace std;

class complex
{
	float real;
	float imaginary;
	
	public:
	complex()
	{
		real=0;
		imaginary=0;
	}
	complex(float a, float b)
	{
		real=a;
		imaginary=b;
	}
    
	void putData(complex &number);
	
	complex friend operator + (complex a, complex b);
	complex friend operator - (complex a, complex b);
	
	complex operator * (complex &number)
	{
		complex product;
		product.real = (real*number.real) - (imaginary*number.imaginary);
		product.imaginary = (real*number.imaginary) + (number.real*imaginary);
		return product;
	}
	
	complex operator / (complex &number)
	{
		complex division;
        float mod=(number.real*number.real + number.imaginary*number.imaginary);
        division.real = ((real*number.real) + (imaginary*number.imaginary))/(mod);
        division.imaginary = ((imaginary*number.real) - (real*number.imaginary))/(mod);
		return division;
	}
};

int main()
{
	complex answer;
	int choice;
	float Re, Im;
	char repeat='y';
	
	while(repeat=='y' || repeat=='Y')
	{
		cout << "First number\nEnter real part: ";
		cin >> Re;
		cout << "Enter imaginary part: ";
		cin >> Im;
		complex number1(Re, Im);
		
		cout << "\nSecond number\nEnter real part: ";
		cin >> Re;
		cout << "Enter imaginary part: ";
		cin >> Im;
		complex number2(Re, Im);
		
		cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nSelect the operation: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					answer = number1 + number2;
					answer.putData(answer);
					break;
				}
			case 2:
				{
					answer = number1 - number2;
					answer.putData(answer);
					break;
				}
			case 3:
				{
					answer = number1 * number2;
					answer.putData(answer);
					break;
				}
			case 4:
				{
					answer = number1 / number2;
					answer.putData(answer);
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

void complex::putData(complex &number)
{
	if(number.imaginary>=0)
		cout << "\n" << real << "+" << imaginary << "i\n";
	else
		cout << "\n" << real << imaginary << "i\n";
}

complex operator + (complex a, complex b)
{
	complex sum;
	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

complex operator - (complex a, complex b)
{
	complex diff;
	diff.real = a.real - b.real;
	diff.imaginary = a.imaginary - b.imaginary;
	return diff;
}
