#include<stdio.h>

//functions
void getMatrix(int a[5][5], int x, int y);
void putMatrix(int a[5][5], int x, int y);
void addMatrix(int a[5][5], int b[5][5], int x, int y, int c[5][5]);
void subtractMatrix(int a[5][5], int b[5][5], int x, int y, int c[5][5]);
void multiplyMatrix(int a[5][5], int b[5][5], int x, int y, int c[5][5]);
void transposeMatrix(int a[5][5], int x, int y, int c[5][5]);

int main()
{
    int x, y; //x=rows & y=columns of the matrix
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &x, &y);
    
    int a[5][5], b[5][5], c[5][5]; //creates matrices
    
    //gets both matrices
    printf("\nEnter first matrix: \n");
    getMatrix(a, x, y);
    printf("Enter second matrix: \n");
    getMatrix(b, x, y);
    
    //gets desired operation
    char again='y';
    while(again == 'y' || again == 'Y')
    {
        restart:
        printf("Enter the operation you want to perform:\n1. Add\n2. Subtract\n3. Multiply\n4. Transpose\n5. Saddle Point\n");
        int choice;
        scanf("%d", &choice);
        if(choice < 1 || choice > 5)
        {
            goto restart;
        }
        
        //performs desired operation
        switch (choice)
        {
            case 1:
                {
                    addMatrix(a, b, x, y, c);
                    printf("\nThe addition of the two matrices is: ");
                    putMatrix(c, x, y);
                    break;
                }
            case 2:
                {
                    subtractMatrix(a, b, x, y, c);
                    printf("\nThe subtraction of the two matrices is: ");
                    putMatrix(c, x, y);
                    break;
                }
            case 3:
                {
                    multiplyMatrix(a, b, x, y, c);
                    printf("\nThe multiplication of the two matrices is: ");
                    putMatrix(c, x, y);
                    break;
                }
            case 4:
                {
                    transposeMatrix(a, x, y, c);
                    printf("\nThe transpose of the matrix is: ");
                    putMatrix(c, x, y);
                    break;
                }
        //    case 5:
        //        {
        //            saddle point
        //        }
        //    default :
        //        {
        //            
        //        }
        }
        printf("Do you want to perform the operations again? (y/n): ");
        scanf(" %c", &again);
    }
    return 0;
}

void getMatrix(int a[5][5], int x, int y) //scans matrix
{
    int i, j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("Enter element [%d][%d]: ", (i+1), (j+1));
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
}

void putMatrix(int a[5][5], int x, int y) //prints matrix
{
    int i, j;
    printf("\n");
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[5][5], int b[5][5], int x, int y, int c[5][5]) //adds matrices
{
    int i, j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrix(int a[5][5], int b[5][5], int x, int y, int c[5][5])
{
    int i, j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrix(int a[5][5], int b[5][5], int x, int y, int c[5][5])
{
    
}

void transposeMatrix(int a[5][5], int x, int y, int c[5][5])
{
    
}
