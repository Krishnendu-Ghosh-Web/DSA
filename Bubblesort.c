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
        for (j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted elements are: ");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}



