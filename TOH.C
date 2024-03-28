
#include <stdio.h>

void move(int n, char a, char b, char c);

int main()
 {
    int n;
    printf("Enter number of Disks: ");
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    return 0; 
}

void move(int n, char a, char b, char c) 
{
    if (n == 1)
	 {
        printf("Move disk %d from %c to %c\n", n, a, c);
    } 
	else
	 {
        move(n - 1, a, c, b);
        printf("Move disk %d from %c to %c\n", n, a, c);
        move(n - 1, b, a, c);
    }
}
