#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node * create();
void display(struct node *s);
void displayReverse(struct node *s);
struct node * insertStart(struct node *s);
void insertEnd(struct node *s);
void insertMiddle(struct node *s);
void modify(struct node *s);
void searchList(struct node *s);
void deleteEnd(struct node *s);
struct node * deleteStart(struct node *s);
void deleteMiddle(struct node *s);
struct node* reverseList(struct node *s);

int main()
{
	struct node *start;
	int choice;
	char repeat;
	start=create();
	do
	{
		printf("\n1. Display\n2. Insert\n3. Modify\n4. Search\n5. Delete\n6. Reverse\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					printf("\nDisplay list\n1. Forward\n2. Reverse\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								display(start);
								break;
							}
						case 2:
							{
								displayReverse(start);
								break;
							}
						default:
							{
								printf("\nInvalid selection!");
								break;
							}
					}
					break;
				}
			case 2:
				{
					printf("\nInsert node\n1. Start\n2. Middle\n3. End\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								start=insertStart(start);
								break;
							}
						case 2:
							{
								insertMiddle(start);
								break;
							}
						case 3:
							{
								insertEnd(start);
								break;
							}
						default:
							{
								printf("\nInvalid selection!");
								break;
							}
					}
					break;
				}
			case 3:
				{
					modify(start);
					break;
				}
			case 4:
				{
					searchList(start);
					break;
				}
			case 5:
				{
					printf("\nDelete node\n1. Start\n2. Middle\n3. End\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								start=deleteStart(start);
								break;
							}
						case 2:
							{
								deleteMiddle(start);
								break;
							}
						case 3:
							{
								deleteEnd(start);
								break;
							}
						default:
							{
								printf("\nInvalid selection!");
								break;
							}
					}
					break;
				}
			case 6:
				{
					start=reverseList(start);
					break;
				}
			default:
				{
					printf("\nInvalid selection!");
					break;
				}
		}
		printf("\nDo you want to perform another operation? ");
		scanf(" %c", &repeat);
	}
	while(repeat=='y' || repeat=='Y');
	return 0;
}

struct node * create()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &temp->data);
	temp->next=NULL;
	return temp;
}

void display(struct node *s)
{
	printf("\n");
	while(s!=NULL)
	{
		printf("%d\n", s->data);
		s=s->next;
	}
}

void displayReverse(struct node *s)
{
	if(s==NULL)
	{
		return;
	}
	displayReverse(s->next);
	printf("\n%d\t", s->data);
}

struct node * insertStart(struct node *s)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &temp->data);
	temp->next=s;
	s=temp;
	return s;
}

void insertEnd(struct node *s)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &temp->data);
	temp->next=NULL;
	while(s->next!=NULL)
	{
		s=s->next;
	}
	s->next=temp;
}

void insertMiddle(struct node *s)
{
	int search;
	printf("Enter element after which you want to insert the node: ");
	scanf("%d", &search);
	while(s->data!=search)
	{
		s=s->next;
	}
	if(s->data==search)
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data: ");
		scanf("%d", &temp->data);
		temp->next=s->next;
		s->next=temp;
	}
	else if(s->next==NULL)
		printf("\nElement not found!");
}

void modify(struct node *s)
{
	int search;
	printf("\nEnter element to modify: ");
	scanf("%d", &search);
	while(s->data!=search)
	{
		s=s->next;
	}
	if(s->data==search)
	{
		printf("\nEnter modified data: ");
		scanf("%d", &s->data);
	}
	else
		printf("\nElement not found!");
}

void searchList(struct node *s)
{
	int search, count=1;
	printf("\nEnter element to search: ");
	scanf("%d", &search);
	while(s->data!=search)
	{
		s=s->next;
		count++;
	}
	if(s->data==search)
	{
		printf("\n%d found in node %d", s->data, count);
	}
	else
	{
		printf("\nElement not found!");
	}
}

void deleteEnd(struct node *s)
{
	struct node *p, *q;
	p=s;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	printf("\nDeleted!");
	free(p);
}

struct node * deleteStart(struct node *s)
{
	struct node *p;
	p=s;
	s=p->next;
	printf("\nDeleted!");
	return s;
}

void deleteMiddle(struct node *s)
{
	struct node *p, *q;
	int del;
	printf("\nEnter element to delete: ");
	scanf("%d", &del);
	p=s;
	while(p->data!=del)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
	printf("\nDeleted!");
}

struct node* reverseList(struct node *s)
{
	struct node *current, *prev, *next;
	current=s;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	s=prev;
	return s;
}
