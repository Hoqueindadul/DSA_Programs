#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

typedef struct node
{
    int data;
    struct node *next;
}stk;
stk *tos = NULL;
int main()
{
    int ch, posi, r, new_elm, t;
    while(1)
    {
        printf("\n(1) Push\t(2)Pop \t(3) Display\t(6) Exit\n");
        printf("Press:  ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 6: exit(0);

            default: printf("Your entered choice is wrong! Pleace enter right choice.");
        }
    }  
}
void push()
{
    stk *newnode;
    newnode = (stk *)malloc(sizeof(stk));
    printf("Enter the data of the node:\n");
    scanf("%d", &newnode->data);
    if(tos == NULL)
    {
        tos = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = tos;
        tos = newnode;
    }
}
void pop()
{
    stk *temp = tos;
    if(tos == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("%d is deleted.", tos->data);
        tos = tos->next;
        free(temp);
    }
}
void display()
{
    stk *temp = tos;
    if(temp == NULL)
    {
        printf("Stack is empty.");
    }
    else
    {
        while(temp != NULL)
        {
            printf("|%d|\n", temp->data);
            temp = temp->next;
        }
        
    }
}