#include <stdio.h>

int main() {
    int test;
    long int n,even_sum=0,odd_sum=0;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        scanf("%ld",&n);
        even_sum=0;
        odd_sum=0;
        for(int j=0;j<=n;j++)
        if(j%2 == 0)
         even_sum += j;
        else
         odd_sum +=j;
        printf("%ld %ld\n",odd_sum,even_sum); 
    }
    
	//code
	return 0;
}
