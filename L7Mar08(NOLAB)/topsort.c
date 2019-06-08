#include <stdio.h>
#include <stdlib.h>

struct vertex 
{
   char data;
   int done;
   int par;
};
int vcount=0,graph[100][100];
struct vertex* v[100];


int stack[100]; 
int top = -1; 
void push(int item) 
{ 
   stack[++top] = item; 
} 

int pop() 
{ 
   return stack[top--]; 
} 

int peek() 
{
   return stack[top];
}

int isStackEmpty() 
{
   return top==-1;
}
int back[100][2],inb=0,tre[100][2],intr=0;
int whitevertexdfs(int vertexIndex) 
{
   int i,kl=-1,ts=0;
   for(i=0;i<vcount;i++) 
   {
      if(graph[vertexIndex][i]==1 && v[i]->done==0) 
      {
      	if(ts==0)
      	{
      		ts=1;
         kl=i;
         }
         tre[intr][0]=vertexIndex;
         tre[intr++][1]=i;
         //printf("\nThere is a tree edge from vertex %c to %c\n\n",v[vertexIndex]->data,v[i]->data);
      }
      if(graph[vertexIndex][i]==1 && v[i]->done==1 && i!=v[vertexIndex]->par )
      {
			//printf("\nThere is a back edge from vertex %c to %c\n\n",v[vertexIndex]->data,v[i]->data);*/
			back[inb][0]=vertexIndex;
     		back[inb++][1]=i;
      }
   }
   return kl;
}
char dfstrng[100];
int ind=0,tinda=0,topsort[100];
void dfs() 
{
   int i,time=0;
   v[0]->done = 1;
   //printf("Discovered Vertex: %c \n",v[0]->data);
   //dfstrng[ind++]=v[0]->data;
   //printf("Discovery time of %c vertex= %d\n",v[0]->data,++time);   
   push(0);
  
   while(!isStackEmpty()) 
   {
      int j=whitevertexdfs(peek());
      if(j==-1) 
      {
      dfstrng[ind++]=v[peek()]->data;
	topsort[tinda++]=peek();
	pop();
         //printf("Finish time of %c vertex= %d\n",v[pop()]->data,++time);
      } 
      else 
      {
      	if(v[j]->done==0)
      	//printf("Discovery time of %c vertex= %d\n",v[j]->data,++time);
         v[j]->done=1;
         
         v[j]->par=peek();
         //printf("Parent of %c is %c \n",v[j]->data,v[peek()]->data); 
         push(j);
         //if(whitevertexdfs(peek())==-1&&v[peek()]->done==0)
         	//printf("Discovery time of %c vertex= %d\n",v[peek()]->data,++time);
      }
   } 
   printf("\n\tDepth First Search(final order):\n\t");
   for(i=0;i<ind;i++)
   	printf("%c ",dfstrng[i]); 
	printf("\n");
   for(i=0;i<vcount;i++) 
      v[i]->done=0;        
}
int main() 
{
   int i,j,ver,edge,k,glg=0;
    scanf("%d%d",&ver,&edge);
   for(i=0;i<100;i++) 
   {
      for(j=0;j<100;j++) 
         graph[i][j]=0;
   }
    for(i=0;i<ver;i++)
	{
	    char c[2];
	    scanf("%s",c);
    	struct vertex* p=(struct vertex*)malloc(sizeof(struct vertex));
	    p->data=c[0];  
	    p->done=0;  
	    p->par=0;   
	    v[vcount++]=p;
    }
    for(i=0;i<edge;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        graph[x][y]=1;
        //graph[y][x]=1;
    }
   dfs();
	printf("\n\tTopological Sort: \n\t");
	for(i=tinda-1;i>=0;i--)
		printf("%c ",v[topsort[i]]->data);
	printf("\n");
   return 0;
}

