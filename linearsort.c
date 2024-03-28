#include<stdio.h>
int main() 
{
    int i, j, n, arr[500], temp;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
	printf("Sorted elements are: ");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}



