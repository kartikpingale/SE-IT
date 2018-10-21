#include<stdio.h>

struct spar{
	int row,col,val;
};

int read(int a[20][20],struct spar x[20],int n1,int n2);
void display(struct spar x[20],int n);
void ddisplay(int a[20][20],int n1,int n2);	
void strans(struct spar x[20],struct spar y[20]);
void add(struct spar x[20],struct spar y[20],struct spar c[20]);
void ftrans(struct spar x[20],struct spar y[20]);

int main()
{
	int a[20][20],i,j,n1,n2,n,ch=0,n3,m1,m2;
	struct spar x[20],st[20],y[20],c[20];
	while(ch!=6)
	{
		printf("1. Create\n2. Display\n3. Add\n4. Simple Transpose\n5. Fast Transpose");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter The Number of Rows and Columns\n");
				scanf("%d %d",&n1,&n2);
				n=read(a,x,n1,n2);
				x[0].row=n1;
				x[0].col=n2;
			break;
			case 2:
				ddisplay(a,n1,n2);
				display(x,n);				
			break;
			case 3:
				printf("Enter The Number of Rows and Columns\n");
				scanf("%d %d",&n1,&n2);
				n=read(a,x,n1,n2);
				x[0].row=n1;
				x[0].col=n2;
				printf("Enter The Number of Rows and Columns\n");
				scanf("%d %d",&m1,&m2);
				n3=read(a,y,m1,m2);
				y[0].row=m1;
				y[0].col=m2;
				add(x,y,c);
			break;
			case 4:
				strans(x,st);
				display(st,n);
			break;
			case 5:
				ftrans(x,st);
				display(st,n);
			break;
			default:
				printf("\nInvalid input!");
			break;
		}
	}
}



int read(int a[20][20],struct spar x[20],int n1,int n2)
{
	printf("Enter The Matrix\n");
	int k=1;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
			{
				x[k].row=i;
				x[k].col=j;
				x[k].val=a[i][j];
				k++;
			}
		}
	}
	x[0].val=k-1;
	return k;
}

void display(struct spar x[20],int n)
{
	printf("No\tRow\tCol\tValue\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",i,x[i].row,x[i].col,x[i].val);
	}
}

void strans(struct spar x[20],struct spar y[20])
{
	y[0].row=x[0].col;
	y[0].col=x[0].row;
	y[0].val=x[0].val;
	int k=0;
	for(int i=0;i<x[0].col;i++)
	{
		for(int j=1;j<=x[0].val;j++)
		{
			if(x[j].col==i)
			{
				k++;
				y[k].row=x[j].col;
				y[k].col=x[j].row;
				y[k].val=x[j].val;
			}
		}
	}
}

void ddisplay(int a[20][20],int n1,int n2)
{
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void add(struct spar x[20],struct spar y[20],struct spar c[20])
{
	int i=1,j=1,k=0;
	c[0].row=x[0].row;
	c[0].col=x[0].col;
	
	while((i!=x[0].val+1)&&(j!=y[0].val+1))
	{
		if((x[i].row==y[j].row)&&(x[i].col==y[j].col))
		{
			k++;
			c[k].row=x[i].row;
			c[k].col=x[i].col;
			c[k].val=x[i].val+y[j].val;
			i++;
			j++;
		}else if(x[i].row<y[j].row)
		{
			k++;
			c[k].row=x[i].row;
			c[k].col=x[i].col;
			c[k].val=x[i].val;
			i++;
		}else if(x[i].row>y[j].row)
		{
			k++;
			c[k].row=y[j].row;
			c[k].col=y[j].col;
			c[k].val=y[j].val;
			j++;
		}else 
		{
			if(x[i].col<y[j].col)
			{
				k++;
				c[k].row=x[i].row;
				c[k].col=x[i].col;
				c[k].val=x[i].val;
				i++;
			}else
			{
				k++;
				c[k].row=y[j].row;
				c[k].col=y[j].col;
				c[k].val=y[j].val;
				j++;
			}
		}
	}
	c[0].val=k;
	display(c,k+1);
}


void ftrans(struct spar x[20],struct spar y[20])
{
	int a[20],k,b[20],t,j=0;
	for(int i=0;i<20;i++)
	{
		a[i]=0;
	}
	for(int i=1;i<=x[0].val;i++)
	{
		k=x[i].col;
		a[k]=a[k]+1;
	}
	b[0]=1;
	for(int i=1;i<x[0].col;i++)
	{
		b[i]=a[j]+1;
		a[j+1]=a[j]+a[j+1];
				j++;
	}
	for(int i=0;i<x[0].col;i++)
	{
		printf("%d\n",b[i]);
	}
	y[0].col=x[0].row;
	y[0].row=x[0].col;
	y[0].val=x[0].val;
	for(int i=1;i<=x[0].val;i++)
	{
		k=x[i].col;
		printf("%d\t",k);
		t=b[k];
		printf("%d\t",t);
		y[t].col=x[i].row;
		y[t].row=x[i].col;
		y[t].val=x[i].val;
		b[k]=b[k]+1;
		printf("%d\t",b[k]);
		printf("\n");
	}
}
