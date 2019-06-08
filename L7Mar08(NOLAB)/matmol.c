
#include<stdio.h>
int mtx[8][8];
void mat(int col)
{
	int i,k,temp,idx=1,j;
	if(col>=8)
		return;
	while(idx)
	{	
		for(i=0;i<8;i++)
		{
			if(mtx[i][col]==1)
			{
				for(k=0;k<8;k++)
					mtx[i][k]*=2;
			}
		}
	
		temp=mtx[0][col];
		for(i=1;i<8;i++)
		{
			if(mtx[i][col]<temp)
			{
				temp=mtx[i][col];
			}
		}
		for(i=0;i<8;i++)
			mtx[i][col]-=(temp-1);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%d ",mtx[i][j]);
		printf("\n");
	}
	printf("\n");
		for(i=0;i<8;i++)
			if(mtx[i][col]!=1)
				break;
			
		if(i==8)
			idx=0;
	}
	mat(col+1);
}

void main()
{
	
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			scanf("%d",&mtx[i][j]);
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%d ",mtx[i][j]);
		printf("\n");
	}
	printf("\n");
	mat(0);
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(mtx[i][j]==1)
				mtx[i][j]=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%d ",mtx[i][j]);
		printf("\n");
	}
}
