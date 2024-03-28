#include <stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int front = 0, rear = -1;
void insert();
void Delet();
void display();
void temp();

int main()
 {
    int choice;
    
    do
	 {
        printf("-----------------Queue Menu---------------");
        printf("\n 1.Insert \n 2.Delete \n 3.Display \n 4.Temp \n 5.Exit");
        printf("\n----------------------------------------");
        printf("\n Enter your choice (1->5): ");
        scanf("%d", &choice);
        
        switch (choice)
		 {
            case 1: insert(); break;
            case 2: Delet(); break;
            case 3: display(); break;
            case 4:temp();break;
            case 5: break;
            default: printf("\n Invalid choice");
        }
    } while (choice != 4);  
    
    return 0;
}

void insert() 
{
    int n;
    
    if (rear == MAXSIZE - 1)
        printf("\n Queue is overflow");  
    else
	 {
        printf("Enter an element: ");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;
    }
}

void Delet() 
{
    int n;
    
    if (front > rear)
        printf("\n Queue is empty");
    else
	 {
        n = queue[front];
        front++;
        printf(" Deleted element is %d", n);  
    }
}

void display()
 {
    int i;
    
    if (front > rear)
        printf("\n Queue is empty");
    else
	 {
        printf("\n Elements of Queue:\n");
        
        for (i = front; i <= rear; i++)  
            printf("%5d", queue[i]);
    }
}
void temp()
{
    int i;
    for (i = 0; i<10; i++)
    {
        printf("%d\n", queue[i]);  
    }
}