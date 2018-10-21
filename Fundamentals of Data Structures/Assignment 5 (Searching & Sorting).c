#include <stdio.h>
#include <string.h>

void bubbleSort(char array[][20], int rows);
void selectionSort(char array[][20], int size);
void insertionSort(char array[][20], int size);
int binarySearch(char array[][20], char key[20], int lower, int upper, int flag);
int binarySearchWithRecursion(char array[][20], char key[20], int lower, int upper, int flag);

int main()
{
	char strings[10][20], key[20];
	int rows, i, choice, flag, sortFlag, lower, upper;
	
	printf("Enter no. of strings: ");
	scanf("%d", &rows);
	
	printf("\nEnter strings: \n");
	for(i=0; i<rows; i++)
	{
		scanf("%s", strings[i]);
	}
	
	printf("\nSORT\n1. Ascending order using Bubble Sort\n2. Descending order using Selection Sort\n3. Descending order using Insertion Sort\nEnter your selection: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			{
				sortFlag=1;
				bubbleSort(strings, rows);
				break;
			}
		case 2:
			{
				sortFlag=0;
				selectionSort(strings, rows);
				break;
			}
		case 3:
			{
				sortFlag=0;
				insertionSort(strings, rows);
				break;
			}
		default:
			{
				printf("Incorrect selection! Enter a number between 1-3\n");
				break;
			}
	}
	
	lower=0;
	upper=rows-1;
	
	printf("\nSEARCH\n1. Binary search\n2. Binary search with recursion\nEnter your selection: ");
	scanf("%d", &choice);
	
	printf("\nEnter string to search: ");
	scanf("%s", key);
	
	switch(choice)
	{
		case 1:
			{
				flag=binarySearch(strings, key, lower, upper, sortFlag);
				if(flag==-1)
				{
					printf("String not found!\n");
				}
				else
				{
					printf("%s found at position %d in the array!\n", strings[flag], flag+1);
				}
				break;
			}
		case 2:
			{
				flag=binarySearchWithRecursion(strings, key, lower, upper, sortFlag);
				if(flag==-1)
				{
					printf("String not found!\n");
				}
				else
				{
					printf("%s found at position %d in the array!\n", strings[flag], flag+1);
				}
				break;
			}
		default:
			{
				printf("Incorrect selection! Enter 1 or 2\n");
				break;
			}
	}
	
	return 0;
}

void bubbleSort(char array[][20], int rows)
{
	int i, j, k, swap=1;
	char temp[20];
	
	for(i=0; i<rows && swap==1; i++)
	{
		swap=0;
		for(j=0; j<(rows-1-i); j++)
		{
			if(strcmp(array[j], array[j+1])>0)
			{
				strcpy(temp, array[j]);
				strcpy(array[j], array[j+1]);
				strcpy(array[j+1], temp);
				swap=1;
			}
		}
		
		printf("\nIteration %d\n", i+1);
		for(k=0; k<rows; k++)
		{
			printf("%s\t", array[k]);
		}
		printf("\n");
	}
}

void selectionSort(char array[][20], int size)
{
	int i, j, k, count;
	char temp[20];
	
	for(i=0; i<size; i++)
	{
		j=i;
		for(k=j+1; k<size; k++)
		{
			if(strcmp(array[j], array[k])<0)
			{
				j=k;
			}
		}
		strcpy(temp, array[i]);
		strcpy(array[i], array[j]);
		strcpy(array[j], temp);
		
		printf("\nIteration %d\n", i+1);
		for(count=0; count<size; count++)
		{
			printf("%s\t", array[count]);
		}
		printf("\n");
	}
}

int binarySearch(char array[][20], char key[20], int lower, int upper, int flag)
{
	while(lower<=upper)
	{
		int mid;
		mid=(lower+upper)/2;
		if(strcmp(array[mid], key)==0)
		{
			return mid;
		}
		if(flag==1)
		{
			if(strcmp(key, array[mid])<0)
			{
				upper=mid-1;
			}
			else
			{
				lower=mid+1;
			}
		}
		else
		{
			if(strcmp(key, array[mid])<0)
			{
				lower=mid+1;
			}
			else
			{
				upper=mid-1;
			}
		}
	}
	
	return -1;
}

int binarySearchWithRecursion(char array[][20], char key[20], int lower, int upper, int flag)
{
	int mid;	
	mid=(lower+upper)/2;
	
	if(lower>upper)
	{
		return -1;
	}
	else if(strcmp(array[mid], key)==0)
	{
		return mid;
	}
	if(flag==1)
	{
		if(strcmp(key, array[mid])<0)
		{
			upper=mid-1;
			binarySearchWithRecursion(array, key, lower, upper, flag);
		}
		else
		{
			lower=mid+1;
			binarySearchWithRecursion(array, key, lower, upper, flag);
		}
	}
	else
	{
		if(strcmp(key, array[mid])<0)
		{
			lower=mid+1;
			binarySearchWithRecursion(array, key, lower, upper, flag);
		}
		else
		{
			upper=mid-1;
			binarySearchWithRecursion(array, key, lower, upper, flag);
		}
	}
}

void insertionSort(char array[][20], int size)
{
	int i, j, k, count=0;
	char temp[20];
	for(i=size-2; i>=0; i--)
  	{
  		strcpy(temp, array[i]);
  		j=i+1;
  		while(strcmp(temp, array[j])<0 && j<=size-1)
  		{
	    	strcpy(array[j-1], array[j]);
	    	j++;
    	}
  
  		strcpy(array[j-1], temp);
  		
  		printf("\nIteration %d\n", count+1);
  		count++;
		for(k=0; k<size; k++)
		{
			printf("%s\t", array[k]);
		}
		printf("\n");
  	}
}
