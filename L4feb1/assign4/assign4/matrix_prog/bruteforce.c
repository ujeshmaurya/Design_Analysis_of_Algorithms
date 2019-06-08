#include<limits.h>
int order(int a[], int i, int j)
{
    if(i == j)
        return 0;
    int min = INT_MAX,k,count;
    for (k = i; k <j; k++)
    {
        count=order(a,i,k)+order(a, k+1, j)+a[i-1]*a[k]*a[j];
        if (count < min)
            min = count;
    }
    return min;
}
