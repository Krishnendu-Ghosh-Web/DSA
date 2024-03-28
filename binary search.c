#include<stdio.h>
int main()
{
	int i,n,s,ar[500],j,temp,low=0,high,mid,f=0;
	printf("Enter the limits:");
	scanf("%d",&n);
	printf("Enter elements in array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",& ar[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ar[j]<ar[i])
			{
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}	
	printf("enter element for search:");
	scanf("%d",&s);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(s==ar[mid])
		{
			f=1;
			break;
		}
		else
		if(s>ar[mid])
		low=mid+1;
		else
		high=mid-1;
	}
	if(f==1)
	printf("searching success..");
	else
	printf("searching not succes..");
	return 0;
}