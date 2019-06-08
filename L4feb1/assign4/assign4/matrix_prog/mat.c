#include<stdio.h>
#include "matrix.h"



int main()
{
	int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    printf("Minimum number of multiplications is %d\n", order(a, 1, n-1));
	dp_order(a,n);
    return 0;
}
