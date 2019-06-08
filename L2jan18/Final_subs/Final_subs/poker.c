#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int convert(char a)
{
	if(a>=48&&a<=57)
		return a-48;
	else if(a=='T')
		return 10;
	else if(a=='J')
		return 11;
	else if(a=='Q')
		return 12;
	else if(a=='K')
		return 13;
	else if(a=='A')
		return 14;
	else
		return 0;
}
int main()
{
	char a[100],w[50],b[50];
	scanf(" %[^\n]s",a);
	int i,k=0,hbc=0,hwc=0,j;
	for(i=0;i<strlen(a);i++)
		if(a[i]!=' ')
			a[k++]=a[i];
	a[k]='\0';
	for(i=0,k=0;i<strlen(a)/2;i++)
		b[k++]=a[i];
	b[k]='\0';
	for(k=0;i<strlen(a);i++)
		w[k++]=a[i];
	w[k]='\0';
	for(i=0;i<strlen(b);i+=2)
		if(hbc<convert(b[i]))
			hbc=convert(b[i]);
	for(i=0;i<strlen(w);i+=2)
		if(hwc<convert(w[i]))
			hwc=convert(w[i]);
	//straight flush condition check start
	{
		int sfw=0,sfb=0,tie=0,flag=1;
		//check sf for black
		char bs=b[1];
		for(i=3;i<strlen(b);i+=2)
			if(b[i]!=bs)
			{	flag=0;	break;	}
		if(flag==0)
			sfb=0;
		else
		{
			int c=convert(b[0]),bflag=1;
			c++;
			for(i=2;i<strlen(b);i+=2)
			{
				if(convert(b[i])!=c++)
				{	bflag=0;	break;	}
				
			}
			if(bflag==1)
				sfb=1;
			else
				sfb=0;
		}
		//check sf for white
		flag=1;
		char ws=w[1];
		for(i=3;i<strlen(w);i+=2)
			if(w[i]!=ws)
			{	flag=0;	break;	}
		if(flag==0)
			sfw=0;
		else
		{
			int c=convert(w[0]),wflag=1;
			c++;
			for(i=2;i<strlen(w);i+=2)
			{
				if(convert(w[i])!=c++)
				{	wflag=0;	break;	}
				
			}
			if(wflag==1)
				sfw=1;
			else
				sfw=0;
		}
		//decide winner
		if(sfw==1 && sfb==0)
		{	printf("White wins!!\n");printf("1\n");	return 0;	}
		else if(sfw==0 && sfb==1)
		{	printf("Black wins!!\n");printf("1\n");	return 0;	}
		else if(sfw==1 && sfb==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("1\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("1\n");	return 0;	}
			else
			{	printf("Tie!!\n");printf("1\n");	return 0;	}
		}
	}//straight flush finish
	//four of a kind check start
	{
		int ffkw=0,ffkb=0,flag=1,count=0,ind;
		//check ffk for black
		int c=convert(b[0]);
		for(i=0;i<strlen(b);i+=2)
		{
			if(c==convert(b[i]))
			{	count++;	ind=i;	}
		}
		if(count<4)
		{
			c=convert(b[2]);
			count=0;
			ind=0;
			for(i=2;i<strlen(b);i+=2)
			{
				if(c==convert(b[i]))
				{	count++;	ind=i;	}
			}
			if(count<4)
				ffkb=0;
		}
		else
		{
			ffkb=1;
			hbc=convert(b[ind]);
		}
		//check ffk for white
		c=convert(w[0]);
		flag=1;
		count=0;
		ind=0;
		for(i=0;i<strlen(w);i+=2)
		{
			if(c==convert(w[i]))
			{	count++;	ind=i;	}
		}
		if(count<4)
		{
			c=convert(w[2]);
			count=0;
			ind=0;
			for(i=2;i<strlen(w);i+=2)
			{
				if(c==convert(w[i]))
				{	count++;	ind=i;	}
			}
			if(count<4)
				ffkw=0;
		}
		else
		{
			ffkw=1;
			hwc=convert(w[ind]);	
		}
		//decide winner
		if(ffkb==1 &&ffkw==0)
		{	printf("Black wins!!\n");printf("2\n");	return 0;	}
		else if(ffkb==0 && ffkw==1)
		{	printf("White wins!!\n");printf("2\n");	return 0;	} 
		else if(ffkb==1 && ffkw==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("2\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("2\n");	return 0;	}
			else
			{	printf("Tie!!\n");printf("2\n");	return 0;	}
		}
	}//four of a kind check finish
	
	//full house check start
	{
		int fhw=0,fhb=0,flag=0,l,sb[2],ind=0;
		//check fh for black
		for(i=0;i<strlen(b);i+=2)
		{
			for(j=i+2;j<strlen(b);j+=2)
			{
				for(k=j+2;k<strlen(b);k+=2)
					if(convert(b[i])==convert(b[j])&&convert(b[j])==convert(b[k]))
					{
						flag=1;
						break;
					}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			hbc=convert(b[i]);
			for(l=0;l<strlen(b);l+=2)
				if(l!=i && l!=j && l!=k)
					sb[ind++]=convert(b[l]);
			if(sb[0]==sb[1])
				fhb=1;
		}
		else
			fhb=0;
		//check fh for white
		ind=flag=0;
		for(i=0;i<strlen(w);i+=2)
		{
			for(j=i+2;j<strlen(w);j+=2)
			{
				for(k=j+2;k<strlen(w);k+=2)
					if(convert(w[i])==convert(w[j])&&convert(w[j])==convert(w[k]))
					{
						flag=1;
						break;
					}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			hwc=convert(w[i]);
			for(l=0;l<strlen(w);l+=2)
				if(l!=i && l!=j && l!=k)
					sb[ind++]=convert(w[l]);
			if(sb[0]==sb[1])
				fhw=1;
		}
		else
			fhw=0;
		//decide winner
		if(fhb==1 &&fhw==0)
		{	printf("Black wins!!\n");printf("3\n");	return 0;	}
		else if(fhb==0 && fhw==1)
		{	printf("White wins!!\n");printf("3\n");	return 0;	} 
		else if(fhb==1 && fhw==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("3\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("3\n");	return 0;	}
			else
			{	printf("Tie!!\n");printf("3\n");	return 0;	}
		}
	}
	//fh check finish
	
	//flush check start
	{
		int fb=0,fw=0,flag=1;
		//flush for black
		char bs=b[1];
		for(i=3;i<strlen(b);i+=2)
			if(b[i]!=bs)
			{	flag=0;	break;	}
		if(flag==0)
			fb=0;
		else
		{
			fb=1;
			hbc=0;
			for(i=0;i<strlen(b);i+=2)
				if(hbc<convert(b[i]))
					hbc=convert(b[i]);
		}
		//flush for white
		flag=1;
		char ws=w[1];
		for(i=3;i<strlen(w);i+=2)
			if(w[i]!=ws)
			{	flag=0;	break;	}
		if(flag==0)
			fw=0;
		else
		{
			fw=1;
			hwc=0;
			for(i=0;i<strlen(w);i+=2)
				if(hwc<convert(w[i]))
					hwc=convert(w[i]);
		}
		//decide winner
		if(fb==1 &&fw==0)
		{	printf("Black wins!!\n");	printf("4\n");return 0;	}
		else if(fb==0 && fw==1)
		{	printf("White wins!!\n");printf("4\n");	return 0;	} 
		else if(fb==1 && fw==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("4\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("4\n");	return 0;	}
			else
			{	printf("Tie!!\n");printf("4\n");	return 0;	}
		}
	}//flush check finish
	
	//straight check starts
	{
		int stb=0,stw=0,flag=1;
		//check straight for black
		int c=convert(b[0]),bflag=1;
		c++;
		for(i=2;i<strlen(b);i+=2)
		{
			if(convert(b[i])!=c++)
			{	bflag=0;	break;	}
			
		}
		if(bflag==1)
		{
			stb=1;
			hbc=0;
			for(i=0;i<strlen(b);i+=2)
				if(hbc<convert(b[i]))
					hbc=convert(b[i]);
		}
		else
			stb=0;
		//check straight for white
		c=convert(w[0]);
		int wflag=1;
		c++;
		for(i=2;i<strlen(w);i+=2)
		{
			if(convert(w[i])!=c++)
			{	wflag=0;	break;	}
			
		}
		if(wflag==1)
		{
			stw=1;
			hwc=0;
			for(i=0;i<strlen(w);i+=2)
				if(hwc<convert(w[i]))
					hwc=convert(w[i]);
		}
		else
			stw=0;
		//decide winner
		if(stb==1 && stw==0)
		{	printf("Black wins!!\n");printf("5\n");	return 0;	}
		else if(stb==0 && stw==1)
		{	printf("White wins!!\n");printf("5\n");	return 0;	} 
		else if(stb==1 && stw==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("5\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("5\n");	return 0;	}
			else
			{	printf("Tie!!\n");printf("5\n");	return 0;	}
		}
	}//straight check finishes
	
	//three of a kind check start
	{
		int tokw=0,tokb=0,flag=0;
		//tofk for black
		for(i=0;i<strlen(b);i+=2)
		{
			for(j=i+2;j<strlen(b);j+=2)
			{
				for(k=j+2;k<strlen(b);k+=2)
					if(convert(b[i])==convert(b[j])&&convert(b[j])==convert(b[k]))
					{
						flag=1;
						break;
					}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			tokb=0;
		else
		{
			tokb=1;
			hbc=convert(b[i]);
		}
		//tofk for white
		flag=0;
		for(i=0;i<strlen(w);i+=2)
		{
			for(j=i+2;j<strlen(w);j+=2)
			{
				for(k=j+2;k<strlen(w);k+=2)
					if(convert(w[i])==convert(w[j])&&convert(w[j])==convert(w[k]))
					{
						flag=1;
						break;
					}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			tokw=0;
		else
		{
			tokw=1;
			hwc=convert(w[i]);
		}
		//decide winner
		if(tokb==1 && tokw==0)
		{	printf("Black wins!!\n");printf("6\n");	return 0;	}
		else if(tokb==0 && tokw==1)
		{	printf("White wins!!\n");printf("6\n");	return 0;	} 
		else if(tokb==1 && tokw==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("6\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("6\n");	return 0;	}
			else
			{	printf("Tie!!\n");printf("6\n");	return 0;	}
		}
	}//three of a kind check finishes
	
	//two pairs check start
	{
		int tpb=0,tpw=0,flag=0,l,bp1,bp2,wp1,wp2,rb,rw;
		//tp for black
		for(i=0;i<strlen(b);i+=2)
		{
			for(j=i+2;j<strlen(b);j+=2)
				if(convert(b[i])==convert(b[j]))
				{	flag=1;	break;	}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			int lflag=0;
			for(k=0;k<strlen(b);k+=2)
			{
				for(l=k+2;l<strlen(b);l+=2)
				{
					if(k!=i && k!=j && l!=i && l!=j && convert(b[k])==convert(b[l]))
					{	lflag=1; break;	}
				}
				if(lflag==1)
					break;
			}
			if(lflag==1)
			{
				tpb=1;
				int en,rflag=0;
				for(en=0;en<strlen(b);en+=2)
					if(en!=i && en!=j && en!=k && en!=l)
					{	rb=convert(b[en]);	break;	}
				if(convert(b[i])>convert(b[k]))
				{	bp1=convert(b[i]);	bp2=convert(b[k]);	}
				else
				{	bp2=convert(b[i]);	bp1=convert(b[k]);	}
			}
			else
				tpb=0;
		}
		else
			tpb=0;
		//tpb for white
		flag=0;
		for(i=0;i<strlen(w);i+=2)
		{
			for(j=i+2;j<strlen(w);j+=2)
				if(convert(w[i])==convert(w[j]))
				{	flag=1;	break;	}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			int lflag=0;
			for(k=0;k<strlen(w);k+=2)
			{
				for(l=k+2;l<strlen(w);l+=2)
				{
					if(k!=i && k!=j && l!=i && l!=j && convert(w[k])==convert(w[l]))
					{	lflag=1; break;	}
				}
				if(lflag==1)
					break;
			}
			if(lflag==1)
			{
				tpw=1;
				int en,rflag=0;
				for(en=0;en<strlen(w);en+=2)
					if(en!=i && en!=j && en!=k && en!=l)
					{	rw=convert(w[en]);	break;	}
				if(convert(w[i])>convert(w[k]))
				{	wp1=convert(w[i]);	wp2=convert(w[k]);	}
				else
				{	wp2=convert(w[i]);	wp1=convert(w[k]);	}
			}
			else
				tpw=0;
		}
		else
			tpw=0;
		//decide winner
		if(tpb==1 && tpw==0)
		{	printf("Black wins!!\n");printf("7\n");	return 0;	}
		else if(tpb==0 && tpw==1)
		{	printf("White wins!!\n");printf("7\n");	return 0;	} 
		else if(tpb==1 && tpw==1)
		{
			if(wp1>bp1)
			{	printf("White wins!!\n");printf("7\n");	return 0;	}
			else if(wp1<bp1)
			{	printf("Black wins!!\n");printf("7\n");	return 0;	}
			else if(wp1==bp1)
			{
				if(wp2>bp2)
				{	printf("White wins!!\n");printf("7\n");	return 0;	}
				else if(wp2<bp2)
				{	printf("Black wins!!\n");printf("7\n");	return 0;	}
				else if(wp2==bp2)
				{
					if(rw>rb)
					{	printf("White wins!!\n");printf("7\n");	return 0;	}
					else if(rw<rb)
					{	printf("Black wins!!\n");printf("7\n");	return 0;	}
					else if(rw==rb)
					{	printf("Tie!!\n");printf("7\n");	return 0;	}
				}
			}
		}
	}// two pair check finishes
	
	//pair check starts
	{
		int pb=0,pw=0,flag=0,b1[3],ind=0,b2[3];
		// pair for black
		for(i=0;i<strlen(b);i+=2)
		{
			for(j=i+2;j<strlen(b);j+=2)
				if(convert(b[i])==convert(b[j]))
				{	flag=1;	break;	}
			if(flag==1)
				break;
		}
		if(flag==0)
			pb=0;
		else
		{
			hbc=convert(b[i]);
			pb=1;
			for(k=0;k<strlen(b);k+=2)
			{
				if(k!=i && k!=j)
					b1[ind++]=convert(b[k]);
			}
			qsort(b1,3,sizeof(int),cmpfunc);
		}
		//pair for white
		ind=0;
		flag=0;
		for(i=0;i<strlen(w);i+=2)
		{
			for(j=i+2;j<strlen(w);j+=2)
				if(convert(w[i])==convert(w[j]))
				{	flag=1;	break;	}
			if(flag==1)
				break;
		}
		if(flag==0)
			pw=0;
		else
		{
			hwc=convert(w[i]);
			pw=1;
			for(k=0;k<strlen(w);k+=2)
			{
				if(k!=i && k!=j)
					b2[ind++]=convert(w[k]);
			}
			qsort(b2,3,sizeof(int),cmpfunc);
		}
		//decide winner
		if(pb==1 && pw==0)
		{	printf("Black wins!!\n");printf("8\n");	return 0;	}
		else if(pb==0 && pw==1)
		{	printf("White wins!!\n");printf("8\n");	return 0;	} 
		else if(pb==1 && pw==1)
		{
			if(hwc>hbc)
			{	printf("White wins!!\n");printf("8\n");	return 0;	}
			else if(hwc<hbc)
			{	printf("Black wins!!\n");printf("8\n");	return 0;	}
			else if(hwc==hbc)
			{	
				if(b1[2]>b2[2])
				{	printf("Black wins!!\n");printf("8\n");	return 0;	}
				else if(b1[2]<b2[2])
				{	printf("White wins!!\n");printf("8\n");	return 0;	}
				else
				{
					if(b1[1]>b2[1])
					{	printf("Black wins!!\n");printf("8\n");	return 0;	}
					else if(b1[1]<b2[1])
					{	printf("White wins!!\n");printf("8\n");	return 0;	}
					else
					{
						if(b1[0]>b2[0])
						{	printf("Black wins!!\n");printf("8\n");	return 0;	}
						else if(b1[0]<b2[0])
						{	printf("White wins!!\n");printf("8\n");	return 0;	}
						else
						{	printf("Tie!!\n");	printf("8\n");return 0;	}
					}
				}
			}
		}
	}//pair check finishes
	
	//high card check starts
	{
		int hhb=0,hhw=0,b1[5],b2[5],ind=0;
		//hhc for black
		for(i=0;i<strlen(b);i+=2)
			b1[ind++]=convert(b[i]);
		qsort(b1,5,sizeof(int),cmpfunc);
		//hhc for white
		ind=0;
		for(i=0;i<strlen(w);i+=2)
			b2[ind++]=convert(w[i]);
		qsort(b2,5,sizeof(int),cmpfunc);
		//decide winner
		for(i=4;i>=0;i--)
		{
			//printf("%d %d\n",b1[i],b2[i]);
			if(b1[i]>b2[i])
			{	hhb=1; break;	}
			else if(b2[i]>b1[i])
			{	hhw=1;	break;	}
			else
				continue;
		}
		if(hhb==1 && hhw==0)
		{	printf("Black wins!!\n");	printf("9\n");return 0;	}
		else if(hhb==0 && hhw==1)
		{	printf("White wins!!\n");printf("9\n");	return 0;	} 
		else if(hhb==0 && hhw==0)
		{	printf("Tie!!\n");	printf("9\n");return 0;	}
	}
	
	
	return 0;
}
