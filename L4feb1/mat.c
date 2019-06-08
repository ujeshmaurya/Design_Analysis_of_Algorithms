#include<stdio.h>
#include<limits.h>
int n;
int order(int a[], int i, int j)
{
    if(i == j)
        return 0;
    int min = INT_MAX,k,count;
    for (k = i; k <j; k++)
    {
    //printf("%d %d %d \n",i-1,k,j);
        count=order(a,i,k)+order(a, k+1, j)+a[i-1]*a[k]*a[j];
        if(i-1==0 && j==n-1)
        printf("%d %d %d %d\n",count,i-1,k,j);
        if (count < min)
            min = count;
    }
    return min;
}
int main()
{
	
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    printf("Minimum number of multiplications is %d\n", order(a, 1, n-1));
    return 0;
}
