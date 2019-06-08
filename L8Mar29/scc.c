#include<stdio.h>
#include<stdlib.h>
int a[100][100],at[100][100],n,e,time=0;;
struct node
{
	char name;
	int st;
	int et;
	int col;
};
struct node *v[100];


void tDFS(int con)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(at[con][i]==1&&v[i]->col==0)
		{
			time++;
			v[i]->st=time;
			v[i]->col=1;
			tDFS(i);
		}
		
	}
	v[con]->col=2;
	time++;
	v[con]->et=time;
	printf("%c\t%d\t%d\n",v[con]->name,v[con]->st,v[con]->et);
	
}
void tDFSu(int start)
{
	int i,j;
	for(i=start;i<n;i++)
	{
		if(v[i]->col==0)
		{
			printf("$%d\n",i);
			time++;
			v[i]->st=time;
			v[i]->col=1;
			tDFS(i);
		}
	}
}


void DFS(int con)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(a[con][i]==1&&v[i]->col==0)
		{
			time++;
			v[i]->st=time;
			v[i]->col=1;
			DFS(i);
		}
		
	}
	v[con]->col=2;
	time++;
	v[con]->et=time;
	printf("%c\t%d\t%d\n",v[con]->name,v[con]->st,v[con]->et);
	
}
void DFSu(int start)
{
	int i,j;
	for(i=start;i<n;i++)
	{
		if(v[i]->col==0)
		{
			time++;
			v[i]->st=time;
			v[i]->col=1;
			DFS(i);
		}
	}
}
int main()
{
	int i,j,k,l,m;
	scanf("%d %d",&n,&e);
	for(i=0;i<n;i++)
	{
		char c[2];
		scanf("%s",c);
		v[i]=(struct node*)malloc(sizeof(struct node));
		v[i]->name=c[0];
		v[i]->st=0;
		v[i]->et=0;
		v[i]->col=0;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0,at[i][j]=0;
	for(i=0;i<e;i++)
	{
		int c,d;
		scanf("%d %d",&c,&d);
		a[c-1][d-1]=1;
		at[d-1][c-1]=1;
	}
	DFSu(0);
	printf("\n");
	for(i=0;i<n;i++)
	{
		v[i]->st=0;
		v[i]->et=0;
		v[i]->col=0;
	}
	time=0;
	tDFSu(0);
	return 0;
}
