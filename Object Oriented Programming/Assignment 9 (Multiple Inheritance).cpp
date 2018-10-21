#include<iostream>

using namespace std;

class Personal
{
	public:
	char name[30], email[20], address[30];
	int age;
	void getPersonalData()
	{
		cin.ignore();
		cout << "Enter name: ";
		cin.getline(name, 30);
		cout << "Enter age: ";
		cin >> age;
		cin.ignore();
		cout << "Enter email ID: ";
		cin.getline(email, 20);
		cout << "Enter address: ";
		cin.getline(address, 30);
	}
};

class Professional
{
	public:
	int exp, salary;
	char skills[50], designation[20];
	void getProfessionalData()
	{
		cout << "Enter designation: ";
		cin.getline(designation, 20);
		cout << "Enter salary: ";
		cin >> salary;
		cout << "Enter work experience in years: ";
		cin >> exp;
		cin.ignore();
		cout << "Enter professional skills: ";
		cin.getline(skills, 50);
	}
};

class Academic
{
	public:
	int passYear;
	float cgpa;
	char degree[10], college[20];
	void getAcademicData()
	{
		cout << "Enter degree: ";
		cin.getline(degree, 10);
		cout << "Enter college: ";
		cin.getline(college, 20);
		cout << "Enter CGPA: ";
		cin >> cgpa;
		cout << "Enter year of passing: ";
		cin >> passYear;
	}
};

class Biodata: public Personal, public Professional, public Academic
{
	public:
	void createBiodata()
	{
		cout << "\nPERSONAL DETAILS\nName: " << name;
		cout << "\nAge: " << age;
		cout << "\nEmail ID: " << email;
		cout << "\nAddress: " << address << endl;
		
		cout << "\nACADEMIC DETAILS\nDegree: " << degree;
		cout << "\nCollege: " << college;
		cout << "\nCGPA: " << cgpa;
		cout << "\nYear of passing: " << passYear << endl;
		
		cout << "\nPROFESSIONAL DETAILS\nDesignation: " << designation;
		cout << "\nSalary: " << salary;
		cout << "\nWork experience: " << exp << " years";
		cout << "\nProfessional skills: " << skills << endl;
	}
};

int main()
{
	Biodata b;
	int choice;
	char repeat;
	
	do
	{
		cout << "\n1. Enter details\n2. Create biodata\nEnter your choice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				{
					b.getPersonalData();
					b.getProfessionalData();
					b.getAcademicData();
					break;
				}
			case 2:
				{
					b.createBiodata();
					break;
				}
			default:
				{
					cout << "\nInvalid Input!";
					break;
				}
		}
		
		cout << "\nDo you want to perform another operation? (y/n)\n";
		cin >> repeat;
	}
	while(repeat=='y' || repeat=='Y');
	
	return 0;
}
