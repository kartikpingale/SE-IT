#include<stdio.h>

typedef struct
{
	int roll;
	char name[30];
	int marks;
	char grade;
}student;

student read();
void display(student s);
char getGrade(int marks);
void add(char filename[]);
void disp(char filename[]);
void search(char filename[]);
void modify(char filename[]);
void delete(char filename[]);

static int ROLL=0;

int main()
{
	student s;
	char filename[10], repeat;
	int choice;
	
	printf("Enter the filename: ");
	scanf("%s", filename);
	
	do
	{
		printf("\n1. Add\n2. Display\n3. Search\n4. Modify\n5. Delete\nEnter your selection: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					add(filename);
					break;
				}
			case 2:
				{
					disp(filename);
					break;
				}
			case 3:
				{
					search(filename);
					break;
				}
			case 4:
				{
					modify(filename);
					break;
				}
			case 5:
				{
					delete(filename);
					break;
				}
			default:
				{
					printf("\nInvalid input! Enter a number between 1-5!");
					break;
				}
		}
		
		printf("\nDo you want to perform another operation?(y/n)\n");
		scanf(" %c", &repeat);
	}
	while(repeat=='y' || repeat=='Y');
	
	return 0;
}

student read()
{
	student s;
	
	ROLL++;
	s.roll=ROLL;
	printf("\nEnter name: ");
	scanf("%s", s.name);
	printf("Enter marks: ");
	scanf("%d", &s.marks);
	s.grade=getGrade(s.marks);
	return s;
}

student readModified(int roll)
{
	student s;
	
	s.roll=roll;
	printf("\nEnter name: ");
	scanf("%s", s.name);
	printf("Enter marks: ");
	scanf("%d", &s.marks);
	s.grade=getGrade(s.marks);
	return s;
}

void display(student s)
{
	printf("\n%d\t\t%s\t\t%d\t\t%c", s.roll, s.name, s.marks, s.grade);
}

char getGrade(int marks)
{
	if(marks>=80)
		return 'O';
	else if(marks>=60 && marks<80)
		return 'A';
	else if(marks>=40 && marks<60)
		return 'B';
	else
		return 'F';
}

void add(char filename[])
{
	FILE *fp;
	student s;
	int count=0;
	
	fp=fopen(filename, "ab");
	fclose(fp);
	
	fp=fopen(filename, "rb");
	if(fp!=NULL)
	{
		while(fread(&s, sizeof(student), 1, fp))
		{
			count++;
		}
		
		if(count!=0)
		{
			ROLL=s.roll;
		}
		else
		{
			ROLL=count;
		}
		
	}
	fclose(fp);
	
	fp=fopen(filename, "ab+");
	
	if(fp == NULL)
		printf("\nFile Not Created!");
	else
	{
		s=read();
		fwrite(&s, sizeof(student), 1, fp);
	}
	
	fclose(fp);
}

void disp(char filename[])
{
	FILE *fp;
	student s;
	
	fp=fopen(filename, "rb");
	
	if(fp == NULL)
		printf("\nFile Not Created!");
	else
	{
		printf("\nFile Opened!\n");
		printf("\nROLL\t\tNAME\t\tMARKS\t\tGRADE\n");
		printf("------------------------------------------------------");
		while(fread(&s, sizeof(student), 1, fp))
		{
			display(s);
		}
		printf("\n");
	}
	
	fclose(fp);
}

void search(char filename[])
{
	FILE *fp;
	student s;
	int field, flag=0;
	
	printf("\nEnter roll no. to search: ");
	scanf("%d", &field);
	
	fp=fopen(filename, "rb");
	
	if(fp == NULL)
		printf("\nFile Not Created!");
	else
	{
		printf("\nFile Opened!");
		while(fread(&s, sizeof(student), 1, fp))
		{
			if(s.roll==field)
			{
				flag=1;
				printf("\nRecord found!");
				display(s);
			}
		}
	}
	
	fclose(fp);
	
	if(flag!=1)
	{
		printf("\nRecord not found!");
	}
}

void modify(char filename[])
{
	FILE *fp, *tp;
	student s;
	int field, flag=0;
	
	printf("\nEnter roll no. to modify: ");
	scanf("%d", &field);
	
	fp=fopen(filename, "rb");
	tp=fopen("temp.txt", "ab+");
	
	if(fp == NULL)
		printf("\nFile Not Created!");
	else
	{
		printf("\nFile Opened!");
		while(fread(&s, sizeof(student), 1, fp))
		{
			if(s.roll==field)
			{
				flag=1;
				printf("\nEnter modified data:\n");
				s=readModified(field);
				fwrite(&s, sizeof(student), 1, tp);
			}
			else
			{
				fwrite(&s, sizeof(student), 1, tp);
			}
		}
	}
	
	if(flag!=1)
	{
		printf("\nRecord not found!");
	}
	
	fclose(fp);
	fclose(tp);
	remove(filename);
	rename("temp.txt", filename);
}

void delete(char filename[])
{
	FILE *fp, *tp;
	student s;
	int field, flag=0;
	
	printf("\nEnter roll no. to delete: ");
	scanf("%d", &field);
	
	fp=fopen(filename, "rb");
	tp=fopen("temp.txt", "ab+");
	
	if(fp == NULL)
		printf("\nFile Not Created!");
	else
	{
		while(fread(&s, sizeof(student), 1, fp))
		{
			if(s.roll==field)
			{
				flag=1;
				printf("\nRecord deleted!\n");
				continue;
			}
			else
			{
				fwrite(&s, sizeof(student), 1, tp);
			}
		}
	}
	
	if(flag!=1)
	{
		printf("\nRecord not found!");
	}
	
	fclose(fp);
	fclose(tp);
	remove(filename);
	rename("temp.txt", filename);
}
