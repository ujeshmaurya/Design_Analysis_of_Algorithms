#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;

  struct node *left,*right;

} node;
node *srnode=NULL;

typedef struct arr
{
  int src,dest;
} arr;
arr backedge[30],tredge[30];
int l=0,dfslow[20],dfsnum[20],m=0,artpt[20];
int n,t=0,k=0,x=0;



node *nodebanao(int data)
{
   node *nod1;
   nod1=(node*)malloc(sizeof(node));
   nod1->data=data;
   nod1->left=NULL;
   nod1->right=NULL;
}

void createtree(node* p,node* c)
{
   if(p->left==NULL)
         p->left=c;
    else if(p->right==NULL)
   	     p->right=c;


   if(srnode==NULL)
   {
   	  srnode=p;
   }

}
void dodfslow(node *root,node *currentnode,int dfslow[],int dfsnum[])
{   int flag=0,i;
   	if(root==NULL)
   	  return;

   	else
   	{
   	  for(i=0;i<l;i++)
   	   {
   	   	 if(root->data==backedge[i].src)
   	   	  {
   	   	 	 flag=1;
   	   	 	if( dfsnum[currentnode->data-1]>=dfsnum[backedge[i].dest-1] &&dfslow[currentnode->data-1]>dfsnum[backedge[i].dest-1])
   	   	 	   dfslow[currentnode->data-1]=dfsnum[backedge[i].dest-1];
   	   	  }

	    }
    }
	  if(flag==0)
	  {
	  	if(currentnode->left==NULL && currentnode->right==NULL)
	  	  {
	  	  	 dfslow[currentnode->data-1]=dfsnum[currentnode->data-1];
		  }

	  }
	  dodfslow(root->left,currentnode,dfslow,dfsnum);
	  dodfslow(root->right,currentnode,dfslow,dfsnum);
	}




void tree(node *root,int dfslow[],int dfsnum[])
{
	if(root!=NULL)
	{
	  dodfslow(root,root,dfslow,dfsnum);

	 tree(root->left,dfslow,dfsnum);

	 tree(root->right,dfslow,dfsnum);
    }

}

void art(node *root)
{    if(root==NULL)
       return;
       int flag=0;
	  if(root==srnode)
		{
		  if(root->left!=NULL &&root->right!=NULL)
			 {
			   artpt[m++]=root->data;
			 }
	    }
	else
	  {
	    if(root->left!=NULL)
		 {
		 	if(dfsnum[root->data-1]<=dfslow[root->left->data-1])
		 	   {
				 artpt[m++]=root->data;
				 flag=1;
			   }
		 }
	    if(root->right!=NULL &&flag==0)
		  {
		  	if(dfsnum[root->data-1]<=dfslow[root->right->data-1])
		 	   {
				artpt[m++]=root->data;
			   }
		  }
	 }
	art(root->left);
	art(root->right);

}
void print(node *root)
{

	if(root==NULL)
	 return;
	 else
	 {
	 	print(root->left);
		 printf(" %d ",root->data);
		 print(root->right);
	 }
}

void dfs(int data,char color[],int par[],int d[],int f[],int adj[][n],int dfsnum[],node *parent)
 {
     int i,pdata,cdata;
	 	color[data-1]='g';
	 	t+=1;
    	d[data-1]=t;
    for(i=0;i<n;i++)
 	  {  if(adj[data-1][i]==1)
 	  	 {
 	  	   if(color[i]=='w')
			{ node *child=NULL;
			  par[i]=data;
			  tredge[x].src=data;
			  tredge[x++].dest=i+1;

			  child=nodebanao(i+1);
			  dfsnum[i]=k++;

			  createtree(parent,child);
			 dfs(i+1,color,par,d,f,adj,dfsnum,child);
		    }

		   else
		   {
		    pdata=data;
		    cdata=i+1;
		    int flag=0,c;
		   while(1)
		    {   if(par[pdata-1]==0)
		         {
		    	     break;
			     }
		    	else if(par[pdata-1]==cdata)
		    	 {
		    	  for(c=0;c<x;c++)
		    	    {
		    	  	if(tredge[c].dest==data && tredge[c].src==cdata)
		    	     {
					  	flag=1;
					  	break;
				      }
			        }
			      if(flag==0)
		    	   {
				   backedge[l].src=data;
				    backedge[l++].dest=cdata;
		           }
		    	 	break;
				 }
		    	else
		    	{
		    		pdata=par[pdata-1];
				}
			}
	        }
    	}
	}
 	    color[data-1]='b';
    	t+=1;
 	    f[data-1]=t;
 }

int main()
{
	int E,i,j,src,des;
	scanf("%d",&n);
	scanf("%d",&E);
	int adj[n][n];
	int d[n];

    int  par[n],f[n];
    char c[n];

	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	     adj[i][j]=0;
	for(i=0;i<E;i++)
	{
	  scanf("%d%d",&src,&des);
	  adj[src-1][des-1]=1;
	}
	for(i=0;i<n;i++)
	{
	    c[i]='w';
	    d[i]=0;
	    f[i]=0;
		par[i]=0;
    }
	k=1;
	for(i=0;i<n;i++)
	{
		if(c[i]=='w')
		{
		  	node *parent=NULL;
	         parent=nodebanao(i+1);
	         dfsnum[i]=k++;
		 dfs(i+1,c,par,d,f,adj,dfsnum,parent);
	    }
	}
	printf("DFSNUM\tDFSLOW\n");
	 for(i=0;i<n;i++)
	   printf("%d\t%d\n",dfsnum[i],dfslow[i]);
	for(i=0;i<n;i++)
	{
		dfslow[i]=dfsnum[i]+1;
	}
	tree(srnode,dfslow,dfsnum);
	 art(srnode) ;
	 printf("dfs\n");
    printf("DFSNUM\tDFSLOW\n");
	 for(i=0;i<n;i++)
	   printf("%d\t%d\n",dfsnum[i],dfslow[i]);
    printf("Articulation point vertices:\n");
	for(i=0;i<m;i++)
 	 printf("%d ",artpt[i]);
	return 0;
}
