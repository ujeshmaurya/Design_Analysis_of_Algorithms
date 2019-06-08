// 0 - white
// 1 - black
// 5 - gray
#include<stdio.h>
int time=0;
int arr[100];
int flag=0;
int alr[100];
int flag1=0;
void dfsfors(int n,int u,int mat[][n],int color[])
{
	int i,z,flag2=1,flag3=1;
	color[u]=5;	
	for(i=0;i<n;i++)
	{
		if(mat[u][i]==1 && color[i]==0)
		{
		        for(z=0;z<flag1;z++)
	                        {
	                           if(alr[z]==i)
	                                {flag3=0;
	                                goto l1;}
	                        }
	                        if(flag3==1)
	                        {
	                                printf("%d ,",i);
	                                alr[flag1++]=i;
	                        }
			dfsfors(n,i,mat,color);
		}
	}
	l1:
	for(z=0;z<flag1;z++)
	{
	   if(alr[z]==u)
	        flag2=0;
	}
	if(flag2==1)
	{
	        printf("%d\n",u);
	        alr[flag1++]=u;
	}
	color[u]=1;
	time++;
}
void dfs(int n,int u,int mat[][n],int color[],int par[],int f[],int d[])
{
	int i;
	color[u]=5;	
	time++;
	d[u]=time;
	printf("Visit time-> %d\t%d\n",u,time);
	for(i=0;i<n;i++)
	{
			

		if(mat[u][i]==1&&color[i]==0)
		{
			par[i]=u;
			dfs(n,i,mat,color,par,d,f);
		}
	}
	color[u]=1;
	time++;
	printf("Finish time-> %d\t%d\n",u,time);
	f[u]=time;
	flag++;
}
void main()
{
	int i,n,j,u,count=0,z,flag4;
	 FILE *fp;
        fp=fopen("graph.txt","r");
        fscanf(fp,"%d ",&n);
        int mat[n][n],color[n],par[n],f[n],d[n],tmat[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d ",&mat[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		color[i]=0;
		par[i]=-1;
		d[i]=0;
		f[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(color[i]==0)
		dfs(n,i,mat,color,par,f,d);
	}
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        tmat[i][j]=mat[j][i];
                }
        }
        for(i=0;i<n;i++)
	{
		color[i]=0;
	}
        for(i=100;i>=0;i--)
        {
                for(j=0;j<n;j++)
                {
                        if(f[j]==i)
                        {
                                flag4=1;
                                for(z=0;z<flag1;z++)
	                        {
	                           if(alr[z]==j)
	                                flag4=0;
	                        }
	                        if(flag4!=1)
	                        {
	                                break;
	                        }
	                        printf("$\n");
                                dfsfors(n,j,tmat,color);
                                //printf("\n");
                                break;
                        }
                }
                
        }
	
}
