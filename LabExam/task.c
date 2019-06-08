#include<stdio.h>
#include<string.h>
#include<stdio.h>
int check(int a[],int n)
{
	int i,one=0,flag=1,f=1;
	for(i=0;i<n;i++)
	{
		if(a[i]==0&&one==0)
			one=1;
		if(one==1&&a[i]==1)
		{
			flag=0;
			break;
		}
	}
	
	return flag;
}
int check2(int a[],int n)
{
	int i;
	int	one=0,flag=1;
		for(i=0;i<n;i++)
		{
			if(a[i]==1&&one==0)
				one=1;
			if(one==1&&a[i]==0)
			{
				flag=0;
				break;
			}
		}
	
	//printf("flag=%d\n",flag);
	return flag;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,a[n],pos1,pos0=-1,j,k,b[n],count0=0,count1=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		if(pos0==-1&&a[i]==0)
			pos0=i;
	}
	while(1)
	{
		if(check(a,n)==1)
			break;
		for(i=pos0;i<n;i++)
		{
			if(a[i]==0)
				continue;
			else 
				break;
		}
		
		j=i;
		
		for(i=j-1;i>=pos0;i--)
		{
			for(k=0;k<n;k++)
			{
				if(k!=i&&k!=j)
				printf("%d ",a[k]);
				else if(k==i)
				printf("1 ");
				else if(k==j)
				printf("0 ");
			}
			printf("\n");
			count0++;
		}
		a[pos0]=1;
		a[j]=0;
		for(i=pos0+1;i<n;i++)
		{
			if(a[i]==0)
			{
				pos0=i;
				break;
			}
		}
	}
	printf("\nNo. of steps=%d\n\n",count0);
	printf("\nOther way round\n");
	for(i=0;i<n;i++)
		a[i]=b[i];
	for(i=0;i<n;i++)
		if(a[i]==1)
		{	pos0=i;	break;	}
	while(1)
	{
		if(check2(a,n)==1)
			break;
		for(i=pos0;i<n;i++)
		{
			if(a[i]==1)
				continue;
			else 
				break;
		}
		
		j=i;
		
		for(i=j-1;i>=pos0;i--)
		{
			for(k=0;k<n;k++)
			{
				if(k!=i&&k!=j)
				printf("%d ",a[k]);
				else if(k==i)
				printf("0 ");
				else if(k==j)
				printf("1 ");
			}
			printf("\n");
			count1++;
		}
		a[pos0]=0;
		a[j]=1;
		for(i=pos0+1;i<n;i++)
		{
			if(a[i]==1)
			{
				pos0=i;
				break;
			}
		}
	}
	printf("\nNo. of steps=%d\n\n",count1);
	
	return 0;
}
