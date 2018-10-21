#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
	int coeff, power;
	struct node *next;
}node;

node* insert(node *head, int power1, int coeff1);
node* create();
node* add(node *p1, node *p2);
node* multiply(node *p1, node *p2);
float eval(node *head, float x);
void print(node *head);

int main()
{
	node *p1, *p2, *p3;
	int choice;
	float x, value;
	char repeat;
	
	do
	{
		printf("\n1. Enter polynomials\n2. Display polynomials\n3. Add\n4. Multiply\n5. Evaluate\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					printf("Enter first polynomial");
					p1=create();
					printf("Enter second polynomial");
					p2=create();
					break;
				}
			case 2:
				{
					printf("First polynomial");
					print(p1);
					printf("\nSecond polynomial");
					print(p2);
					break;
				}
			case 3:
				{
					p3=add(p1, p2);
					printf("Addition: ");
					print(p3);
					break;
				}
			case 4:
				{
					p3=multiply(p1, p2);
					printf("Multiplication: ");
					print(p3);
					break;
				}
			case 5:
				{
					printf("Enter value of x: ");
					scanf("%f", &x);
					value=eval(p1, x);
					printf("Evaluated value of first polynomial = %6.2f", value);
					value=eval(p2, x);
					printf("Evaluated value of second polynomial = %6.2f", value);
					break;
				}
			default:
				{
					printf("Invalid input!");
					break;
				}
		}
		
		printf("\nDo you want to perform another operation? (y/n)");
		scanf(" %c", &repeat);
	}
	while(repeat=='y'||repeat=='Y');
	
	return 0;
}

node* insert(node *head, int power1, int coeff1)
{
	node *p, *q;
	p=(node *)malloc(sizeof(node));
	p->power=power1;
	p->coeff=coeff1;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		head->next=head;
		return head;
	}
	if(power1>head->power)
	{
		p->next=head->next;
		head->next=p;
		head=p;
		return head;
	}
	if(power1==head->power)
	{
		head->coeff=head->coeff+coeff1;
		return head;
	}
	q=head;
	while(q->next!=head && power1>=q->next->power)
	{
		q=q->next;
	}
	if(p->power==q->power)
	{
		q->coeff=q->coeff+coeff1;
	}
	else
	{
		p->next=q->next;
		q->next=p;
	}
	return head;
}

node* create()
{
	int n, i, power1, coeff1;
	node *head=NULL;
	printf("\nEnter no of terms: ");
	scanf("%d", &n);
	printf("\nEnter term: ");
	for(i=1; i<=n; i++)
	{
		scanf("%d %d", &coeff1, &power1);
		head=insert(head, power1, coeff1);
	}
	return head;
}

node* add(node *p1, node *p2)
{
	node *p, *head;
	head=NULL;
	int power, coeff;
	p=p1->next;
	do
	{
		head=insert(head, p->power, p->coeff);
		p=p->next;
	}
	while(p!=p1->next);
	p=p2->next;
	do
	{
		head=insert(head, p->power, p->coeff);
		p=p->next;
	}
	while(p!=p2->next);
	return head;
}

node* multiply(node *head1, node *head2)
{
	node *cur1, *cur2, *head3;
    cur1 = head1->next;
    while(cur1 != head1)
    {
    	cur2 = head2->next;
    	while(cur2!=head2)
    	{
        	head3 =insert(head3, cur1->power+cur2->power, cur1->coeff*cur2->coeff);
        	cur2=cur2->next;
    	}
    	cur1=cur1->next;
    }
    return head3;
}

float eval(node *head, float x)
{
	float value=0.0;
	node *p;
	p=head->next;
	do
	{
		value=value+p->coeff*pow(x, p->power);
		p=p->next;
	}
	while(p!=head->next);
	return value;
}

void print(node *head)
{
	node *p;
	p=head->next;
	printf("\n");
	do
	{
		printf("%dx^%d ", p->coeff, p->power);
		p=p->next;
	}
	while(p!=head->next);
}
