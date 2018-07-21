#include<stdio.h>

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

void create();
void display();
void add();
void search();
void modify();
void delete();

struct student
{
    char name[10];
    int roll;
};

int main()
{
    student s[10];
    int size, choice;
    char repeat='y';
    
    printf("Enter the no. of students: ");
    scanf("%d", &size);
    
    while(repeat=='y' || repeat=='Y')
	{
		printf("Enter the operation you want to perform\n1. Create Database\n2. Display Database\n3. Add Record\n4. Search Record\n5. Modify Record\n6. Delete Record\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					
					break;
				}
			case 2:
				{
					
					break;
				}
			case 3:
				{
					
					break;
				}
			case 4:
				{
					
					break;
				}
            case 5:
				{
					
					break;
				}
			case 6:
				{
					
					break;
				}
			default:
				{
					printf("Incorrect selection! Enter a number between 1-6\n");
					break;
				}
		}
		printf("Do you want to perform any operation again? (y/n)\n");
		scanf(" %c", &repeat);
	}
    return 0;
}
