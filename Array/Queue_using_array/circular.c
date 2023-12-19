#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert_queue();
void display_queue();
void delet_queue();

int queue[MAX];
int rear = -1, front = -1;

void main()
{
    int choice;
    while(1)
    {
        printf("(1) Insert\t (2) Display\t (3) Delete\t (4) Exit\n");
        printf("Press:> ");
        scanf("%d", &choice);
        switch (choice)
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
    if((rear == MAX -1 && front == 0) || (front == rear +1))
    {
        printf("Queue is Full.\n");
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
            rear = (rear + 1) % MAX;
            queue[rear] = num;
        }
    }
}
void delet_queue()
{
    if(rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        if(rear == front)
        {
            printf("%d is deleted.\n", queue[front]);
            rear = -1;
            front = -1;
        }
        else
        {
            printf("%d is deleted.\n", queue[front]);
            front = (front+1) % MAX;
        }
    }
}
void display_queue()
{
    if(rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        if(rear >= front)
        {
            for(int i=front;i<=rear;i++)
            {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
        else
        {
            for(int i=0;i<=rear;i++)
            {
                printf("%d ", queue[i]);
            }
            
            for(int i=front;i<MAX;i++)
            {
                printf("%d ", queue[i]);
            }
            
            printf("\n");
        }
        
    }
}

