#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

struct node
{
    int data;
    struct node *add;
};struct node *start = NULL, *new1, *temp, *prev, *next;

void creat();
void insert_first();
void insert_middle();
void insert_last();
void display();
void Delete_first();
void Delete_middle();
void Delete_last();

int main()
{
    int choice;

    do
    {
        printf("\n----------------- Linked List Menu---------------");
        printf("\n 1.Creat");
        printf("\n 2.Insert First");
        printf("\n 3.Insert Middle");
        printf("\n 4.Insert Last");
        printf("\n 5.Display");
        printf("\n 6.Delete First");
        printf("\n 7.Delete Middle");
        printf("\n 8.Delete Last");
        printf("\n 9.Exit");
        printf("\n------------------------------------------------");
        printf("\n Enter your choice (1->9): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:creat();break;
        case 2: insert_first();break; 
        case 3:insert_middle(); break;
        case 4:insert_last(); break;
        case 5:display();break;
        case 6:Delete_first();break;
        case 7:Delete_middle(); break;
        case 8: Delete_last();break;
        case 9:break;
        default:printf("\n Invalid choice");
        }
    } while (choice != 9);

    return 0;
}

void creat()
{
	int n;
	char ch;
	printf("\n Enter first element:");
	scanf("%d",&n);
	start=(struct node*)(malloc(sizeof(struct node)));
	start->data=n;
	start->add=NULL;
	temp=start;
	printf("\n Do you want to continue :");
	scanf(" %c", &ch);
	while(ch=='y'||ch=='Y')
	
	
	{
		printf("\n Enter next  element:");
	    scanf("%d",&n);
	    new1=(struct node*)(malloc(sizeof(struct node)));
	    new1->data=n;
	    new1->add=NULL;
	    temp->add=new1;
	    temp=temp->add;
	    printf("\n Do you want to continue :");
	    scanf(" %c", &ch);
	}
    
}

void insert_first()
{
	int n;
	if(start==NULL)
	printf("\n LIst not found");
	else
	{
		printf("\n Enter  element for insert:");
	    scanf("%d",&n);
	    new1=(struct node*)(malloc(sizeof(struct node)));
	    new1->data=n;
	    new1->add=NULL;
	    new1->add=start;
	    start=new1;
		
	}
	    
}

void insert_middle()
{
	int n,pos,i;
	if(start==NULL)
	printf("\n LIst not found");
	else
	{
		printf("\n Enter  element for insert:");
	    scanf("%d",&n);
	    new1=(struct node*)(malloc(sizeof(struct node)));
	    new1->data=n;
	    new1->add=NULL;
	    printf("\n Enter position:");
	    scanf("%d",&pos);
	    next=start;
	    while(i<pos)
	    {
	    	prev=next;
	    	next=next->add;
	    	i++;
		}
		prev->add=new1;
		new1->add=next;
		
	}
    
}

void
 insert_last()
{
	int n;
	if(start==NULL)
	printf("\n LIst not found");
	else
	{
		printf("\n Enter  element for insert:");
	    scanf("%d",&n);
	    new1=(struct node*)(malloc(sizeof(struct node)));
	    new1->data=n;
	    new1->add=NULL;
	    temp=start;
	    while(temp->add!=NULL)
	    {
	    	temp=temp->add;
		}
		temp->add=new1;
	    
	}
	
}

void display()
{
	if(start==NULL)
	printf("\n LIst not found");
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->add;
		}
	}
    
}

void Delete_first()
{
	if(start==NULL)
	printf("\n List not found");
	else
	{
		temp=start;
		start=start->add;
		printf("Deleted node is %d",temp->data);
		
		free(temp);
	}
    
}

void Delete_middle()
{
	int pos,i=1;
	if(start==NULL)
	printf("\n List not found");
	else
	{
		printf("Enter the position :");
		scanf("%d",&pos);
		temp=start;
		while(i<pos)
		{
			prev=temp;
			temp=temp->add;
			i++;
		}
		next=temp->add;
		prev->add=next;
		printf("\n Deleted node is %d",temp->data);
		free(temp);
	}
	
}

void Delete_last()
{
	if(start==NULL)
	printf("\n List not found");
	else
	{
		temp=start;
		while(temp->add!=NULL)
		{
			prev=temp;
			temp=temp->add;
		}
		prev->add=NULL;
		printf("\n Deleted node is %d",temp->data);
		free(temp);
	}
}