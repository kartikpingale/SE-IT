#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class file
{
	int roll, age;
	char name[20];
	public:
		void getdata()
		{
			ofstream fout;
			fout.open("myfile1.txt", ios::app|ios::out);
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter roll number: ";
			cin >> roll;
			cout << "Enter age: ";
			cin >> age;
			fout << name << endl << roll << endl << age;

		}
		void display()
		{
			ifstream fin;
			fin.open("myfile1.txt");
			while(!fin.eof())
			{
				fin >> name >> roll >> age;
				cout << "\n" << name << "\t" << roll << "\t" << age << endl;
			}
		}
		void dlete()
		{
			ifstream fin;
			ofstream nik;
			char name1[20];
			fin.open("myfile1.txt");
			nik.open("mfile.txt");
			cout<<"Enter name to be deleted : ";
			cin>>name1;
			while(!fin.eof())
			{
				fin>>name>>roll>>age;
				if((strcmp(name,name1))!=0)
				nik<<name<<endl<<roll<<endl<<age;
			}
			fin.close();
			nik.close();
			remove("myfile1.txt");
			rename( "mfile.txt","myfile1.txt");
			cout<<"\nAfter deletion: \n";
		}
		void modify()
		{
		    char name1[20];
		    int choice=0;
		    ifstream fin;
		    ofstream nik;
            fin.open("myfile1.txt");
			nik.open("mfile.txt");
			cout<<"Enter name to be modified: ";
			cin>>name1;
			while(!fin.eof())
			{
				fin>>name>>roll>>age;
				if((strcmp(name,name1))==0)
                {
					while(choice!=4)
                  	{
                    	cout<<"\n1.Name\n2.Age\n3.Roll Number\n4.Exit\n";
                    	cin>>choice;
                    	switch(choice)
						{
                        	case 1:	cout<<"Enter name: ";
                                	cin>>name;
									break;
                        	case 2:	cout<<"Enter age: ";
                                	cin>>age;
									break;
                        	case 3:	cout<<"Enter roll no.: ";
                                	cin>>roll;
									break;
                    	}
                  	}
					cout<<"\nModified data: \n";
					cout<<"\nNAME\tROLL\tAGE\n";
					cout<<name<<"\t"<<roll<<"\t"<<age<<endl;
                }
				nik<<name<<endl<<roll<<endl<<age;
			}
			fin.close();
			nik.close();
			remove("myfile1.txt");
			rename("mfile.txt", "myfile1.txt");
			if(choice==0)
                cout<<"\nRequested data not found\n";
            else
                cout<<"\nAfter modification: \n";
		}
};
int main()
{
	file obj;
	ofstream fout;
	fout.open("myfile1.txt", ios::trunc);
	fout.close();
	ifstream fin;
	int n, i, choice=0;
	while(choice!=6)
	{
		cout<<"\n1.Create Database\n2.Display\n3.Add\n4.Delete\n5.Modify\n6.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"Enter number of students : ";
					cin>>n;
					cout<<"\nEnter data: " << endl;
					for(i=0; i<n; i++)
					{
						obj.getdata();
					}
					break;
				}
			case 2:
				{
					cout<<"\nNAME\tROLL\tAGE\n";
					obj.display();
					break;
				}
			case 3:
				{
					obj.getdata();
                    cout<<"\nNew data: \n";
					cout<<"\nNAME\tROLL\tAGE\n";
                    obj.display();
                    break;
				}
			case 4:
				{
					obj.dlete();
					cout<<"\nNAME\tROLL\tAGE\n";
					obj.display();
					break;
				}
			case 5:
				{
					obj.modify();
					obj.display();
					break;
				}
			case 6: break;
			default:
				{
					cout << "Invalid choice!" << endl;
				}
		}
	}
}
