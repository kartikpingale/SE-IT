#include<iostream>
#include<fstream>

using namespace std;

class myfile
{
	public:
	int roll;
	char name[30];
	float per;
	char read[100];
	void writefile()
	{
		fstream data;
		cout << "Enter roll no.: ";
		cin >> roll;
		cin.ignore();
		cout << "Enter name: ";
		cin.getline(name, 30);
		cout << "Enter percentage: ";
		cin >> per;
		
		data.open("data.txt", ios::out|ios::app);
		data << "Roll no.: " << roll << endl;
		data << "Name: " << name << endl;
		data << "Percentage: " << per << endl;
		data.close();
	}
	void readfile()
	{
		fstream data;
		data.open("data.txt", ios::in);
		data.seekg(0);
		while(!data.eof())
		{
			data.getline(read, 100);
			cout << read << endl;
		}
		data.close();
	}
};

int main()
{
	myfile f;
	int choice;
	char repeat;
	
	do
	{
		cout << "\n1. Write Data\n2. Read Data\nEnter your choice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
			{
				f.writefile();
				break;
			}
			case 2:
			{
				f.readfile();
				break;
			}
			default:
			{
				cout << "\nInvalid input!";
				break;
			}
		};
		
		cout << "\nDo you want to perform another operation? (y/n)";
		cin >> repeat;
	}
	while(repeat=='y' || repeat=='Y');
	
	return 0;
}
