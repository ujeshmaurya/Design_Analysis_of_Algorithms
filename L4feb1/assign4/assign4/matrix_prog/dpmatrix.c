#include<stdio.h>
#include<limits.h>
void recusrsive_print(int i, int j, int n,int *bracket, int* id)
{
    if (i == j)
    {
       printf("%d",*id);
       *id+=1;
        return;
    }
    printf("(");
    recusrsive_print(i, *((bracket+i*n)+j), n, bracket, id);
    recusrsive_print(*((bracket+i*n)+j) + 1, j,n, bracket, id);
    printf(")");
}

void dp_order(int p[], int n)
{
    int m[n][n];
    int bracket[n][n],i,L,k;
    for (i=1; i<n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    int id=1;
    printf("Optimal Parenthesization is : ");
    recusrsive_print(1, n-1, n, (int *)bracket, &id);
    printf("\nOptimal Cost is : %d\n", m[1][n-1]);
}
