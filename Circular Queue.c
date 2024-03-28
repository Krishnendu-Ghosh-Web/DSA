#include <stdio.h>
#define MAXSIZE 10
int cq[MAXSIZE];
int rear = -1, front = -1;
void insert();
void Delet();
void display();
void temp();
int main()
 {
    int choice;
    
    do
	 {
        printf("----------------- Circular Queue Menu---------------");
        printf("\n 1.Insert \n 2.Delete \n 3.Display \n .4 Temp  \n 5.Exit");
        printf("\n----------------------------------------");
        printf("\n Enter your choice (1->4): ");
        scanf("%d", &choice);
        
        switch (choice)
		 {
            case 1: insert(); break;
            case 2: Delet(); break;
            case 3: display(); break;
            case 4: temp();break;
            case 5: break;
            default: printf("\n Invalid choice");
        }
    } while (choice != 5);  
    
    return 0;
}
void insert()
{
	int n;
	if((rear+1)%MAXSIZE==front)
	printf("\n Queue is overflow");
	else
	{
		printf("\n Enter an element :");
		scanf("%d",&n);
		if(rear==-1 && front==-1)
		{
			front=0;
			rear=0;
		}
		else
		rear=(rear+1)%MAXSIZE;
		cq[rear]=n;
	}
	
}
void Delet()
{
	int n;
	if(rear==1 && front==-1)
    printf("\n Queue is empty");
	else
    {
    	n=cq[front];
    	printf("\n Deleted element is %d",n);
    	if(front==rear)
    	{
    		front=-1;
    		rear=-1;
		}
		front=(front+1)%MAXSIZE;	
	}
	
}
void display()
{
	int i;
	if(rear==-1 && front==-1)
	printf("\n Queue is empty");
	else
	{
		printf("\n Elements of Queue");
		for(i=front;i!=rear;(i=(i+1)%MAXSIZE))
		{
			printf("%5d",cq[i]);
		}
		printf("%5d",cq[i]);
	}
	
}
void temp()
{
    int i;
    for (i = front; i<10; i++)
    {
        printf("%d\n", cq[i]);  
    }
}