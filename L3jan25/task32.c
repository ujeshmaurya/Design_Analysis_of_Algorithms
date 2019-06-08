#include<stdio.h>
#include<limits.h>
#include<math.h>

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n],ind=0,sum,j,min=INT_MAX,max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(max<a[i])
				max=a[i];
		}
		//printf("%d\n",max);
		for(i=0;i<max;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				sum+=(int)fabs(i-a[j]);
			}
			if(min>sum)
			{	
				ind=i;
				
				min=sum;
			}
		}
		printf("%d %d\n",min,ind);
	}
	return 0;
}
