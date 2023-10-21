#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int tos = -1;
int stack[MAX];

void push();
void display();
void pop();
int peep(int);
int update(int pos, int new);

int main()
{
    int ch, posi, r, new_elm, t;
    while(1)
    {
        printf("\n(1) Push\t(2) Display\t(3) Pop\t(4) Peep\t(5) Update\t(6) Exit\n");
        printf("Press:  ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: push();
            break;
            case 2: display();
            break;
            case 3: pop();
            break;
            case 4: printf("Enter your position:\n");
                    scanf("%d", &posi);
                    r = peep(posi);
                    printf("%d: is PeepedOut for Position: %d", r, posi);
            break;
            case 5: printf("Enter your position to update\n");
                    scanf("%d", &posi);
                    printf("Enter new element\n");
                    scanf("%d", &new_elm);
                    t = update(posi, new_elm);
            break;
            case 6: exit(0);

            default: printf("Your entered choice is wrong! Pleace enter right choice.");
        }
        
    }
}
void push()
{
    int num;
    if(tos == MAX-1)
    {
        printf("Stack is full");
    }
    else
    {
         printf("Enter your data: \n");
        scanf("%d", & num);
        tos++;
        stack[tos] = num;
    }
}
void display()
{
    if(tos == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("Your present Stack is: \n");
        for(int i = tos;i>-1;i--)
        {
            printf("|%d|\n", stack[i]);
        }
    }
}
void pop()
{
    if(tos == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Your elements is deleted: %d\n", stack[tos]);
        tos --;
    }
}
int peep(int pos)
{
    int elm;
    if(tos-pos+1 < 0)
    {
        printf("Value is not accessable\n");
        exit(0);
    }
    else
    {
        int elm = stack[tos-pos+1];
        
    }
    return (elm);
}
int update(int pos, int new)
{
    int res;
    if(tos-pos+1<0)
    {
        printf("Element can't be Update\n");
    }
    else
    {
        res = stack[tos - pos + 1];
        stack[tos-pos+1] = new;
    }
    return (res);
}