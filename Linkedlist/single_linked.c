#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void creat();
void display();
void insert_asfirst();
void insert_aslast();
void insert_anywhere();
void delet_asfirst();
void delet_aslast();
void delet_anywhere();

struct node *head=NULL, *temp, *newnode;

struct node
{
	int data;
	struct node *next;
};

void main()
{
	char ch1, ch2;
	
	while(1)
	{
		if(head == NULL)
		{
			printf("(c) Create \t (e) Exit\n");
			scanf(" %c", &ch1);
		}
		else
		{
			printf("(i) Insert\t(r) Delete \t(d) Display\t(e) Exit\n");
			scanf(" %c", &ch1);
		}
		switch(ch1)
		{
			case 'c': creat();
			break;
			case 'i': printf("(f) First\t(l) Last\t (a) AnyWhere\n");
					scanf(" %c", &ch2);
					switch(ch2)
					{
						case 'f': insert_asfirst();
						break;
						case 'l': insert_aslast();
						break;
						case 'a': insert_anywhere();
						break;
						default: if(ch2 == 'c')
                                printf("Your choice is wrong!\n");
					}
			break;
			case 'r': printf("(p) First\t (s) Last\n");
			 		scanf(" %c", &ch2);
			 		switch(ch2)
			 		{
			 			case 'p': delet_asfirst();
			 			break;
			 			case 's': delet_aslast();
			 			break;
			 			case 'j': delet_anywhere();
						break;
			 			default: printf("your choice is wrong\n");
			 		}
			case 'd': display();
			break;
			case 'e': exit(0);
            default: if(ch1 == 'i','r','d')
                    printf("Your choice is wrong.\n");
		}
	}
}

void creat()
{
    temp = head;
    char choi;
    do{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of the node: \n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to more node. if(Yes) Press:y || if(N0) Press: N:> ");
        scanf(" %c", &choi);
    }
    while(choi == 'y');
}

void display()
{
    temp = head;
    if(head == NULL)
    {
        printf("LinkedList is empty. Pleace create linkedlist.");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->next != NULL)
            {
                printf("%d -> ", temp->data);
            }
            else
            {
                printf("%d ", temp->data);
                printf("\n");
            }
            temp = temp->next;
        }
    }
}

void insert_asfirst()
{
    temp = head;
    char mor;
    do{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of the nde: \n");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
        printf("Do you insert more node as first then Press (y/n):  ");
        scanf(" %c", &mor);
    }while(mor == 'y');
}
void insert_aslast()
{
    temp = head;
    char mor1;
    do{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of the node: \n");
        scanf("%d", &newnode->data);
        //ewnode->next = NULL;
        if(temp->next == NULL)
        {
            temp->next = newnode;
            newnode->next = NULL;   
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next == NULL)
                {
                    temp->next = newnode;
                    newnode->next = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
        printf("Do you insert more node as first then Press (y/n):  ");
        scanf(" %c", &mor1);
    }while(mor1 == 'y');
}
void insert_anywhere()
{
    temp = head;
    int nodedata, choi, found = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of the node: \n");
    scanf("%d", &newnode->data);
    printf("Enter node data from where you want insert another node: ");
    scanf("%d", &nodedata);
    printf("(B) Before\t (A) After\n");
    scanf(" %c", &choi);
    if(choi == 'B')
    {
        if(head->data == nodedata)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            while(found == 0 && temp != NULL)
            {
                if(temp->next->data == nodedata)
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    found = 1;
                    
                }
                else
                {
                    printf("Your entered nodedata is not present.");
                }
                temp = temp->next;
            }
        }
    }
    if(choi == 'A')
    {
        while(1)
        {
            if(temp->next == NULL)
            {
                temp->next = newnode;
                newnode->next = NULL;
                break;
            }
            if(temp->data == nodedata)
            {
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            else
            {
                printf("Your entered node data in not present.");
            }
            temp = temp->next;
        }
    }
}

void delet_asfirst()
{
    temp = head;
    if(head == NULL)
    {
        printf("Linkedlist is empty.\n");
    }
    else
    {
        if(temp->next == NULL)
        {
            printf("%d is deleted.\n", temp->data);
            // head = NULL;
            free(temp);
        }
        else
        {
            printf("%d is deleted.\n", temp->data);
            head = head->next;
            free(temp);
        }
    }
}
void delet_aslast()
{
    temp = head;
    if(head == NULL)
    {
        printf("Linkedlist is empty.\n");
    }
    else
    {
        if(temp->next == NULL)
        {
            printf("%d is deleted.", temp->data);
            temp = NULL;
            head = temp;
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next->next == NULL)
                {
                    printf("%d is deleted.\n", temp->next->data);
                    free(temp->next);
                    temp->next = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void delet_anywhere()
{
    int nodedata, found = 0;
    temp = head;
    printf("Enter the node data whick want to delte: ");
    scanf("%d", &nodedata);
    if(head->data == nodedata)
    {
        printf("%d is deleted\n", head->data);
        head = head->next;
        free(temp);
    }
    else
    {
        while(found == 0 && temp != NULL)
        {
            if(temp->next->data == nodedata)
            {
                printf("%d id deleted.\n", temp->next->data);
                temp->next = temp->next->next;
                break;
            }
        }
        temp = temp->next;
    }
}