#include<stdio.h>

void swap(int *a, int *b);
int read(int array[]);
void write(int array[], int n);
void quicksortRecursion(int a[], int lower, int upper);
int partition(int a[], int lower, int upper);
void mergesortRecursion(int a[], int i, int j);
void merge(int a[], int l, int m, int u);

int main()
{
	int array[20];
	int size, i, choice, high, low=0;
	char repeat;
	
	size=read(array);
	high=size-1;
	
	do
	{
		printf("\n1. Quick sort\n2. Merge sort\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					quicksortRecursion(array, low, high);
					write(array, size);
					break;
				}
			case 2:
				{
					mergesortRecursion(array, low, high);
					write(array, size);
					break;
				}
			default:
				{
					printf("\nInvalid input!");
					break;
				}
		}
		printf("\nDo you want to perform another operation? (y/n)");
		scanf(" %c", &repeat);
	}
	while(repeat=='y' || repeat=='Y');
	
	return 0;
}

void quicksortRecursion(int a[], int lower, int upper)
{
	int pivot;
	if(lower<upper)
	{
		pivot=partition(a, lower, upper);
		quicksortRecursion(a, lower, pivot-1);
		quicksortRecursion(a, pivot+1, upper);
	}
}

int partition(int a[], int lower, int upper)
{
	int v, i, j, temp;
	v=a[lower];
	i=lower;
	j=upper+1;
	
	do
	{
		do
		{
			i++;
		}
		while(a[i]<v && i<=upper);
		do
		{
			j--;
		}
		while(v<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	while(i<j);
	a[lower]=a[j];
	a[j]=v;
	printf("\nPass: ");
	write(a, upper+1);
	return j;
}

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int read(int array[])
{
	int n, i;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	printf("\nEnter elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &array[i]);
	}
	
	return n;
}

void write(int array[], int n)
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void mergesortRecursion(int a[], int i, int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesortRecursion(a, i, mid);
		mergesortRecursion(a, mid+1, j);
		merge(a, i, mid, j);
	}
}

void merge(int a[], int l, int m, int u)
{
	int c[20];
	int i, j, k;
	i=1;
	j=m+1;
	k=0;
	while(i<=m && j<=u)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=m)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<=u)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	for(i=1, j=0; i<=u; i++, j++)
		a[i]=c[j];
	printf("\nPass: ");
	write(a, j+1);
}
