#include<iostream>

using namespace std;

class Base1
{
	public:
	int id;
	char name[30], dob[20], bloodgroup[10];
};

class Base2
{
	public:
	float height, weight;
};

class Base3
{
	public:
	char policy[10], address[50];
};

class Intermediate: public Base1, public Base2, public Base3
{
	public:
	char telephone[10], license[10];
};

class Derived: public Intermediate
{
	public:
	void create()
	{
		cout << "Enter ID: ";
		cin >> id;
		cin.ignore();
		cout << "Enter name: ";
		cin.getline(name, 30);
		cout << "Enter date of birth: ";
		cin.getline(dob, 20);
		cout << "Enter blood group: ";
		cin.getline(bloodgroup, 10);
		
		cout << "Enter height: ";
		cin >> height;
		cout << "Enter weight: ";
		cin >> weight;
		
		cout << "Enter policy number: ";
		cin >> policy;
		cin.ignore();
		cout << "Enter address: ";
		cin.getline(address, 50);
		
		cout << "Enter telephone number: ";
		cin >> telephone;
		cout << "Enter license number: ";
		cin >> license;
	}
	
	void display(Derived d[], int n)
	{
		int i;
		for(i=0; i<n; i++)
		{
			cout << "\nID: " << d[i].id;
			cout << "\nName: " << d[i].name;
			cout << "\nDate of birth: " << d[i].dob;
			cout << "\nBlood group: " << d[i].bloodgroup;		
			cout << "\nHeight: " << d[i].height;
			cout << "\nWeight: " << d[i].weight;
			cout << "\nPolicy number: " << d[i].policy;
			cout << "\nAddress: " << d[i].address;
			cout << "\nTelephone number: " << d[i].telephone;
			cout << "\nLicense number: " << d[i].license << endl;
		}
	}
	
	int deleteRecord(Derived d[], int n)
	{
		int i, pos, field;
		cout << "\nEnter ID to delete: ";
		cin >> field;
		pos=search(d, n, field);
		if(pos==-1)
			cout << "\nRecord not found!";
		else
		{
			if(pos==0)
			{
				for(i=1; i<n; i++)
				{
					d[i-1]=d[i];
				}
			}
			else
			{
				for(i=(pos+1); i<n; i++)
				{
					d[i-1]=d[i];
				}
			}
			n--;
			cout << "\nRecord deleted!" << endl;;
		}
		return n;
	}
	
	void edit(Derived d[], int n)
	{
		int result, field;
		cout << "\nEnter ID to edit: ";
		cin >> field;
		cin.ignore();
		result=search(d, n, field);
		if(result==-1)
			cout << "\nRecord not found!";
		else
		{
			cout << "\nEnter modified data!\n";
			cout << "Enter name: ";
			cin.getline(d[result].name, 30);
			cout << "Enter date of birth: ";
			cin.getline(d[result].dob, 20);
			cout << "Enter blood group: ";
			cin.getline(d[result].bloodgroup, 10);
			cout << "Enter height: ";
			cin >> d[result].height;
			cout << "Enter weight: ";
			cin >> d[result].weight;
			cout << "Enter policy number: ";
			cin >> d[result].policy;
			cin.ignore();
			cout << "Enter address: ";
			cin.getline(d[result].address, 50);
			cout << "Enter telephone number: ";
			cin >> d[result].telephone;
			cout << "Enter license number: ";
			cin >> d[result].license;
		}
	}
	
	int search(Derived d[], int n, int key)
	{
		int i;
		for(i=0; i<n; i++)
		{
			if(key==d[i].id)
				return i;
		}
		return -1;
	}
	
	void putRecord(Derived d[], int i)
	{
		cout << "\nRecord found!\nID: " << d[i].id;
		cout << "\nName: " << d[i].name;
		cout << "\nDate of birth: " << d[i].dob;
		cout << "\nBlood group: " << d[i].bloodgroup;		
		cout << "\nHeight: " << d[i].height;
		cout << "\nWeight: " << d[i].weight;
		cout << "\nPolicy number: " << d[i].policy;
		cout << "\nAddress: " << d[i].address;
		cout << "\nTelephone number: " << d[i].telephone;
		cout << "\nLicense number: " << d[i].license << endl;
	}
};

int main()
{
	Derived d[20], D;
	int choice, n, i, field, result;
	char repeat;
	
	do
	{
		cout << "\n1. Create record\n2. Display records\n3. Insert a record\n4. Edit record\n5. Search record\n6. Delete record\nEnter your choice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				{
					cout << "\nEnter no. of records you want to create: ";
					cin >> n;
					for(i=0; i<n; i++)
						d[i].create();
					break;
				}
			case 2:
				{
					D.display(d, n);
					break;
				}
			case 3:
				{
					d[n].create();
					n++;
					break;
				}
			case 4:
				{
					D.edit(d, n);
					break;
				}
			case 5:
				{
					cout << "\nEnter ID to search: ";
					cin >> field;
					result=D.search(d, n, field);
					if(result==-1)
						cout << "\nRecord not found!";
					else
						D.putRecord(d, result);					
					break;
				}
			case 6:
				{
					n=D.deleteRecord(d, n);
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
