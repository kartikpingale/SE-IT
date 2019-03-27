#include<iostream>

using namespace std;

class node
{
	public:
	char name[30];
	int priority;
	node *next;
};

class queue
{
	public:
	node *front, *rear;
	queue();
	void enqueue();
	void dequeue();
	void display();
};

int main()
{
	queue patients;
	int choice;
	do
	{
		cout << "\n1. Enter patient data\n2. Remove patient data\n3. Display priority queue\n4. Exit\nEnter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				patients.enqueue();
				break;
			}
			case 2:
			{
				patients.dequeue();
				break;
			}
			case 3:
			{
				patients.display();
				break;
			}
			case 4:	break;
			default:
			{
				cout << "\nInvalid Input!\n";
				break;
			}
		}
	}
	while(choice!=4);
	return 0;
}

queue::queue()
{
	front=NULL;
	rear=NULL;
}

void queue::enqueue()
{
	int illness, error=0;
	node *patient=new node;
	cout << "\nEnter patient's name: ";
	cin.ignore();
	cin.getline(patient->name, 30);
	do
	{
		cout << "\n1. Serious\n2. Medium\n3. General\nSelect the illness: ";
		cin >> illness;
		switch(illness)
		{
			case 1:
			{
				patient->priority=3;
				break;
			}
			case 2:
			{
				patient->priority=2;
				break;
			}
			case 3:
			{
				patient->priority=1;
				break;
			}
			default:
			{
				cout << "\nInvalid Input!\n";
				error=1;
				break;
			}
		}
	}
	while(error==1);
	
	if(rear==NULL)
	{
		patient->next=NULL;
		front=patient;
		rear=patient;
	}
	else if(patient->priority > front->priority)
	{
		patient->next=front;
		front=patient;
	}
	else
	{
		node *prev, *temp=front;
		while((patient->priority <= temp->priority) && temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp->next==NULL && temp->priority>=patient->priority)
		{
			temp->next=patient;
			patient->next=NULL;
			return;
		}
		prev->next=patient;
		patient->next=temp;
	}
}

void queue::dequeue()
{
	if(front==NULL)
	{
		cout << "\nEmpty Queue!\n";
	}
	else
	{
		cout << "\nPatient served!\nName: " << front->name << endl;
		if(front->priority==1)
		{
			cout << "Illness: General\n";
		}
		else if(front->priority==2)
		{
			cout << "Illness: Medium\n";
		}
		else
		{
			cout << "Illness: Serious\n";
		}
		node *temp=front;
		front=front->next;
		delete temp;
	}
}

void queue::display()
{
	if(front==NULL)
	{
		cout << "\nEmpty Queue!\n";
	}
	else
	{
		cout << "\nPatient Priority Queue:\n\nSr. No.\t\tName\t\t\tIllness\n";
		cout << "-------------------------------------\n";
		int i=1;
		node *temp=front;
		while(temp!=NULL)
		{
			cout << i << "\t\t" << temp->name << "\t\t";
			if(temp->priority==3)
				cout << "Serious\n";
			else if(temp->priority==2)
				cout << "Medium\n";
			else
				cout << "General\n";
			i++;
			temp=temp->next;
		}
	}
}
