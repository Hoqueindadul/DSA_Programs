// program for create, insert, delete from an array.

#include<stdio.h>


void creat_trvers(int ar[], int siz);
void insert(int ar[], int siz, int elmt, int posi);
void delet(int ar[], int siz, int posi);

int main()
{
    int arr[30], size, pos, elm;
    int i;
    printf("Enter how many elements you want\n");
    scanf("%d", &size);
    printf("Enter your array elements: \n");
    creat_trvers(arr, size);
    printf("Enter your position:\n");
    scanf("%d", &pos);
    printf("enter your element: \n");
    scanf("%d", &elm);
    insert(arr, size, elm, pos);
    printf("For delete\n");
    printf("Enter your position to be delet: \n");
    scanf("%d", &pos);
    delet(arr, size, pos);
    
    
    return 0;
}
void creat_trvers(int ar[], int siz)
{
    int i;
    for(i=0;i<siz;i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Before inserting more elements: \n");
    for(i=0;i<siz;i++)
    {
        printf("%d ", ar[i]);
    }
}
void insert(int ar[], int siz, int elmt, int posi)
{
    int ruf = siz, i;
    while(ruf>=posi)
    {
        ar[ruf+1] = ar[ruf];
        ruf --;
    }
    ar[posi] = elmt;
    siz += 1;
    printf("After inserting more elements: \n");
    for(i=0;i<siz;i++)
    {
        printf("%d ", ar[i]);
    }
}
void delet(int ar[], int siz, int posi)
{

    int delelm, temp = posi;
    printf("Enter your element to be delete: \n");
    scanf("%d", &delelm);
    if(delelm == ar[posi])
    {
        printf("%d is deleted", ar[posi]);
        while(temp<=siz-1)
        {
            ar[temp] = ar[temp+1];
            temp++;
        }
        siz = siz-1;
        printf("After deleting elements: \n");
        for(int i=0;i<=siz;i++)
        {
            printf("%d ", ar[i]);
        }
    }
    else
    {
        printf("Your entered number is not present in that position\n");
    }
    
    
    
}