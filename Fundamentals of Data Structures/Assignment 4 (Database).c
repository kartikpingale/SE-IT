/*
PROBLEM STATEMENT -
Create a Database using array of structures and perform following operations on it:
i. Create Database
ii. Display Database
iii. Add record
iv. Search record
v. Modify record
vi. Delete record
*/

#include <stdio.h>

typedef struct 
{
	int id;
	char name[30];
	char designation[30];
	float salary;
}employee;

employee read();
void display(employee emp);
int delete(employee emp[], int pos, int size);
int search(employee emp[], int id, int size);
int modify(employee emp[], int id, int size);
int add(employee emp[], int size);

static int ID=1;

int main()
{
	employee e[20];
	int size=1, i, choice, searchField, searchFlag;
	char repeat='y';
	
	while(repeat=='y' || repeat=='Y')
	{
		printf("\n1. Create database\n2. Display\n3. Add\n4. Search\n5. Modify\n6. Delete\nSelect your option: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					do
					{
						printf("\nEnter no. of employees: ");
						scanf("%d", &size);
					}
					while(size<=0);
	
					for(i=0; i<size; i++)
					{
						e[i]=read();
					}
					
					printf("Database created!\n");
					break;
				}
			case 2:
				{
					for(i=0; i<size; i++)
					{
						display(e[i]);
					}
					break;
				}
			case 3:
				{
					size=add(e, size);
					break;
				}
			case 4:
				{
					printf("\nEnter employee ID to search: ");
					scanf("%d", &searchField);
				
					searchFlag=search(e, searchField, size);
				
					if(searchFlag==-1)
					{
						printf("\nCannot find employee with ID %d\n", searchField);
					}
					else
					{
						printf("\nEmployee with ID %d found!", searchField);
						display(e[searchFlag]);
					}
					break;
				}
			case 5:
				{
					printf("\nEnter employee ID to modify: ");
					scanf("%d", &searchField);

					searchFlag=modify(e, searchField, size);

					if(searchFlag==-1)
					{
						printf("\nCannot find employee with ID %d\n", searchField);
					}
					else
					{
						printf("\nData for employee with ID %d modified!", searchField);
						display(e[searchFlag]);
					}
					break;
				}
			case 6:
				{
					printf("\nEnter employee ID to delete: ");
					scanf("%d", &searchField);

					searchFlag=search(e, searchField, size);

					if(searchFlag==-1)
					{
						printf("\nCannot find employee with ID %d\n", searchField);
					}
					else
					{
						size=delete(e, searchFlag, size);
						printf("Employee with ID %d deleted!", searchField);
					}
					break;
				}
			default:
				{
					printf("\nInvalid selection! Enter a number between 1-5!\n");
					break;
				}
		}
		printf("\nDo you want to perform another operation? (y/n)");
		scanf(" %c", &repeat);
	}
	
	return 0;
}

employee read()
{
	employee emp;
	emp.id=ID;
	ID++;
	printf("\nEnter name: ");
	scanf("%s", emp.name);
	printf("Enter designation: ");
	scanf("%s", emp.designation);
	printf("Enter salary: ");
	scanf("%f", &emp.salary);
	return emp;
}

void display(employee emp)
{
	printf("\nEmployee ID: %d", emp.id);
	printf("\nName: %s", emp.name);
	printf("\nDesignation: %s", emp.designation);
	printf("\nSalary: %0.2f\n", emp.salary);
}

int search(employee emp[], int id, int size)
{
	int i, flag=0;
	for(i=0; i<size; i++)
	{
		if(emp[i].id==id)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int delete(employee emp[], int pos, int size)
{
	int i;
	if(pos==(size-1))
	{}
	else if(pos==0)
	{
		for(i=1; i<size; i++)
		{
			emp[i-1]=emp[i];
		}
	}
	else
	{
		for(i=(pos+1); i<size; i++)
		{
			emp[i-1]=emp[i];
		}
	}
	size--;
	return size;
}

int modify(employee emp[], int id, int size)
{
	int choice, i, flag;
	char repeat='y';
	flag=search(emp, id, size);
	if(flag==-1)
	{
		return -1;
	}
	else
	{
		while(repeat=='y' || repeat=='Y')
		{
			printf("\n1. Name\n2. Designation\n3. Salary\nSelect field to modify: ");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
				{
					printf("Enter name: ");
					scanf("%s", emp[flag].name);
					break;
				}
				case 2:
				{
					printf("Enter designation: ");
					scanf("%s", emp[flag].designation);
					break;
				}
				case 3:
				{
					printf("Enter salary: ");
					scanf("%f", &emp[flag].salary);
					break;
				}
				default:
				{
					printf("\nInvalid selection! Enter a number between 1-3!\n");
					break;
				}
			}
			printf("\nDo you want to modify another field? (y/n)");
			scanf(" %c", &repeat);
		}
		return flag;
	}
}

int add(employee emp[], int size)
{
	int i;
	for(i=size; i<=size; i++)
	{
		emp[i]=read();
	}
	size++;
	return size;
}
