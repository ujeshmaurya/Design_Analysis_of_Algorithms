#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sorting(int freq[],char chrlist[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(freq[j]<freq[j+1])
			{
				int temp=freq[j];
				freq[j]=freq[j+1];
				freq[j+1]=temp;
				
				char temp1=chrlist[j];
				chrlist[j]=chrlist[j+1];
				chrlist[j+1]=temp1;
			}
		}
	}
}
void divide(int freq[],int start,int end, char *code[])
{
	if(start==end || start+1==end)
		return;
	int i,j,s1=0,s2=0,min,mins=100000,dfact,k;
	for(i=start+1;i<end;i++)
	{
		s1=0;s2=0;
		for(j=start;j<i;j++)
		{
			s1+=freq[j];
		}
		for(k=j;k<end;k++)
		{
			s2+=freq[k];
		}
		dfact=s1-s2;
		if(dfact<0)
			dfact*=-1;
		if(dfact<mins)
		{
			mins=dfact;
			min=i;
		}
	}
	for(i=start;i<min;i++)
	{
		strcpy(code[i],strcat(code[i],"0"));	
	}
	for(i=min;i<end;i++)
	{
		strcpy(code[i],strcat(code[i],"1"));	
	}
	divide(freq,start,min,code);
	divide(freq,min,end,code);
}
int main()
{
	FILE *fp;
	FILE *fp2;
	fp2=fopen("outp.txt","w");
	fp=fopen("inp.txt","r");
	int n=0,i,j,ind=0;
	char ch;
	fscanf(fp,"%c ",&ch);
	while(fscanf(fp,"%c ",&ch)!=-1)
	{
		n++;
	}	
	n++;
	fclose(fp);
	fp=fopen("inp.txt","r");
	char *code[n];
	int freq[n];
	char chrlist[n];
	char chr[n];
	fscanf(fp,"%s",chrlist);
	for(i=0;i<n;i++)
	{
		freq[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<ind;j++)
		{
			if(chrlist[i]==chr[j])
				{
					freq[j]++;
					goto l1;
				}
		}
		chr[ind]=chrlist[i];
		freq[ind]++;
		ind++;
		l1:
		code[i]=(char *)malloc(20* sizeof(char));
	}
	chr[ind]='\0';
	sorting(freq,chr,ind);
	divide(freq,0,ind,code);
	for(i=0;i<ind;i++)
	{
		printf("%c--%s\n",chr[i],code[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<ind;j++)
		{
			if(chrlist[i]==chr[j])
			{
				fprintf(fp2,"%s",code[j]);
			}
		}
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
