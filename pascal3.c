#include<stdio.h>
int main()
{
	int i,j,k,n,v;
	printf("enter row:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		v=1;
		for(j=0;j<n-i;j++)
		printf(" ");
		for(k=0;k<=i;k++)
		{
			printf("%d ",v);
			v *= (float)(i-k)/(k+1);
		}
		printf("\n");
	}
	
}
