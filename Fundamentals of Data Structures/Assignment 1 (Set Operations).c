#include<stdio.h>

void readArray(int array[], int size);
void writeArray(int array[], int size);
int unionArray(int a[], int sizeA, int b[], int sizeB, int c[]);
int intersectionArray(int a[], int sizeA, int b[], int sizeB, int c[]);
int differenceArray(int a[], int sizeA, int b[], int sizeB, int c[]);
int symmetricdifferenceArray(int a[], int sizeA, int b[], int sizeB, int x[], int y[], int c[]);

int main()
{
	int setA[20], setB[20], setC[20], setX[20], setY[20];
	int sizeA, sizeB, choice, limit, limit2;
	char repeat='y';
	
	printf("Enter size of A: ");
	scanf("%d", &sizeA);
	printf("Enter elements of A: \n");
	readArray(setA, sizeA);
	
	printf("\nEnter size of B: ");
	scanf("%d", &sizeB);
	printf("Enter elements of B: \n");
	readArray(setB, sizeB);
	
	while(repeat=='y' || repeat=='Y')
	{
		printf("\nEnter the operation you want to perform\n1. Union\n2. Intersection\n3. Difference\n4. Symmetric Difference\n");
		scanf("%d", &choice);
		printf("\n");
		
		switch(choice)
		{
			case 1:
				{
					limit = unionArray(setA, sizeA, setB, sizeB, setC);
					printf("Union of two sets is: \n");
					writeArray(setC, limit);
					break;
				}
			case 2:
				{
					limit = intersectionArray(setA, sizeA, setB, sizeB, setC);
					printf("Intersection of two sets is: \n");
					writeArray(setC, limit);
					break;
				}
			case 3:
				{
					limit = differenceArray(setA, sizeA, setB, sizeB, setC);
					limit2 = differenceArray(setB, sizeB, setA, sizeA, setX);
					printf("Difference of two sets is: \nA-B = ");
					writeArray(setC, limit);
					printf("\nB-A = ");
					writeArray(setX, limit2);
					break;
				}
			case 4:
				{
					limit = symmetricdifferenceArray(setA, sizeA, setB, sizeB, setX, setY, setC);
					printf("Symmetric difference of two sets is: \n");
					writeArray(setC, limit);
					break;
				}
			default:
				{
					printf("Incorrect selection! Enter a number between 1-4\n");
					break;
				}
		}
		printf("Do you want to perform any operation again? (y/n)\n");
		scanf(" %c", &repeat);
	}
	
	return 0;
}

void readArray(int array[], int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		scanf("%d", &array[i]);
		j=0;
		for(j=0; j<i; j++)
		{
			if(i==0)
			{
				break;
			}
			else
			{
				if(array[i] == array[j])
				{
					printf("Repeated number! Enter another one\n");
					i--;
				}
			}
		}
	}
}

void writeArray(int array[], int size)
{
	int i;
	printf("{");
	for(i=0; i<size; i++)
	{
		if(i==(size-1))
		{
			printf("%d}\n", array[i]);
		}
		else
		{
			printf("%d, ", array[i]);
		}
	}
}

int unionArray(int a[], int sizeA, int b[], int sizeB, int c[])
{
	int i, j, k=0, flag;
	for(i=0; i<sizeA; i++)
	{
		c[k]=a[i];
		k++;
	}
	for(i=0; i<sizeB; i++)
	{
		flag=0;
		for(j=0; j<sizeA; j++)
		{
			if(b[i]==c[j])
			{
				flag++;
			}
		}
		if(flag==0)
		{
			c[k]=b[i];
			k++;
		}
	}
	return k;
}

int intersectionArray(int a[], int sizeA, int b[], int sizeB, int c[])
{
	int i, j, k=0;
	for(i=0; i<sizeA; i++)
	{
		for(j=0; j<sizeB; j++)
		{
			if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
			}
		}
	}
	return k;
}

int differenceArray(int a[], int sizeA, int b[], int sizeB, int c[])
{
	int i, j, k=0, flag;
	for(i=0; i<sizeA; i++)
	{
		flag=1;
		for(j=0; j<sizeB; j++)
		{
			if(a[i]==b[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			c[k]=a[i];
			k++;
		}
	}
	return k;
}

int symmetricdifferenceArray(int a[], int sizeA, int b[], int sizeB, int x[], int y[], int c[])
{
	int sizeX, sizeY, k;
	sizeX = differenceArray(a, sizeA, b, sizeB, x);
	sizeY = differenceArray(b, sizeB, a, sizeA, y);
	k = unionArray(x, sizeX, y, sizeY, c);
	return k;
}
