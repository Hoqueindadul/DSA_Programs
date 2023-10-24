#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node *head=NULL, *temp, *newnode;


struct node
{
	int data;
	struct node *next;
};

void main()
{
	int ch1, ch2;
	
	while(1)
	{
		if(head == NULL)
		{
			printf("(1) Create \t(2) Display\t (3) Exit\n");
			scanf("%d", &ch1);
		}
		else
		{
			printf("(2) Insert\t(3) Delete \t(4) Display\t(5) Exit\n");
			scanf("%d", &ch1);
		}
		switch(ch1)
		{
			case 1: creat();
			break;
			case 2: printf("(6) First\t(7) Last\n");
					scanf("%d", &ch2);
					switch(ch2)
					{
						case 5: asfirst();
						break;
						case 6: aslast();
						break;
						//case 7: asanywhere();
						//break;
						default: if(ch2 == 1)
								 printf("Your choice is wrong!\n");
					}
			break;
			case 3: printf("(8) First\t (9) Last\n");
					scanf("%d", &ch2);
					switch(ch2)
					{
						case 8: asfirst_delt();
						break;
						case 9: aslast_delt();
						break;
						// case 11: asandywhere();
						// break;
						default: if(ch2 == 1)
								 printf("your choice is wrong\n");
					}
			case 4: display();
			break;
			case 5: exit(0);
		}
	}
}
void creat()
{
	int more;
	temp = head;
	do
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data of node:\n");
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
			temp = temp->next;
		}
		printf("For more node Enter (1/0): ");
		scanf("%d", &more);
	}while(more==1);
}

void display()
{
	temp = head;
	if(head == NULL)
	{
		printf("LinkedList is Empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->next !=NULL)
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
void asfirst()
{
	temp = head;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter your data: \n");
	scanf("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
	
}
void aslast()
{
	temp = head;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter your data: \n");
	scanf("%d", &newnode->data);
    //newnode->next = NULL;
	while(temp!= NULL)
	{
		if(temp->next == NULL)
		{
			temp->next = newnode;
			newnode->next = NULL;
		}
		temp = temp->next;
	}
}
void asfirst_delt()
{
	struct node *temp = head;
	if(temp == NULL)
	{
		printf("Your Linkedlist is empty.\n");
	}
	else
	{
		printf("%d is Deleted.\n", temp->data);
		head = head->next;
		free(temp);
	}
}
void aslast_delt()
{
	struct node *temp = head;
	if(temp->next == NULL)
	{
		printf("%d is Deleted.\n", temp->data);
		free(temp);
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->next->next == NULL)
			{
				printf("%d is deleted.\n", temp->next->data);
				free(temp->next);
				temp->next = NULL;
			}
			temp = temp->next;
		}
	}
}