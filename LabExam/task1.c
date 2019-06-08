#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n][4],i;
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=0;i<n;i++)
	{
		int j,maxcount=0,val;
		for(j=a[i][0];j<=a[i][1];j++)
		{
			int count=1,m=j;
			while(m!=1)
			{
				if(m%2==0)
					m/=2;
				else
					m=(m*3)+1;
				count++;
			}
			if(count>maxcount)
			{	maxcount=count; val=j;	}
		}
		a[i][2]=maxcount;
		a[i][3]=val;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][3]);
	}
	return 0;
}

