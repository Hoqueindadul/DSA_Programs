#include<stdio.h>

void creat_array(int arr[], int s);
void traverse_array(int arr[], int s);

int main()
{
    int arr[50], size, res;
    printf("Enter How Many Elements You Want: \n");
    scanf("%d", &size);
    creat_array(arr, size);
    printf("After Traversing The array:\n");
    traverse_array(arr, size);
    
}

void creat_array(int arr[], int s)
{
    printf("Enter your Array Elements: \n");
    for(int i=0;i<s;i++)
    {
        scanf("%d", &arr[i]);
    }
}
void traverse_array(int arr[], int s)
{
    for(int i = 0;i < s;i++)
    {
        printf("%d ", arr[i]);
    }
}
