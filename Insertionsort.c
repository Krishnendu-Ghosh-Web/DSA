#include<stdio.h>
int main() 
{
    int i, j,k, n, arr[500], temp;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    for (k = 0; k < n; k++) 
    {
       temp=arr[k];
       j=k-1;
       while((temp<arr[j]) && j>=0)
       {
       	arr[j+1]=arr[j];
       	j--;
	   }
	   arr[j+1]=temp;
    }
    printf("Sorted elements are: ");
    for (i = 0; i < n; i++)
        printf("\t %d", arr[i]);

    return 0;
}



