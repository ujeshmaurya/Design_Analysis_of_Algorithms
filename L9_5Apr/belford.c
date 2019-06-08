#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
struct Edge
{
    int src, dest, weight;
};
struct g
{
    int V, E;
    struct Edge* edge;
};
struct g* createg(int V, int E)
{
    struct g* g =(struct g*)malloc( sizeof(struct g) );
    g->V=V;
    g->E=E;
    g->edge=(struct Edge*)malloc(g->E*sizeof(struct Edge));
    return g;
}
void Bford(struct g* g, int src)
{
    int V = g->V,E = g->E,i,j;
    int dist[V];
    for (i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for (i=1;i<=V-1;i++)
    {
        for (j=0;j<E;j++)
        {
            int u=g->edge[j].src;
            int v=g->edge[j].dest;
            int weight = g->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    printf("Vertex   Distance from Source\n");
    for (i=0;i<V;++i)
        printf("%d \t\t %d\n", i, dist[i]);
    return;
}
int main()
{
	int v,e,i,src;
	scanf("%d %d %d",&v,&e,&src);
    struct g* g = createg(v,e);
    for(i=0;i<e;i++)
    {
    	int s,d,w;
    	scanf("%d %d %d",&s,&d,&w);
    	g->edge[i].src=s;
		g->edge[i].dest=d;
		g->edge[i].weight=w;
    }
    Bford(g,src);
    return 0;
}
