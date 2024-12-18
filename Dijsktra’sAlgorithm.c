#include <stdio.h>
#include<string.h>
void path(int prevnode[],int j)
{
    if(prevnode[j]>=0)
    {
        path(prevnode,prevnode[j]);
        printf("%d -> ",(prevnode[j]+1));
    }
}
int main()
{
    int n,i,j,node,count=0,index=0,min;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    int g[n][n],visited[n],sdist[n],prevnode[n];
    memset(visited,0,n*sizeof(visited[0]));
    memset(prevnode,0,n*sizeof(prevnode[0]));
    printf("enter the adjacency matrix of the graph:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
       {
            scanf("%d",&g[i][j]);
        }
    }
    printf("enter the starting vertex/node: ");
    scanf("%d",&node);
    node=node-1;
    for(i=0;i<n;i++)
    {
        if(i==node)
       {
            sdist[node]=0;
            prevnode[node]=-1;
        }
        else
            sdist[i]=999;
    }
   
 while(count<n)
 {
        min=9999;
        for(i=0;i<n;i++)
        {
            if(sdist[i]<min&&visited[i]==0)
            {
                min=sdist[i];
                index=i;
            }
        }
        for(j=0;j<n;j++)
        {
            if(g[index][j]!=0)
            {
                if(sdist[j]>(sdist[index]+g[index][j]))
                {
                    sdist[j]=sdist[index]+g[index][j];
                    prevnode[j]=index;
                }
            }
        }
        visited[index]=1;
        count++;
    }
    
    for(i=0;i<n;i++)
    {
        if(sdist[i]==0)
            continue;
        if(sdist[i]>800)
        {
            printf("No path exists from node %d to node %d\n",(node+1),(i+1));
            continue;
        }
        printf("the shortest distance from node %d to node %d is %d\n",(node+1),(i+1),sdist[i]);
        printf("path: ");
        path(prevnode,i);
        printf("%d\n",(i+1));
    }
    return 0;
}
