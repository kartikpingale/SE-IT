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

int create();
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
    struct student s[10];
    int choice, size, sr;
    char repeat='y';
    
    while(repeat=='y' || repeat=='Y')
	{
		printf("Enter the operation you want to perform\n1. Create Database\n2. Display Database\n3. Add Record\n4. Search Record\n5. Modify Record\n6. Delete Record\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					size = create();
					break;
				}
			case 2:
				{
                    printf("Enter serial no. of student: ");
                    scanf("%d", &sr);
					display(s, sr);
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

int create()
{
    int size;
    
    printf("Enter the no. of students: ");
    scanf("%d", &size);
    
    printf("Database created!\n");
    
    return size;
}

void display(struct student xyz[], int serial)
{
    printf("Name: %s\nRoll number: %d\n", xyz[serial].name, xyz[serial].roll);
}

void add()
{
    
}
