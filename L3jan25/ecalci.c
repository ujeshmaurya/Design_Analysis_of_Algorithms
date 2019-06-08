#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char base[100];	//lookup table
int maxb;	//max base supported in current execution
struct number
{
	int bs;
	int len;
	char num[100];
};
typedef struct number number;
void createCalciBase(int n)	//create max 62 base system
{
	int i,j=48;
	for(i=0;i<n;i++)
	{
		base[i]=j++;
		if(j==58)
			j=65;
		if(j==91)
			j=97;
	}
	/*for(i=0;i<n;i++)
		printf("%c ",base[i]);
	printf("\n");*/
}

int calciLookup(char c)	 //return the value of char c by checking it in current look up table
{
	int i;
	for(i=0;i<maxb;i++)
		if(c==base[i])
			return i;
	return -1;
}
int initializeCalciBase(FILE *basefile)	//read 1st file and populate look up table upto maxD (given by file)
{
	char a[300];
	int i,count=0;
	fscanf(basefile," %[^\n]s",a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='\0')
			break;
		if(a[i]!=' ')
			base[count++]=a[i];
	}
	/*for(i=0;i<count;i++)
		printf("%c ",base[i]);
	printf("\n");*/
	return count;
}
number createCalciNumber(char a[])	//create a "number" from given base and number in a string
{
	number n;
	int i=0,j=0;
	char b[20];
	while(a[i]!=' ')
		b[i]=a[i++];
	b[i]='\0';
	n.bs=atol(b);
	i++;
	for(	;i<strlen(a);i++)
	{
		b[j++]=a[i];
	}
	b[j]='\0';
	strcpy(n.num,b);
	n.len=strlen(b);
	return n;
}
int base10convfb(number n)	//convert a base 'b' no. to base 10 no.
{
	int i,x=0,p=0;
	for(i=n.len-1;i>=0;i--)
	{
		x=x+calciLookup(n.num[i])*pow(n.bs,p++);
	}
	return x;
}
number basebconvf10(int x,int b)	//convert a base 10 no. to a base 'b' no.
{
	number n;
	int i=0,j;
	char ba[50];
	while(x!=0)
	{
		ba[i++]=base[x%b];
		x/=b;
	}
	ba[i]='\0';
	//printf("$%s$\n",ba);
	int k=i-1;
	for(j=0;j<i;j++)
		n.num[j]=ba[k--];
	n.num[j]='\0';
	n.len=strlen(n.num);
	n.bs=b;
	return n;
}
number sum(number a,number b)	//adds two diff numbers
{
	int x=base10convfb(a);
	int y=base10convfb(b);
	if(a.bs>b.bs)
	{
		return basebconvf10(x+y,a.bs);
	}
	else
	{
		return basebconvf10(x+y,b.bs);
	}
}
number minus(number a,number b)	//subtracts two different numbers
{
	int x=base10convfb(a);
	int y=base10convfb(b);
	if(a.bs>b.bs)
	{
		return basebconvf10(x-y,a.bs);
	}
	else
	{
		return basebconvf10(x-y,b.bs);
	}
}
void printnumber(number n)
{
	printf("%s(%d)",n.num,n.bs);
}
int main(int argc, char* argv[])
{
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r");
	createCalciBase(62);
	maxb=initializeCalciBase(fp1);	//max base got initialised and look up table got populated according to file1 input
	char c=getc(fp2);
	while(c!=EOF)
	{
		fseek(fp2,-1,SEEK_CUR);
		char command[10];
		fscanf(fp2,"%s",command);
		number n1,n2;
		fscanf(fp2,"%d%s%d%s",&n1.bs,n1.num,&n2.bs,n2.num);
		n1.len=strlen(n1.num);
		n2.len=strlen(n2.num);
		if(strcmp(command,"sum")==0)
		{
			printnumber(n1);
			printf(" + ");
			printnumber(n2);
			printf(" = ");
			printnumber(sum(n1,n2));
			printf("\n");
		}
		else if(strcmp(command,"minus")==0)
		{
			printnumber(n1);
			printf(" - ");
			printnumber(n2);
			printf(" = ");
			printnumber(minus(n1,n2));
			printf("\n");
		}
		c=getc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
