#include<stdio.h>
#include<stdlib.h>

struct node
{
	int roll, marks;
	char name[30];
	struct node *prev, *next;
};

struct node* create();
void fDisplay(struct node *s);
void rDisplay(struct node *s);
struct node* insert(struct node *s);
void modify(struct node *s);
struct node * delete(struct node *s);

int main()
{
	struct node *head;
	int choice;
	head=create();
	do
	{
		printf("\n1. Insert\n2. Display\n3. Modify\n4. Delete\n5. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					head=insert(head);
					break;
				}
			case 2:
				{
					printf("1. Forward\n2. Reverse\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								fDisplay(head);
								break;
							}
						case 2:
							{
								rDisplay(head);
								break;
							}
					}
					break;
				}
			case 3:
				{
					modify(head);
					break;
				}
			case 4:
				{
					head=delete(head);
					break;
				}
			case 5:	break;
			default:
				{
					printf("Invalid choice!");
					break;
				}
		}
	}
	while(choice!=5);
	return 0;
}

struct node* create()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Create record\nEnter roll no.: ");
	scanf("%d", &temp->roll);
	printf("Enter name: ");
	scanf(" %[^\n]", temp->name);
	printf("Enter marks: ");
	scanf("%d", &temp->marks);
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

void fDisplay(struct node *s)
{
	printf("\n");
	while(s!=NULL)
	{
		printf("\nRoll no.: %d\nName: %s\nMarks: %d\n", s->roll, s->name, s->marks);
		s=s->next;
	}
}

void rDisplay(struct node *s)
{
	struct node *temp;
	temp=s;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=s)
	{
		printf("\nRoll no.: %d\nName: %s\nMarks: %d\n", temp->roll, temp->name, temp->marks);
		temp=temp->prev;
	}
	printf("\nRoll no.: %d\nName: %s\nMarks: %d\n", temp->roll, temp->name, temp->marks);
}

struct node* insert(struct node *s)
{
	struct node *temp, *stemp;
	stemp=s;
	int choice, r;
	printf("\n1. Start\n2. Middle\n3. End ");
	scanf("%d", &choice);
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter record\nEnter roll no.: ");
	scanf("%d", &temp->roll);
	printf("Enter name: ");
	scanf(" %[^\n]", temp->name);
	printf("Enter marks: ");
	scanf("%d", &temp->marks);
	switch(choice)
	{
		case 1:
			{
				temp->prev=NULL;
				temp->next=s;
				s->prev=temp;
				s=temp;
				return s;
				break;
			}
		case 2:
			{
				printf("Enter roll no. after which you want to add record: ");
				scanf("%d", &r);
				while(s->roll!=r)
				{
					s=s->next;
				}
				temp->next=s->next;
				s->next->prev=temp;
				temp->prev=s;
				s->next=temp;
				break;
			}
		case 3:
			{
				while(s->next!=NULL)
				{
					s=s->next;
				}
				temp->prev=s;
				temp->next=NULL;
				s->next=temp;
				break;
			}
	}
	return stemp;
}

void modify(struct node *s)
{
	int r, flag=0;
	printf("Enter roll no. to modify: ");
	scanf("%d", &r);
	while(s->roll!=r)
	{
		s=s->next;
	}
	if(s->roll==r)
	{
		flag=1;
		printf("Enter modified record\nEnter roll no.: ");
		scanf("%d", &s->roll);
		printf("Enter name: ");
		scanf(" %[^\n]", s->name);
		printf("Enter marks: ");
		scanf("%d", &s->marks);
	}
	else if(flag==0)
	{
		printf("\nRecord not found!");
	}
}

struct node * delete(struct node *s)
{
	struct node *stemp;
	stemp=s;
	int r, flag=0;
	printf("Enter roll no. to delete: ");
	scanf("%d", &r);
	while(s->roll!=r)
	{
		s=s->next;
	}
	if(s->roll==r)
	{
		flag=1;
		if(s->next==NULL)
		{
			s->prev->next=NULL;
		}
		else
		{
			s->prev->next=s->next;
			s->next->prev=s->prev;
			s->next=NULL;
			s->prev=NULL;
		}
	}
	else if(flag==0)
	{
		printf("\nRecord not found!");
	}
	return stemp;
}
