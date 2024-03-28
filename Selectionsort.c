#include <stdio.h>

int main()
 {
    int i, j, n, arr[500], temp, min, loc;
    printf("Enter the limit: ");
    scanf("%d", &n);
    if (n > 500)
	 {
        printf("Invalid limits. Please enter below 500.\n");
    } 
	else 
	{
        printf("Enter the elements:\n");
        for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        for (i = 0; i < n ; i++)
		 {
            min = arr[i];
            loc = i;
            for (j = i + 1; j < n; j++) 
			{
                if (arr[j] < min)
				 {
                    min = arr[j];
                    loc = j;
                }
            }
            if (i != loc) 
			{
                temp = arr[i];
                arr[i] = arr[loc];
                arr[loc] = temp;
            }
        }

        printf("\nSorted elements are:");
        for (i = 0; i < n; i++)
        printf("\t%d", arr[i]);
    }
    return 0;
}






