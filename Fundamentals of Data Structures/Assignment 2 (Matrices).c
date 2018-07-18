#include<stdio.h>

void readMatrix(int a[][10], int rowSize, int colSize);
void writeMatrix(int a[][10], int rowSize, int colSize);
void addMatrix(int a[][10], int rowA, int colA, int b[][10], int rowB, int colB, int c[][10]);
void multiplyMatrix(int a[][10], int rowA, int colA, int b[][10], int rowB, int colB, int c[][10]);
void transposeMatrix(int a[][10], int rowA, int colA, int c[][10]);

int main()
{
	int matrixA[10][10], matrixB[10][10], matrixC[10][10];
	int rowA, colA, rowB, colB, choice;
	char repeat='y';
	
	printf("Enter no. of rows for matrix A: ");
	scanf("%d", &rowA);
	printf("Enter no. of columns for matrix A: ");
	scanf("%d", &colA);
	
	readMatrix(matrixA, rowA, colA);
	
	printf("Enter no. of rows for matrix B: ");
	scanf("%d", &rowB);
	printf("Enter no. of columns for matrix B: ");
	scanf("%d", &colB);
	
	readMatrix(matrixB, rowB, colB);
	
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
						addMatrix(matrixA, rowA, colA, matrixB, rowB, colB, matrixC);
						writeMatrix(matrixC, rowA, colA);
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
						multiplyMatrix(matrixA, rowA, colA, matrixB, rowB, colB, matrixC);
						writeMatrix(matrixC, rowA, colB);
					}
					break;
				}
			case 3:
				{
					transposeMatrix(matrixA, rowA, colA, matrixC);
					printf("Transpose of matrix A:\n");
					writeMatrix(matrixC, colA, rowA);
					transposeMatrix(matrixB, rowB, colB, matrixC);
					printf("\nTranspose of matrix B:\n");
					writeMatrix(matrixC, colB, rowB);
					break;
				}
			case 4:
				{
					
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

void readMatrix(int a[][10], int rowSize, int colSize)
{
	int i, j;
	for(i=0; i<rowSize; i++)
	{
		for(j=0; j<colSize; j++)
		{
			printf("Enter element [%d][%d]: ", (i+1), (j+1));
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
}

void writeMatrix(int a[][10], int rowSize, int colSize)
{
	int i, j;
	printf("\n");
	for(i=0; i<rowSize; i++)
	{
		for(j=0; j<colSize; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void addMatrix(int a[][10], int rowA, int colA, int b[][10], int rowB, int colB, int c[][10])
{
	int i, j;
	for(i=0; i<rowA; i++)
	{
		for(j=0; j<colA; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void multiplyMatrix(int a[][10], int rowA, int colA, int b[][10], int rowB, int colB, int c[][10])
{
	int i, j, k, sum=0;
	for(i=0; i<rowA; i++)
	{
		for(j=0; j<colB; j++)
		{
			for(k=0; k<rowB; k++)
			{
				sum += a[i][k]*b[k][j];
			}
			c[i][j]=sum;
			sum=0;
		}
	}
}

void saddlepointMatrix(int a[][10], int rowA, int colA)
{
	int i, j, smallest, largest;
	int saddle[10][10];
	for()
	{
		
	}
}

void transposeMatrix(int a[][10], int rowA, int colA, int c[][10])
{
	int i, j;
	for(i=0; i<rowA; i++)
	{
		for(j=0; j<colA; j++)
		{
			c[j][i] = a[i][j];
		}
	}
}
