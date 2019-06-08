#include<stdio.h>


int NP(int W, int weight[], int profit[], int n)
{
   int table[n+1][W+1],i,w,took[n+1][W+1];
   for(i=0;i<=n;i++)
   {
       for(w=0;w<=W;w++)
       {
           if(i==0||w==0)
                table[i][w]=0,took[i][w]=0;
           else if(weight[i-1]<=w)
           {
                if(profit[i-1]+table[i-1][w-weight[i-1]]>table[i-1][w])
                {
                	table[i][w]=profit[i-1]+table[i-1][w-weight[i-1]];
                	//printf("%d ",i);
                	took[i][w]=1;
                }
                else
                {
                	table[i][w]=table[i-1][w];
                	took[i][w]=0;
                }
           }
           else
                table[i][w]=table[i-1][w],took[i][w]=0;
       }
       //printf("\n");
   }
   int j;
    for(i=0;i<=n;i++)
   	{
   		for(j=0;j<=W;j++)
   			printf("%d ",table[i][j]);
		printf("\n");
   	}
   	i=n;
   	j=W;
   	printf("Items Taken:-> \n");
   	while(i>0&&j>0)
   	{
   		if(table[i][j]==table[i-1][j])
   		{
   			
   			i--;
   		}
   		else
   		{
   			printf("%d %d %d\n",i,weight[i-1],profit[i-1]);
   			j-=weight[i-1];
   		}
   	}
   	printf("\n");
   return table[n][W];
}
 
int main()
{
	int n,w;
    scanf("%d%d",&n,&w);
    int a[n],i,profit[n];
    for(i=0;i<n;i++)
    	scanf("%d %d",&a[i],&profit[i]);
    printf("Maximum profit taken: %d\n",NP(w,a,profit,n));
    return 0;
}
