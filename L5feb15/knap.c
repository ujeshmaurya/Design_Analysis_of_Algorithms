#include<stdio.h>
#include<stdlib.h>

int main()
{
 	int n,c,j;
 	scanf("%d %d",&n,&c);
 	int p[n],w[n],i;
 	for(i=0;i<n;i++)
 		scanf("%d",&p[i]);
	for(i=0;i<n;i++)
 		scanf("%d",&w[i]);
	float a[n];
	for(i=0;i<n;i++)
		a[i]=(float)p[i]/w[i];
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				float t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				int temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
		
	//mergeSort(a,0,n-1);
	printf("Price/Weight Ratio:\n");
	for(i=0;i<n;i++)
		printf("%d / %d = %.2f\n",p[i],w[i],a[i]);
	printf("\n");
	float tp=0;
	printf("Price\tWeight\tfraction\tP/W ratio\tCapacity\n");
	for(i=0;i<n;i++)
	{
		if(c-w[i]>=0)
		{
			c-=w[i];
			tp+=p[i];
			printf("%d\t%d\t1.00\t\t%.2f\t\t%d\n",p[i],w[i],a[i],c);
		}
		else
			break;
	}
	if(i!=n)
	{
		float t=(float)c/w[i];
		tp+=t*p[i];
		printf("%d\t%d\t%.2f\t\t%.2f\t\t0\n",p[i],w[i],t,a[i]);
	}
	i++;
	for(;i<n;i++)
	{
			printf("%d\t%d\t0.00\t\t%.2f\t\t0\n",p[i],w[i],a[i]);
	}
	printf("Final profit= %.2f\n",tp);
 	return 0;
 }
