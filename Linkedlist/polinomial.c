#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coefe, expo;
    struct node *next;
};
struct node *next;
void create(struct node **poly, int coef, int exp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coefe = coef;
    newnode->expo = exp;
    newnode->next = NULL;
    if (*poly == NULL)
    {
        *poly = newnode;
        return;
    }
    else
    {
        struct node *head = *poly;
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = newnode;
    }
}
void display(struct node *poly)
{
    if (poly == NULL)
    {
        printf("\nThere Is Nothing Any Polynomial !!!");
        return;
    }
    else
    {
        struct node *temp = poly;
        while (temp != NULL)
        {
            printf("%dX^%d", temp->coefe, temp->expo);
            if (temp->next != NULL)
            {
                printf(" + ");
            }
            temp = temp->next;
        }
    }
}
void main()
{
    printf("\n\t--- Addition Of Two Polynomial Using Linked List ---\n");
    int term, i, c, e;
    struct node *p1, *p2, *p3;
    p1 = p2 = p3 = NULL;
    printf("\nHow Many Term For 1st Polynomial ? => ");
    scanf("%d", &term);
    for (i = 0; i < term; i++)
    {
        printf("\nEnter Coeffecient For %d Term => ", i + 1);
        scanf("%d", &c);
        printf("\nEnter Exponent For %d Term => ", i + 1);
        scanf("%d", &e);
        create(&p1, c, e);
    }
    printf("\nHow Many Term For 2nd Polynomial ? => ");
    scanf("%d", &term);
    for (i = 0; i < term; i++)
    {
        printf("\nEnter Coeffecient For %d Term => ", i + 1);
        scanf("%d", &c);
        printf("\nEnter Coeffecient For %d Term => ", i + 1);
        scanf("%d", &e);
        create(&p2, c, e);
    }
    printf("\n1st_Polynomial : ");
    display(p1);
    printf("\n2nd_Polynomial : ");
    display(p2);
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo == p2->expo)
        {
            create(&p3, p1->coefe + p2->coefe, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo)
        {
            create(&p3, p1->coefe, p1->expo);
            p1 = p1->next;
        }
        else
        {
            if (p1->expo < p2->expo)
            {
                create(&p3, p2->coefe, p2->expo);
                p2 = p2->next;
            }
        }
    }
    while (p1 != NULL)
    {
        create(&p3, p1->coefe, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        create(&p3, p2->coefe, p2->expo);
        p2 = p2->next;
    }
    printf("\nAddition Result : ");
    display(p3);
}

