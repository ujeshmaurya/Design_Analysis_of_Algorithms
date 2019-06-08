#include <stdio.h>

int bSearch(int *arr,int *s,int n, int value)
{
   int low = 0,high = n-1,mid;
   while (low < high)
   {
       mid = low + ((high - low) / 2);
       if (arr[s[mid]] > value)
           high = mid;
       else if (arr[s[mid]] < value)
           low = mid + 1;
       else
           return mid;
   }
   return low;
}
int lis(int *arr, int n)
{
    int s[n],p[n],size=0,i;
    for(i=0 ; i<n ;i++)
    {
        if(i == 0)
        {
            s[size] = i;
            p[i] = -1;
        }
        else if(arr[i] <= arr[s[size]])
        {
            int pos = bSearch(arr,s,size+1,arr[i]);
            s[pos] = i;
            if(pos != 0)
            {
                 p[i] = s[pos-1];
            }
        }
        else
        {
            size = size+1;
            s[size] = i;
            p[i] = s[size-1];
        }
    }
    printf("Length of Longest Increasing Subsequence = %d\n",size+1);
  
    int pos = s[size],b[n],j;
    i=0;
    while(size >=0)
    {
        b[i++]=arr[pos];
        pos = p[pos];
        size--;
    }
    for(j=i-1;j>=0;j--)
    	printf("%d ",b[j]);
    printf("\n");
}
  
int main()
{
	int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    lis(arr,n);
    return 0;
}
