#include<stdio.h>
#include<stdlib.h>

void readMatrix(int *a, int *rowSize, int *colSize);
void writeMatrix(int *a, int *rowSize, int *colSize);
void addMatrix(int *a, int *rowA, int *colA, int *b, int *c);
void multiplyMatrix(int *a, int *rowA, int *colA, int *b, int *rowB, int *colB, int *c);
void transposeMatrix(int *a, int *rowA, int *colA, int *c);
void saddlepointMatrix(int a[][10], int *rowA, int *colA);

int main()
{
	int *matrixA, *matrixB, *matrixC;
	int rowA=1, colA=1, rowB=1, colB=1, choice;
	char repeat='y';
	
	do
    {
        if(rowA<=0 || colA<=0)
        {
            printf("Invalid input! Enter the data again\n\n");
        }
        printf("Enter no. of rows for matrix A: ");
        scanf("%d", &rowA);
        printf("Enter no. of columns for matrix A: ");
        scanf("%d", &colA);
    }
	while(rowA<=0 || colA<=0);
	
	matrixA=(int *) malloc(sizeof(int)*rowA*colA);
	
	readMatrix(matrixA, &rowA, &colA);
	
    do
    {
        if(rowB<=0 || colB<=0)
        {
            printf("Invalid input! Enter the data again\n\n");
        }
        printf("Enter no. of rows for matrix B: ");
        scanf("%d", &rowB);
        printf("Enter no. of columns for matrix B: ");
        scanf("%d", &colB);
    }
    while(rowB<=0 || colB<=0);
    
    matrixB=(int *) malloc(sizeof(int)*rowB*colB);
    
	readMatrix(matrixB, &rowB, &colB);

	while(repeat=='y' || repeat=='Y')
	{
		printf("Enter the operation you want to perform\n1. Add\n2. Multiply\n3. Transpose\n4. Saddle Point\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					if(rowA==rowB && colA==colB)
					{
						addMatrix(matrixA, &rowA, &colA, matrixB, matrixC);
						writeMatrix(matrixC, &rowA, &colA);
					}
					else
					{
						printf("\nCannot add the matrices!\n");
					}
					break;
				}
			case 2:
				{
					if(colA!=rowB)
					{
						printf("\nCannot multiply the matrices!\n");
					}
					else
					{
						multiplyMatrix(matrixA, &rowA, &colA, matrixB, &rowB, &colB, matrixC);
						writeMatrix(matrixC, &rowA, &colB);
					}
					break;
				}
			case 3:
				{
					transposeMatrix(matrixA, &rowA, &colA, matrixC);
					printf("Transpose of matrix A:\n");
					writeMatrix(matrixC, &colA, &rowA);
					transposeMatrix(matrixB, &rowB, &colB, matrixC);
					printf("\nTranspose of matrix B:\n");
					writeMatrix(matrixC, &colB, &rowB);
					break;
				}
			/*case 4:
				{
					
					break;
				}
			default:
				{
					printf("Incorrect selection! Enter a number between 1-4\n");
					break;
				}*/
		}
		printf("Do you want to perform any operation again? (y/n)\n");
		scanf(" %c", &repeat);
	}
	
	return 0;
}

void readMatrix(int *a, int *rowSize, int *colSize)
{
	int i, j;
	for(i=0; i<(*rowSize); i++)
	{
		for(j=0; j<(*colSize); j++)
		{
			printf("Enter element [%d][%d]: ", (i+1), (j+1));
			scanf("%d", (a + i*(*colSize) + j));
		}
	}
	printf("\n");
}

void writeMatrix(int *a, int *rowSize, int *colSize)
{
	int i, j;
	printf("\n");
	for(i=0; i<(*rowSize); i++)
	{
		for(j=0; j<(*colSize); j++)
		{
			printf("%d\t", *(a + i*(*colSize) + j));
		}
		printf("\n");
	}
}

void addMatrix(int *a, int *rowA, int *colA, int *b, int *c)
{
	int i, j;
	for(i=0; i<(*rowA); i++)
	{
		for(j=0; j<(*colA); j++)
		{
			*(c + i*(*colA) + j) = *(a + i*(*colA) + j) + *(b + i*(*colA) + j);
		}
	}
}

void multiplyMatrix(int *a, int *rowA, int *colA, int *b, int *rowB, int *colB, int *c)
{
	int i, j, k, sum=0;
	for(i=0; i<(*rowA); i++)
	{
		for(j=0; j<(*colB); j++)
		{
			for(k=0; k<(*rowB); k++)
			{
				sum += *(a + i*(*rowB) + k) * *(b + k*(*rowB) + j);
			}
			*(c + i*(*colB) + j)=sum;
			sum=0;
		}
	}
}

void transposeMatrix(int *a, int *rowA, int *colA, int *c)
{
	int i, j;
	for(i=0; i<(*rowA); i++)
	{
		for(j=0; j<(*colA); j++)
		{
			*(c + j*(*colA) + i) = *(a + i*(*colA) + j);
		}
	}
}
