#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "subseq.h"


int main()
{
	char a[100],b[100],c[100];
	scanf("%s%s%s",a,b,c);
	int x=lcs3(a,b,c,strlen(a),strlen(b),strlen(c));
	return 0;
}
