#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node *ladd;
    int data;
    struct node *radd;
};struct node *root = NULL, *new1;

void creat(struct node *r, struct node *new1);
void inorder(struct node *r);
void preorder(struct node *r);
void postorder(struct node *r);

int main()
{
    int ch;
    do
    {
        printf("\n Tree Application ");
        printf("\n 1.Create ");
        printf("\n 2.Inorder ");
        printf("\n 3.Preorder ");
        printf("\n 4.Postorder ");
        printf("\n 5.Exit ");
        printf("\n ---------------------");
        printf(" \n Enter your choice...");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            char choice;
            do
            {
                int n;
                printf("\n Enter an element:");
                scanf("%d", &n);
                new1 = (struct node *)(malloc(sizeof(struct node)));
                new1->ladd = new1->radd = NULL;
                new1->data = n;
                if (root == NULL)
                    root = new1;
                else
                    creat(root, new1);
                printf(" \n Want to continue (Y/N): ");
                scanf(" %c", &choice);
            } while (choice == 'y' || choice == 'Y');
            break;
        }
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
        }

    } while (ch != 5);
    return 0;
}
void creat(struct node *r, struct node *new1)
{
    if (new1->data < r->data)
    {
        if (r->ladd == NULL)
            r->ladd = new1;
        else
            creat(r->ladd, new1);
    }
    else if (new1->data > r->data)
    {
        if (r->radd == NULL)
            r->radd = new1;
        else
            creat(r->radd, new1);
    }
    else if (new1->data == r->data)
        printf("\n Duplicate elements are not allowed.");
}
void inorder(struct node *r)
{
    int i = 0;
    struct node *s[100];
    while (1)
    {
        while (r != NULL)
        {
            s[++i] = r;
            r = r->ladd;
        }
        if (i != 0)
        {
            r = s[i--];
            printf("%5d", r->data);
            r = r->radd;
        }
        else
            break;
    }
}
void preorder(struct node *r)
{
    int i = 0;
    struct node *s[100];
    while (1)
    {
        while (r != NULL)
        {
            printf("%5d", r->data);
            s[++i] = r;
            r = r->ladd;
        }
        if (i != 0)
        {
            r = s[i--];
            r = r->radd;
        }
        else
            break;
    }
}
void postorder(struct node *r)
{
    int i = 0;
    struct node *s1[100];
    struct node *s2[100];

    s1[++i] = r;

    while (i != 0)
    {
        r = s1[i--];
        s2[++i] = r;

        if (r->ladd != NULL)
            s1[++i] = r->ladd;
        if (r->radd != NULL)
            s1[++i] = r->radd;
    }

    while (i != 0)
    {
        r = s2[i--];
        printf("%5d", r->data);
    }
}

