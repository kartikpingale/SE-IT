#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int flag;
	union
	{
		char str[200];
		struct Node *dlink;
	}u;
	struct Node *next;
};

struct Node* getNode();
struct Node* createGLL(struct Node* head, char str[]);
void display(struct Node *temp);

int main()
{
	struct Node *head;
	char str[200];
	printf("Enter String : ");
	gets(str);
	head = createGLL(head,str);
	display(head);
	return 0;
}

struct Node* getNode()
{
	struct Node *node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->u.dlink = 0;
	node->next = NULL;
	return node;
}

struct Node* createGLL(struct Node* head, char str[])
{
	int i,j,open,close;
	struct Node *temp;
	open=0;
	close=0;
	for(i=0;str[i]!='\0';)
	{
		if(str[i]=='{' && i==0)
		{
			head = getNode();
			temp = head;
		}
		else{
			temp->next = getNode();
			temp = temp->next;
		}
		i++;
		j=0;
		while(str[i]!=',' && str[i]!='{' && str[i]!='}')
		{
			temp->u.str[j]=str[i];
			i++;
			j++;
		}
		temp->u.str[j]='\0';
		temp->flag = 0;
		if(str[i]=='{')
		{
			open++;
			temp->next = getNode();
			temp = temp->next;
			temp->flag = 1;
			temp->u.dlink = createGLL(temp->u.dlink,&str[i]);
			while(open!=close){
				i++;
				if(str[i]=='{')
					open++;
				else if(str[i]=='}')
					close++;
			}
			i++;
		}
		if(str[i]=='}')
			return head;
	}
}

void display(struct Node *temp)
{
	static int depth;
	depth++;
	int i;
	if(temp==NULL)
	{
		if(depth==1)
			printf("List is empty!");
		else
			printf("Sublist is empty!");
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->flag==0)
			{
				printf("\n");
				for(i=1;i<depth;i++)
					printf("  ");
				printf("%s",temp->u.str);
			}
			else
				display(temp->u.dlink);
			temp = temp->next;
		}
	}
	depth--;
}
