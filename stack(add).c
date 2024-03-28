#include <stdio.h>
#include <stdlib.h>

int no1, no2, *x, *y, *z, max;

void input()
{
    printf("Enter 1st num: ");
    scanf("%d", &no1);
    printf("Enter 2nd num: ");
    scanf("%d", &no2);
}

int length(int no)
{
    int l = 0;
    while (no > 0)
    {
        ++l;
        no /= 10;
    }
    return (l);
}

int maximum(int l1, int l2)
{
    if (l1 > l2)
        return (l1);
    else
        return (l2);
}

void dataset()
{
    int c = 0;
    *x = (int *)malloc(max * sizeof(int));
    *y = (int *)malloc(max * sizeof(int));
    *z = (int *)malloc(max * sizeof(int));

    for (int i = 0; i < max; ++i)
    {
        *(x + i) = 0;
        *(y + i) = 0;
        *(z + i) = 0;
    }

    for (int i = max - 1; no1 > 0; --i, no1 /= 10)
        *(x + i) = no1 % 10;
    
    for (int i = max - 1; no2 > 0; --i, no2 /= 10)
        *(y + i) = no2 % 10;

    for (int i = max - 1; i >= 0; --i)
    {
        int s = *(x + i) + *(y + i) + c;
        if (s >= 10)
        {
            c = s / 10;
            s = s % 10;
        }
        *(z + i) = s;
    }
}

void print()
{
    for (int i = 0; i < max; i++)
        printf("%d", *(z + i));
    printf("\n");
}

int main()
{
    input();
    dataset();
    print();
    free(x);
    free(y);
    free(z);
    return 0;
}
