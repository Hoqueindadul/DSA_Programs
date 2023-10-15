#include<stdio.h>

void input(int ar[][100], int row, int col);
void sparc(int arr[][100], int row, int col);

int main()
{
    int arr[100][100], row, col;
    printf("Enter how many row and coloumn you want: ");
    scanf("%d %d", &row, &col);
    input(arr, row, col);

    sparc(arr, row, col);
}

void input(int arr[][100], int row, int col)
{
    int i, j;
    printf("Enter your array elements: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("After display of an array\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void sparc(int arr[][100], int row, int col)
{
    int i, j, k, nonzero = 0;
    k = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(arr[i][j] != 0)
            {
                nonzero++;
            }  
        }
    }
    int output[3][nonzero];
    for(i= 0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            
            if(arr[i][j] != 0)
            {
                output[0][k] = i;
                output[1][k] = j;
                output[2][k] = arr[i][j];
                k++;
            }
        }
    }
    printf("The sparce matrix is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<nonzero;j++)
        {
            printf("%d", output[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}