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
    int ch, num;
    
    if(rear == MAX - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        
        if(rear == -1)
        {
            printf("Enter your number: \n");
            scanf("%d", &num);
            rear++;
            front++;
            queue[rear] = num;
        }
        else
        {

            printf("(1) From Rear\t (2) From Front\n");
            scanf("%d", &ch);
            printf("Enter your number: \n");
            scanf("%d", &num);
            switch(ch)
            {
                case 1: rear++;
                        queue[rear] = num;
                        break;
                
                case 2: for(int i=rear;i>=front;i--)
                        { 
                            queue[i+1] = queue[i];
                        }
                        queue[front] = num;
                        rear++;
                        break;
                default: printf("your choice is wrong!\n");
            }
                
        }
    }
}
void display_queue()
{
    int i;
    if(rear == -1)
    {
        printf("Queue is empty.\n");
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
    int i, dch;
    if(rear == -1)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        if(rear == front)
        {
            printf("%d is deleted.\n", queue[front]);
            front = -1;
            rear = -1;
        }
        else
        {
            printf("(1)From Rear\t(2) From Front\n");
            scanf("%d", &dch);
            switch(dch)
            {
                case 1: printf("%d is deleted.\n", queue[rear]);
                        rear--;
                        break;
                case 2: printf("%d is deleted.\n", queue[front]);
                        front++;
                        break;
                default: printf("Your choice is wrong!\n");
            }
        }
    }
}