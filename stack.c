#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top = -1;
void push();
void pop();
void display();
void temp();
int main()
{
    int choice;
    
    do
    {
        printf("----------------stack------------------");
        printf("\n 1.push \n 2. pop \n 3. display \n 4.temp \n 5.exit");
        printf("\n----------------------------------------");
        printf("\n Enter your choice between (1->5): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break; 
            case 3: display(); break;
            case 4:temp();break;
            case 5: break; 
			 
            default: printf("\n invalid choice");
        }
    } while (choice != 4);  
    
    return 0;
}

void push()
{
    int n;
    if (top == MAXSIZE - 1)  
        printf("\n stack is overflow ");
    else
    {
        printf("Enter an element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void pop()
{
    int n;
    if (top == -1)
        printf("\n stack is empty");
    else
    {
        n = stack[top];
        top--;
        printf("Popped element is %d", n);  
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("stack is empty");
    else
    {
        printf("Elements of stack:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);  
    }
}

void temp()
{
    int i;
    for (i = 0; i<10; i++)
    {
        printf("%d\n", stack[i]);  
    }
}