#include<stdio.h>

void readMatrix(int a[][10], int rowSize, int colSize);
void writeMatrix(int a[][10], int rowSize, int colSize);
void addMatrix(int a[][10], int rowA, int colA, int b[][10], int c[][10]);
void multiplyMatrix(int a[][10], int rowA, int colA, int b[][10], int rowB, int colB, int c[][10]);
void transposeMatrix(int a[][10], int rowA, int colA, int c[][10]);
void saddlepointMatrix(int a[][10], int rowA, int colA);

int main()
{
	int matrixA[10][10], matrixB[10][10], matrixC[10][10];
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
	
	readMatrix(matrixA, rowA, colA);
	
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
						addMatrix(matrixA, rowA, colA, matrixB, matrixC);
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
                    printf("Matrix A:\n");
					saddlepointMatrix(matrixA, rowA, colA);
                    printf("\nMatrix B:\n");
                    saddlepointMatrix(matrixB, rowB, colB);
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

void addMatrix(int a[][10], int rowA, int colA, int b[][10], int c[][10])
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
	int small[10][10], large[10][10];
    int i, j, rowIndex, colIndex, largest, smallest, flag=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            small[i][j]=0;
            large[i][j]=0;
        }
    }
    for(i=0; i<rowA; i++)
    {
        smallest=a[i][0];
        for(j=0; j<colA; j++)
        {
            if(a[i][j]<smallest)
            {
                smallest=a[i][j];
                colIndex=j;
            }
            else if(a[i][j]==smallest)
            {
                rowIndex=i;
                colIndex=j;
                small[rowIndex][colIndex]=smallest;
            }
        }
        rowIndex=i;
        small[rowIndex][colIndex]=smallest;
    }
    for(j=0; j<colA; j++)
    {
        largest=a[0][j];
        for(i=0; i<rowA; i++)
        {
            if(a[i][j]>largest)
            {
                largest=a[i][j];
                rowIndex=i;
            }
        }
        colIndex=j;
        large[rowIndex][colIndex]=largest;
    }
    for(i=0; i<rowA; i++)
    {
        for(j=0; j<colA; j++)
        {
            if((small[i][j]==large[i][j]) && (small[i][j]!=0))
            {
                printf("Saddle point is %d in row %d and column %d\n", small[i][j], (i+1), (j+1));
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        printf("There is no saddle point in the matrix\n");
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
