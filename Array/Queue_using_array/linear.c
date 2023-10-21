#include<stdio.h>
#include<stdlib.h>
#define MAX 6


void insert_queue();
void display_queue();
void delet_queue();


int front = -1;
int rear = -1;
int queue[MAX];

void main()
{
    int ch;
    while(1)
    {
        printf("(1) Insert\t (2) Display\t (3) Delete\t (4) Exit\n");
        printf("Press:> ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: insert_queue();
            break;
            case 2: display_queue();
            break;
            case 3: delet_queue();
            break;
            case 4: exit(0);
            default: printf("\nYour entered choice is wrong. Pleace enter right choice!\n");
            
        }
    }

}
void insert_queue()
{
    int num;
    if(rear == MAX-1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        printf("Enter your number: \n");
        scanf("%d", &num);
        if(rear == -1)
        {
            rear ++;
            front ++;
            queue[rear] = num;
        }
        else
        {
            rear ++;
            queue[rear] = num;
        }
    }
}
void display_queue()
{
    int i;
    if(front == -1)
    {
        printf("\nQueue is empty.\n\n");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
void delet_queue()
{
    if(rear == -1)
    {
        printf("\nQueue is empty\n\n");
    }
    else
    {
        if(rear == front)
        {
            printf("\n%d is deleted.\n\n", queue[front]);
            rear = -1;
            front = -1;
        }
        else
        {   
            printf("\n%d is deleted.\n\n", queue[front]);
            front ++;
        }
    }
}