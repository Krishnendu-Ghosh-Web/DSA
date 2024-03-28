#include <stdio.h>
#include<stdlib.h>
struct node
{
	struct node *ladd;
    int data;
    struct node *radd;
};struct node *start = NULL, *new1, *temp, *prev, *next ;

void creat();
void insert_first();
void insert_middle();
void insert_last();
void display();
void  display_reverse();
void Delete_first();
void Delete_middle();
void Delete_last();

int main()
{
    int choice;

    do
    {
        printf("\n----------------- Doubly Linked List Menu---------------");
        printf("\n 1.Creat");
        printf("\n 2.Insert First");
        printf("\n 3.Insert Middle");
        printf("\n 4.Insert Last");
        printf("\n 5.Display");
        printf("\n 6.Display Reverse");
        printf("\n 7.Delete First");
        printf("\n 8.Delete Middle");
        printf("\n 9.Delete Last");
        printf("\n 10.Exit");
        printf("\n------------------------------------------------");
        printf("\n Enter your choice (1->10): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:creat();break;
        case 2:insert_first();break; 
        case 3:insert_middle(); break;
        case 4:insert_last(); break;
        case 5:display();break;
        case 6:display_reverse();break;
        case 7:Delete_first();break;
        case 8:Delete_middle(); break;
        case 9:Delete_last();break;
        case 10:break;
        default:printf("\n Invalid choice");
        }
    } while (choice != 10);

    return 0;
}
void creat()
{
	int n;
	char ch;
	printf("\n Enter first element:");
	scanf("%d",&n);
	start=(struct node*)(malloc(sizeof(struct node)));
	start->ladd=NULL;
	start->data=n;
	start->radd=NULL;
	temp=start;
	printf("\n Do you want to continue :");
	scanf(" %c", &ch);
	while(ch=='y'||ch=='Y')
	
	{
		printf("\n Enter next  element:");
	    scanf("%d",&n);
	    new1=(struct node*)(malloc(sizeof(struct node)));
	    new1->ladd=NULL;
	    new1->data=n;
	    new1->radd=NULL;
	    temp->radd = new1;
	    new1->ladd=temp;
	    temp=temp->radd;
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
	   new1->ladd=new1->radd=NULL;
	    new1->data=n;
	    new1->radd=start;
	    start->ladd=new1;
	    start=new1;
		
	}
	    
}
void insert_middle()
{
    int n, pos, i = 1;
    if (start == NULL)
        printf("\n List not found");
    else
    {
        printf("\n Enter element for insert:");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1->ladd = new1->radd = NULL;
        new1->data = n;
        printf("\n Enter the position:");
        scanf("%d", &pos);
        next = start;
        while (i < pos)
        {
            prev = next;
            next = next->radd;
            i++;
        }
        prev->radd = new1;
        new1->ladd = prev;
        new1->radd = next;
        next->ladd = new1;
    }
}
void insert_last()
{
	int n;
	if(start==NULL)
	printf("\n LIst not found");
	else
	{
		printf("\n Enter  element for insert:");
	    scanf("%d",&n);
	    new1=(struct node*)(malloc(sizeof(struct node)));
	    new1->ladd=new1->radd=NULL;
	    new1->data=n;
	    temp=start;
	    while(temp->radd!=NULL)
	    {
	    	temp=temp->radd;
		}
		temp->radd=new1;
		new1->ladd=temp;
	    
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
			temp=temp->radd;
		}
	}
    
}
void display_reverse()
{
	if(start==NULL)
	printf("\n LIst not found");
	else
	{
		temp=start;
		while(temp->radd!=NULL)
		{
			temp=temp->radd;
		}
			while(temp!=NULL)
			{
				printf("%5d",temp->data);
				temp=temp->ladd;
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
		start=start->radd;
		start->ladd=NULL;
		printf("Deleted element is %d",temp->data);
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
		next=start;
		while(i<pos)
		{
			prev=next;
			next=next->radd;
			i++;
		}
		temp=next;
		next=next->radd;
		prev->radd=next;
		next->ladd=prev;
		printf("\n Deleted element is %d",temp->data);
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
		while(temp->radd!=NULL)
		{
			prev=temp;
			temp=temp->radd;
		}
		printf("\n Deleted element is %d",temp->data);
		prev->radd=NULL;
		free(temp);
	}
}