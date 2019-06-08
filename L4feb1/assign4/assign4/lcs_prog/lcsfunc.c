#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int lcs3( char X[], char Y[], char Z[], int m,int n, int o)
{
    int L[m+1][n+1][o+1];
 
    int i,j,k;
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            for (k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],L[i][j-1][k]),L[i][j][k-1]);
            }
        }
    }
 	i=m;
 	j=n;
 	k=o;
 	char a[100];
 	int ind=0;
 	while(i>0&&j>0&&k>0)
 	{
 		int x=L[i][j][k];
 		if(x==L[i-1][j][k])
 			i-=1;
		else if(x==L[i][j-1][k])
			j-=1;
		else if(x==L[i][j][k-1])
			k-=1;
		else
		{
			a[ind++]=X[i-1];
			i-=1;
			j-=1;
			k-=1;
		}
 	}
    a[ind]='\0';
    for(i=ind-1;i>=0;i--)
    	printf("%c",a[i]);
	printf("\n");
    return L[m][n][o];
}
