#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void creat();
void display();
void delet_anywhere();

int length_list();

struct node *head = NULL;
struct node *tail = NULL;

 struct node
{
    int data;
    struct node *next;
    struct node *prev;
};


void main()
{
	char ch1, ch2;
    int catch;
	catch = length_list();   
	while(1)
	{
             
                      
		if(head == NULL && tail == NULL)
		{
			printf("(c) Create \t (e) Exit\n");
			scanf(" %c", &ch1);
             
		}
		else
		{
			printf("(r) Delete anywhere\t (d) Display\t(e) Exit\n");
			scanf(" %c", &ch1);
		}
		switch(ch1)
		{
			case 'c': creat();
			break;
            case 'r': delet_anywhere(catch);
			break;		
            case 'd': display();
			break;
        	case 'e': exit(0);
            default: printf("Your choice is wrong.\n");
        }
    }
}


int length_list()
{ 
    int count = 0;
    struct node *temp = head;
    while(temp != NULL)
    {  
        count++;
        temp = temp->next;
    }
    return(count);
}
void creat()
{
    char more;
    struct node* newnode;
    do{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: \n");
    scanf("%d", &newnode->data);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        head->prev = NULL;
    }
    else
    {
        if(head == tail)
        {
            head->next = newnode;
            newnode->prev = head;
            newnode->next = NULL;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = NULL;
            tail = newnode;
            
        }
    }
    printf("do you want more node Press (y/n): ");
    scanf(" %c", &more);
    }while(more == 'y');
}
void display()
{
    int choi ,count =0;
    struct node *temp = head, *temp1 = tail;
    temp = head;
    temp1 = tail;
    if(temp == NULL)
    {
        printf("Linkedlist is empty.\n");
    }
    else
    {
        printf("You want display linkedlist from \n(1) Head (2) Tail\n");
        printf("Enter:> ");
        scanf("%d", &choi);
        if(choi == 1)
        {
            while(temp != NULL)
            {  // count++;
                if(temp->next != NULL)
                {
                    printf("%d -> ", temp->data);
                }
                else
                {
                    printf("%d", temp->data);
                    printf("\n");
                }
                temp = temp->next;
            }
        }
        if(choi == 2)
        {
            while(temp1 != NULL)
            {
                if(temp1->prev != NULL)
                {
                    printf("%d -> ", temp1->data);
                }
                else
                {
                    printf("%d", temp->data);
                    printf("\n");
                }
              
                temp1 = temp1->prev;
            }
        }
	}
}
void delet_anywhere(int cath)
{

    struct node *temp = head;
    int num;
    printf("Enter your position: ");
    scanf("%d", &num);
    if(head->data == num)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }
    if(tail->data == num)
    {
        tail = tail->prev;
        tail->next = NULL;
        return;
    }
    if(head->next->data == num)
    {
        head->next = head->next->next;
        head->next->prev = head;
        return;
    }
    head = head->next;
    
}
