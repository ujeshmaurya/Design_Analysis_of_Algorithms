#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
char table[1000][1000];
int ind=0;
struct node
{
    int freq;
    char sign;

};
struct treenode 
{
    int data;
    char si;
    struct treenode *left;
    struct treenode *right;
};
 

struct treenode* newtreenode(int data,char c)
{

  struct treenode* treenode = (struct treenode*)malloc(sizeof(struct treenode));
	treenode->si=c;
  treenode->data = data;
  treenode->left = NULL;
  treenode->right = NULL;
  return(treenode);
}
char struse[1000];
int ih=0;
char traversed[1000];
int it=0;
void printInorder(struct treenode* node)
{
     if (node == NULL)
     {
          return;
   		}
 	
    struse[ih++]='0';
    struse[ih]='\0';
    //printf("%s\n",struse);
     printInorder(node->left);
 

     struse[ih-1]='\0';
     if(node->si!='$')
     {
     	strcpy(table[ind++],struse);
     	traversed[it++]=node->si;
 	}
 
	ih--;
	struse[ih++]='1';
	struse[ih]='\0';
	//printf("%s\n",struse);
     printInorder(node->right);
     
     ih--;  
     struse[ih]='\0';
     return;
   		
}
int main(void) {
	int n,i,j,k,l;
	char a[10000];
	scanf(" %[^\n]s",a);
    l=strlen(a);
    //bubble sorting of string
    for(i=0;i<l;i++)
    	for(j=0;j<l-i-1;j++)
    	if(a[j]>a[j+1])
    	{
    		char temp=a[j];
    		a[j]=a[j+1];
    		a[j+1]=temp;
    	}

	struct node *c;
	c=(struct node*)malloc(256*sizeof(struct node));
	j=1;
	for(i=0;i<l;i++)
	{
		if(i!=0)
			j++;
		c[j-1].sign=a[i];
		c[j-1].freq=0;
		while(a[i]==c[j-1].sign)
		{
			c[j-1].freq++;
			i++;
		}
		i--;
	}
	//c=(struct node*)realloc(c,j);
	int no=j,cumsum=0;
	//bubble sorting of frequencies
	for(i=0;i<no;i++)
    	for(j=0;j<no-i-1;j++)
    	if(c[j].freq>c[j+1].freq)
    	{
    		struct node temp=c[j];
    		c[j]=c[j+1];
    		c[j+1]=temp;
    	}
	printf("\tTable for Frequency(SORTED):\n\n\tSymbols\t\tFrequency\n");
	for(i=0;i<no;i++)
		printf("\t%c\t\t%d\n",c[i].sign,c[i].freq);
	
	//Creation of tree in bottom up manner
	struct treenode *lef,*rig,*par,*peer,*trpr;
	lef=newtreenode(c[0].freq,c[0].sign);
	rig=newtreenode(c[1].freq,c[1].sign);
	par=newtreenode(c[0].freq+c[1].freq,'$');
	par->left=lef;
	par->right=rig;
	for(i=2;i<no;i++)
	{
		if(c[i].freq>=par->data)
		{
			peer=newtreenode(c[i].freq,c[i].sign);
			trpr=newtreenode(c[i].freq+par->data,'$');
			//printf("c=%d\n",trpr->data);
			trpr->left=par;
			trpr->right=peer;
			par=trpr;
		}
		else
		{
			peer=newtreenode(c[i].freq,c[i].sign);
			trpr=newtreenode(c[i].freq+par->data,'$');
			//printf("c=%d\n",trpr->data);
			trpr->left=peer;
			trpr->right=par;
			par=trpr;
		}
	}
	strcat(struse,"\0");
	printInorder(par);
	printf("\tTable for Codes:\n\n\tSymbols\t\tCodes\n");
	for(i=0;i<ind;i++)
		printf("\t%c\t\t%s\n",traversed[i],table[i]);

	return 0;
}


