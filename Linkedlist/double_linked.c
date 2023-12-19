#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void creat();
void display();
void insert_asfirst();
void insert_aslast();
void insert_anywhere();
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
	while(1)
	{
       
		if(head == NULL && tail == NULL)
		{
			printf("(c) Create \t (e) Exit\n");
			scanf(" %c", &ch1);
             
		}
		else
		{
			printf("(i) Insert\t(r) Delete \t(d) Display\t(L) Length\t(e) Exit\n");
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
			 			case 'a': insert_anywhere(catch);
			 			break;
						default: if(ch2 == 'c')
                                 printf("Your choice is wrong!\n");
					}
			break;
			// case 'r': printf("(p) First\t (s) Last\n");
			//  		scanf(" %c", &ch2);
			//  		switch(ch2)
			//  		{
			//  			case 'p': delet_asfirst();
			//  			break;
			//  			case 's': delet_aslast();
			//  			break;
			//  			case 'j': delet_anywhere();
			// 			break;
			//  			default: printf("your choice is wrong\n");
			//  		}
			case 'd': display();
			break;
            case 'L': catch = length_list();        
                      printf("The tatal length of your list is: %d\n", catch);
            break;
			case 'e': exit(0);
            default: if(ch1 == 'i','r','d')
                    printf("Your choice is wrong.\n");
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
    // printf("the length is: %d", count);
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
    // newnode->next = NULL;
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

void insert_asfirst()
{
    struct node *newnode;
    char choice;
    do{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the node data: \n");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        head->prev = NULL;
        printf("Do you want to more node. Press(y/n):>");
        scanf(" %c", &choice);
    }while(choice == 'y');
    
}


void insert_aslast()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: \n");
    scanf("%d", &newnode->data);
    while(tail != NULL)
    {
        if(tail->next == NULL)
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            tail->next = NULL;
            
            break;
        }
        tail = tail->next;
    }
}

void insert_anywhere(int catch)
{
    struct node *newnode, *temp = head;
    int position, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: \n");
    scanf("%d", &newnode->data);
    printf("Enter your position: ");
    scanf("%d", &position);
    
        if(position<1 && position>catch)
        {
            printf("Your entered position is invalid! Pleace enter valid position.");
        }
        else
        {
             if(position == 1)
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                newnode->prev = NULL;
            }
            else
            {
                while(i < position)
                {
                    temp = temp->next;
                    i++;
                }
                newnode->prev = temp;
                newnode->next = temp->next;
                temp->next = newnode;
                newnode->next->prev = newnode;
            }
      
        //  if(head->data == position)
        //  {
        //     newnode->next = head->next;
        //     head->next->prev = newnode;
        //     head->next = newnode;
        //     newnode->prev = head;
        //  }
        //  else if(tail->data == position)
        //  {
        //     tail->next = newnode;
        //     newnode->prev = tail;
        //     newnode->next = NULL;
        //     tail = newnode;
        //  }
        //  else if(head->next->data == position)
        //  {
        //     newnode->next = head->next->next;
        //     head->next->next->prev = newnode;
        //     head->next->next = newnode;
        //     newnode->prev = head->next;
        //  }
        //  head = head->next;
        }

}


void display()
{
    int choi ,count =0;
    struct node *temp = head, *temp1 = tail;
    // temp = head;
    // temp1 = tail;
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
    // printf("Total count = %d", count);
}


