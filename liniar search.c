#include<stdio.h>
int main()
{
	int n,i,s,ar[500],f=0;
	printf("enter the limits:");
	scanf("%d",&n);
	printf("enter the elements in array:\n");
	for(i=0;i<n;i++)
	scanf("%d", & ar[i]);
	printf("Enter element for searching:");
	scanf("%d",&s);
	for(i=0;i<n;i++)
	{
		if(ar[i]==s)
		f=1;
		break;
	}
	if(f=1)
	printf("searching is succes");
	else 
	printf("searching is not succes");
	
	return 0;
	
}