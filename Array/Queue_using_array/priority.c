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
        if(rear == MAX - 1)
        {
            printf("Queue is full.\n");
        }
        else
        {
            printf("Enter your number: \n");
            scanf("%d", &num);
            int position;
            position = rear;
            rear = rear + 1;
            while(position >= 0 && queue[position] >= num)
            {
                queue[position + 1] = queue[position];
                position = position - 1;
            }
            queue[position + 1] = num;
            if(front == -1)
            {
                front = front + 1;
            }
        }
    }

    void display_queue()
    {
        if(front == -1)
        {
            printf("Queue is empty.\n");
        }
        else
        {
            for(int i=front;i<=rear;i++)
            {
                printf("%d ", queue[i]);
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
            if(front == rear)
            {
                printf("%d is deleted.\n", queue[front]);
                rear = -1;
                front = -1;
            }
            else
            {
                printf("%d is deleted.\n", queue[front]);
                front ++;
            }

        }
    }