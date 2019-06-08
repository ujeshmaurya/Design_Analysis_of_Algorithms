#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    unsigned int size = pow(2, n),j,k;
    int a[size][n],indi=0,max=0,*b,*c;
    b=(int*)calloc(size,sizeof(int));
    c=(int*)calloc(size,sizeof(int));
    for (i= 1; i < size; i++)
    {
        int indj=0;
        for (j = 0; j < n; j++)
        {
            if (i & (1<<j))
            {
                if(indj==0)
                    a[indi][indj++]=arr[j];
                else if(a[indi][indj-1]<arr[j])
                    a[indi][indj++]=arr[j];
            }
        }
        a[indi][indj]=INT_MAX;
        indi++;
        if(indj>max)
        {    max=indj;  }
    }
    for(i=0;i<indi;i++)
    {
        if(b[i]==1)
            continue;
        for(k=i+1;k<indi;k++)
        {
            j=0;
            int flag=0;
            while(a[i][j]!=INT_MAX)
            {
                if(a[i][j]!=a[k][j])
                {
                    flag=1;
                    break;
                }
                j++;
            }
            if(flag==0&&a[i][j]==a[k][j])
             {     b[k]=1;    }
        }
    }
    printf("All Possible strictly increasing subsequences are:\n");
    int indc=0,count=0;
    for(i=0;i<indi;i++)
    {
        j=0;
        if(b[i]==0)
        {
            count++;
            while(a[i][j]!=INT_MAX)
            {
                printf("%d ",a[i][j++]);
            }
            printf("\n");
            if(j==max)
                c[indc++]=i;
        }
    }
    printf("Total no. of possible increasing subsequences are: %d\n",count);
    printf("Length of longest increasing subsequence is: %d\n",max);
    printf("Those longest subsequences are:\n");
    for(i=0;i<indc;i++)
    {
        j=c[i];
        k=0;
        while(a[j][k]!=INT_MAX)
        {
            printf("%d ",a[j][k++]);
        }
        printf("\n");
    }
    return 0;
}
