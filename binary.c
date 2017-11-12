#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int k=0,rem,n,count=1,arr[100]; 
    scanf("%d",&n);
    for(n;n>0;n=n/2)
	 {
        rem=n%2;
        arr[k]=rem;
        k++;
    }
    
    for(int j=0;j<k;j++)
    {
    	printf("%d",arr[j]);
        if(arr[j] == arr[j+1])
            count++;
    }
    printf("%d",count);
    return 0;
}

