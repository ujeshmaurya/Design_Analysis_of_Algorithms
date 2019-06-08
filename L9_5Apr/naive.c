#include<stdio.h>
#include<string.h>

 void LPScalc(char b[], int m, int lps[])
{
    lps[0]=0;
    int i=1,len=0;
    while (i<m)
    {
        if (b[i]==b[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else 
        {
            if (len!=0)
            {
                len=lps[len-1];
            }
            else 
            {
                lps[i]=0;
                i++;
            }
        }
    }
    printf("LPS Array:\n");
    for(i=0;i<m;i++)
    	printf("%d ",lps[i]);
	printf("\n");
}

void KMP(char b[], char a[])
{
    int m=strlen(b),n=strlen(a);
 
    
    int lps[m];
    LPScalc(b, m, lps);
    int i=0,j=0; 
    while (i<n)
    {
        if(b[j]==a[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            printf("Pattern found index %d \n", i-j);
            j=lps[j-1];
        }
        else if(i<n&&b[j]!=a[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
}
void naive(char b[], char a[])
{
    int n=strlen(a),m=strlen(b),i;
  
    for ( i=0;i<=n-m;i++)
    {
        int j;
        for (j=0;j<m;j++)
            if (a[i+j]!=b[j])
                break;
 
        if (j==m)  
           printf("Pattern found at  %d\n", i);
    }
}
int main()
{
   char a[1000],b[100];
   scanf("%s%s",b,a);
   printf("%s\n%s\n",b,a);
   printf("Naive Approach:\n");
   naive(b,a);
   KMP(b,a);
   return 0;
}
