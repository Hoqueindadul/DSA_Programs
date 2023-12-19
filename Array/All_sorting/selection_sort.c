#include<stdio.h>

void arrayInput(int [], int);
void arrayDisplay(int [], int);
void sortElements(int [], int);

int main()
{
    int arr[50], limit;
    printf("Enter how many number you want: ");
    scanf("%d", &limit);
    printf("Enter array elements: \n");
    arrayInput(arr, limit);
    printf("Before sorting all the elements: \n");
    arrayDisplay(arr, limit);
    printf("After sorting all the elements: \n");
    sortElements(arr, limit);

    return 0;
}
void arrayInput(int arr[], int l)
{
    int i;
    for(i = 0;i < l;i++)
    {
        scanf("%d", &arr[i]);
    }
}
void arrayDisplay(int arr[], int l)
{
    int i;
    for(i = 0;i < l;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sortElements(int arr[], int l)
{
    int i, j, min, temp;
    for(i = 0;i < l;i++)
    {
        min = i;
        for(j = i+1;j < l;j++)
        {
            if(arr[j] < arr[min])   //Desending order
            // if(arr[j] > arr[min])   // Assending order
            min = j;
        }
        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    for(i = 0;i < l;i++)
    {
        printf("%d ", arr[i]);
    }
}
