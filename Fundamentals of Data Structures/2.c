#include<stdio.h>

int main()
{
    int x, y;
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &x, &y);
    int a[x][y], b[x][y], c[x][y];
    int i, j;
    for(i=0; i<x; i++) //gets matrix A
    {
        for(j=0; j<y; j++)
        {
            printf("Enter element A[%d][%d]: ", (i+1), (j+1));
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0; i<x; i++) //gets matrix B
    {
        for(j=0; j<y; j++)
        {
            printf("Enter element B[%d][%d]: ", (i+1), (j+1));
            scanf("%d", &b[i][j]);
        }
    }
    for(i=0; i<x; i++) //adds matrices
    {
        for(j=0; j<y; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for(i=0; i<x; i++) //prints matrix C
    {
        for(j=0; j<y; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
